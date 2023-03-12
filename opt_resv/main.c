#include <stdio.h>
#include <locale.h>

int MAX(int x,int y){ return (x>y) ? x : y; }
int MIN(int x,int y){ return(x<y) ? x : y; }

int main(){

    setlocale(LC_ALL, "");

    // Read values
    int K,n,m,l,X,D;
    printf("%ls",L"Please enter the K,v,μ,λ,X,D : ");
    scanf(" %d,%d,%d,%d,%d,%d", &K , &n , &m , &l , &X , &D );

    int maxDisPoint = 2*X+1;
    int X_K[K+1][maxDisPoint]; // x[k]
    float V_K[K+1][maxDisPoint]; // V[x(k),k]
    int U_K[K][maxDisPoint]; // optimal control rule , R[x(k),k] = u(k)

    // Find discrete valid x(k)
    for (int i=0; i<=K; ++i){
        for (int j=0; j<maxDisPoint; ++j) {
            if(i==0 && j==0) { X_K[i][j]=0; }
            else if (i==0){ X_K[i][j]=-1; }
            else{  X_K[i][j] = j; }
            V_K[i][j] = 0; // initialize V_K
            if(i==K){ V_K[i][j] = n*MIN(j,X)-m*MAX(0,j-X); }
        }
    }

    // Discrete Stochastic Dynamic Programming
    for(int i=K-1;i>=0;i--){
        for(int j=0;j<maxDisPoint;j++){

            if( X_K[i][j]== -1 ){
                V_K[i][j] = -1.0f;
                U_K[i][j] = -1;
            }
            else{

                //Find valid u_k
                int min = MIN(D,l*X-X_K[i][j])+1;
                int u_k[min];
                for (int k = 0; k < min; k++) { u_k[k] = k; }

                //Find the V[x_k](max)
                float v_k = 0,v_k_max=0,v_k_ind=0;
                int u_k_max = 0,x_k=0;
                float prob = 0;

                for (int l = 0; l < min; l++){
                    for(int z=0;z<=(X_K[i][j]/2);z++){
                        for(int d=0;d<=D;d++){
                            prob = (1/(float)(D+1))*(1/(float)((X_K[i][j]/2)==0?1:((X_K[i][j]/2)+1)));
                            x_k = X_K[i][j]-z+MIN(u_k[l],d); // x(k+1)
                            v_k_ind = prob*V_K[i+1][x_k]; // V[x(k+1)]
                            v_k = v_k + v_k_ind;
                        }
                    }
                    if(l==0){
                        v_k_max = v_k;
                        u_k_max = u_k[l];
                    }
                    else if( v_k >= v_k_max ){
                        v_k_max = v_k;
                        u_k_max = u_k[l];
                    }
                    v_k=0;
                }

                U_K[i][j] = u_k_max;
                V_K[i][j] = v_k_max;
            }
        }
    }

    // Print solution
    float total_value=V_K[0][0];
    printf("\nTotal value = %.2f\n\n",total_value);

    for (int i=0; i<K; ++i){
        for (int j=0; j<maxDisPoint; ++j){
            if(V_K[i][j] != -1.0){ printf("At level %d : R[x(%d)=%d,%d]=%d\n",i,i,X_K[i][j],i,U_K[i][j]); }
        }
        printf("\n\n");
    }

    return 0;

}

