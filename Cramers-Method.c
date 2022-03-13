#include <stdio.h>
#include <stdlib.h>
#define N 3
#define Dxyz(X,Y) (*(Dxyz + (X)*N +(Y)))
#define I(X,Y) (*(I + (X)*N + (Y)))
#define A(X,Y) (*(A + (X)*N + (Y)))
#define invA(X,Y) (*(invA + (X)*N +(Y)))
void CramersRulesForInverse(double *A);
void CreateIdentitiyMat(double *I);
void det3x3(double *Dxyz,double *det);
void CreateDxyz_mat(double *A,double *I,int A_colNum,double *Dxyz,int invA_colNum);

int main() {
	double A[N*N];
	CramersRulesForInverse(A);
	return 0;
}

void CramersRulesForInverse(double *A){
	int i,j;
	double det[1],detA;
    double *Dxyz;
    double *I;
    double *invA;
    double dx,dy,dz;
    invA=(double *)malloc(N*N*sizeof(double));
    Dxyz=(double *)malloc(N*N*sizeof(double));
    I=(double *)malloc(N*N*sizeof(double));
	printf("Write the elements of the A matrix: \n");

	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			scanf("%lf",&A(i,j));
		}
	}
	printf("A matrix: \n");
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("%f ",A(i,j));
		}
		printf("\n");
	}
	
	det3x3(A,det);
	printf("Determinant of A matrix: %f\n",det[0]);
	detA=det[0];


	for(i=0;i<N;i++){
		printf("----------------------------------------------------\n");
		printf("Calculation of the column #%d of the inverse A: \n",i+1);

		for(j=0;j<N;j++){
			CreateDxyz_mat(A,I,j,Dxyz,i);
        	for(int k=0;k<N;k++){
        		printf("\n");
        		for(int l=0;l<N;l++){
        			printf("%f ",Dxyz(k,l));
				}
			}
			
			det3x3(Dxyz,det);
			printf("\nDeterminant: %f",det[0]);
			printf("\n");
			
		}
		
	}
	
	printf("Invrerse A: \n");
	for(i=0;i<N;i++){
		
		for(j=0;j<N;j++){
			CreateDxyz_mat(A,I,j,Dxyz,i);
			det3x3(Dxyz,det);
			invA(j,i)=det[0]/detA;
		}
		
	}
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("%f ",invA(i,j));
		}
		printf("\n");
	}
	
    free(Dxyz);
    free(I);
    free(invA);
    
}


void CreateDxyz_mat(double *A,double *I,int A_colNum,double *Dxyz,int invA_colNum){
    double det;
	int i,j;
    CreateIdentitiyMat(I);
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(j==A_colNum)
				Dxyz(i,j)=I(i,invA_colNum);
			else
				Dxyz(i,j)=A(i,j);
		}
	}
   
}

void CreateIdentitiyMat(double *I){

	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(i==j){
				I(i,j)=1;
			}
			else{
				I(i,j)=0;
			}
		}
	}

}

void det3x3(double *Dxyz,double *det){
	det[0] = Dxyz(0,0)*((Dxyz(1,1)*Dxyz(2,2)) - (Dxyz(2,1)*Dxyz(1,2))) - Dxyz(0,1)*(Dxyz(1,0)*Dxyz(2,2) - Dxyz(2,0)*Dxyz(1,2)) + Dxyz(0,2)*(Dxyz(1,0)*Dxyz(2,1) - Dxyz(2,0)*Dxyz(1,1));
}



