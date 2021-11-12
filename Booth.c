#include <stdio.h>
void transformador_de_binario(int decimal,int v[17]) /*Transformador de binario*/
{
    int i;
    for(i=7; i>=0; i--)
        {
        v[i]=decimal%2;
        decimal=decimal/2;
        }
        for(i=8; i<17; i++)
        {
        v[i]=0;
        }
}


void transformador_de_complementoA1(int q[17]) /*transformador de complementoA1*/
{
    int X;
        for(X=7; X>=0; X--)
        {
            
            if(q[X]==0)
            {
                q[X]=1;
            }
            else
                q[X]=0;
            
        }
}
void transformador_de_complementoA2(int w[17])/*transformador de complementoA2*/
{
    int k=7;
         w[k]=w[k]+1;
        for(; k>=0; k--)
        {
            if(w[k]==2)
            {
                
                w[k-1]=w[k-1]+1;
                w[k]=0;
            }
            
        }
}
void transformador_de_Binario_p(int decimal,int E[17]) /* transformador especifico do multiplicador*/
{
    int i;
    for(i=15; i>=8; i--)
        {
        E[i]=decimal%2;
        decimal=decimal/2;
        }
    E[16]=0;
    for(i=0; i<8; i++)
        {
        E[i]=0;
        }
}
void transformador_de_complementoA1_p(int q[17])/* complemento A1 especifico do multiplicador*/
{
    int X;
        for(X=15; X>=8; X--)
        {
            
            if(q[X]==0)
            {
                q[X]=1;
            }
            else
                q[X]=0;
            
        }
}
void transformador_de_complementoA2_p(int w[17])/* complemento A2 especifico do multiplicador*/
{
    int k=15;
         w[k]=w[k]+1;
        for(; k>=8; k--)
        {
            if(w[k]==2)
            {
                
                w[k-1]=w[k-1]+1;
                w[k]=0;
            }
            
        }
}
void zero_um(int f[17],int g[17]) /* processo do algoritmo pra finais 01*/
{
    for(int o=0; o<17; o++)
    {
        g[o]=f[o]+g[o];
    }
    for(int o=16; o>=0; o--)
    {
        if(g[o]==2)
        {
            g[o-1]=g[o-1]+1;
            g[o]=0;
        }
        if(g[o]==3)
        {
            g[o-1]=g[o-1]+1;
            g[o]=1;
        }
    }
}
void um_zero(int f[17],int g[17])/* processo do algoritmo pra finais 10*/
{
    for(int o=0; o<17; o++)
    {
        g[o]=g[o]+f[o];
    }
    for(int o=16; o>=0; o--)
    {
        if(g[o]==2)
        {
            g[o-1]=g[o-1]+1;
            g[o]=0;
        }
        if(g[o]==3)
        {
            g[o-1]=g[o-1]+1;
            g[o]=1;
        }
    }
}
void passo_pra_direita(int m[17]) /* processo do algoritmo pra passar bit 1 pra direita*/
{
  for(int b=16; b>=1; b--)  
  {
      if(m[b]==1)
      {
          m[b+1]=1;
          m[b]=0;
      }
      
  }
  if(m[0]==1)
  {
      m[1]=1;
  }
}

int main()
{
int a[17];/*Vetor onde ira ficar o multiplicando. x+y+1*/
int s[17];/*Vetor onde ira ficar o negativo do multiplicando. x+y+1*/
int p[17];/*Vetor onde ira ficar o multiplicador. x+y+1*/
    
    a[17]=0;
    s[17]=0;
    p[17]=0;
    
  int multiplicando, multiplicador;
    /* declaracao do usuario sobre o multiplicando e multiplicador */
    printf("Escreva o multiplicando:");
    scanf("%d", &multiplicando);
    printf("escreva o multiplicador:");
    scanf("%d", &multiplicador);
    int variavel;
    variavel=multiplicando;
    
    if(multiplicando<0)
    {multiplicando= multiplicando * -1;}
    
    
    transformador_de_binario(multiplicando, a);
   transformador_de_binario(multiplicando, s);
   /* caso o multiplicando for positivo*/
   if(variavel>0)
   {
                                                        printf("A =");
                                                        for(int X1=0; X1<17; X1++)
                                                            {
                                                            printf("%d", a[X1]);
                                                            }printf("\n");
   transformador_de_complementoA1(s);
    transformador_de_complementoA2(s);
    printf("S =");
                                                        for(int x2=0; x2<17; x2++)
                                                            {
                                                            printf("%d", s[x2]);
                                                            }    printf("\n");
    }
    /*caso o multiplicando for negativo*/
    else
    {
           printf("S =");
                                                        for(int x3=0; x3<17; x3++)
                                                            {
                                                            printf("%d", s[x3]);
                                                            } printf("\n");
    transformador_de_complementoA1(a);
    transformador_de_complementoA2(a);
                                                        printf("A =");
                                                        for(int X4=0; X4<17; X4++)
                                                            {
                                                            printf("%d", a[X4]);
                                                            }printf("\n");
    }
    /*transformando multiplicador em binario*/
    if(multiplicador>=0)
    {
    
    transformador_de_Binario_p(multiplicador, p);
                                                            printf("P =");
                                                        for(int X5=0; X5<17; X5++)
                                                            {
                                                            printf("%d", a[X5]);
                                                            }printf("\n");
    }
    
    /*transformando multiplicador negativo em binario*/
    

    else
    {
    transformador_de_Binario_p(multiplicador, p);
        transformador_de_complementoA1_p(p);
    transformador_de_complementoA2_p(p);
                                                            printf("P =");
                                                        for(int X6=0; X6<17; X6++)
                                                            {
                                                            printf("%d", a[X6]);
                                                            }printf("\n");
    }

for (int l=1; l<9; l++) /* procedimento de booth */
{
    if(p[16]==0 && p[15]==0 || p[16]==1 && p[15]==1)
    {
    passo_pra_direita(p);    
                                                       
                                                        printf("p[%d]=", l);
                                                    for( int r=0; r<17; r++)
                                                    {
                                                        printf("%d", p[r]);
                                                    }
                                                        printf("\n");
                                                      
    }
   else if(p[16]==1 && p[15]==0)
    {
    zero_um(a, p);
                                                       
                                                       printf("p[%d]=", l);
                                                    for( int u1=0; u1<17; u1++)
                                                    {
                                                        
                                                        printf("%d", p[u1]);
                                                    }
                                                        printf("\n");
                                                     
    
    passo_pra_direita(p);                           
                                                        
                                                       printf("p[%d]=", l);
                                                    for( int u=0; u<17; u++)
                                                    {
                                                        
                                                        printf("%d", p[u]);
                                                    }
                                                        printf("\n");
                                                     
    }
   else if(p[16]==0 && p[15]==1)
    {
       um_zero(s, p); 
                                                        
                                                        printf("p[%d]=", l);
                                                    for( int u2=0; u2<17; u2++)
                                                    {
                                                        printf("%d", p[u2]);
                                                    }
                                                        printf("\n");
                                                      
    passo_pra_direita(p); 
                                                        
                                                        printf("p[%d]=", l);
                                                    for( int z=0; z<17; z++)
                                                    {
                                                        printf("%d", p[z]);
                                                    }
                                                        printf("\n");
                                                     
    }
    
    
}

printf("produto final (binario)=");
for( int u4=0; u4<16; u4++)
{
printf("%d", p[u4]);
}


    return 0;
}