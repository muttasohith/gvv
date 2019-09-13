#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "coeffs.h"
int  main(void) 
{
//assaigning the given points
double** A = createMat(2,1); double** C = createMat(2,1);
*A[0] = 1; *A[1] = 3; 
*C[0] = 5; *C[1] = 1; 

//asaigning normal vec to lines
double** n = createMat(2,1);
*n[0] = -2; *n[1] = 1; 

double** O = (linalg_sum(A, C, 2,1));
*O[0] /= 2;
*O[1] /= 2;
//finding k
double k= **matmul(transpose(n, 2,1),O, 1, 2, 1);
//slope of OA
double** s= linalg_sub(A,O,2,1);
//distance between O and A
double  d= linalg_norm(s,2 );
//defing omat
double** omat=createMat(2,2);
omat[0][0] = 0;
omat[0][1] = 1;
omat[1][0] = -1;
omat[1][1] =0;
//finding unit vector
double** m= matmul(omat,n,2,2,1);
double** M=linalg_div(m, 2, 1, linalg_norm(m,2 ));
//finding B and D
double** B= (linalg_sum(O,linalg_scamul(M, 2, 1, d) , 2,1));
double** D= (linalg_sub(O,linalg_scamul(M, 2, 1, d) , 2,1));
//finding given answer
double** X = createMat(1,2);
X[0][0] = 1;X[0][1] = 1;
double a=**matmul(X,B, 1, 2, 1);
double b=**matmul(X,D,1,2,1);
//a*b is my answer
double c= a*b;
//printing all values
printf("B=");
print(B,2,1);
printf("D=");
print(D,2,1);

printf("m=\n");
print(m,2,1);
printf("M=\n");
print(M,2,1);
printf("d=%lf\n",d);
printf("k=%lf\n",k);
printf("A=\n");
print(A,2,1);
printf("a=%lf\n",a);
printf("b=%lf\n",b);
printf("c=%lf\n",c);
//SAVING THE DATA OF MATRICES
saveMat("A.dat",A,2,1);
saveMat("B.dat",B,2,1);
saveMat("C.dat",C,2,1);
saveMat("D.dat",D,2,1);

//DEFINING COORDINATES
double **x_1=linspace(A[0][0],B[0][0],100);
double **x_2=linspace(B[0][0],C[0][0],100);
double **x_3=linspace(C[0][0],D[0][0],100);
double **x_4=linspace(D[0][0],A[0][0],100);
double **y_1=linspace(A[1][0],B[1][0],100);
double **y_2=linspace(B[1][0],C[1][0],100);
double **y_3=linspace(C[1][0],D[1][0],100);
double **y_4=linspace(D[1][0],A[1][0],100);
double **x_5=linspace(A[0][0],C[0][0],100);
double **y_5=linspace(A[1][0],C[1][0],100);
double **x_6=linspace(B[0][0],D[0][0],100);
double **y_6=linspace(B[1][0],D[1][0],100);
//print(theta,10,1);
// saveMat(theta,"theta.dat",100,1);
//double** line_AB= line_gen( A, B,100);
//print(line_AB,2,100);

//SAVING THE DATA
saveMat("X_AB.dat",x_1,1,100);
saveMat("X_BC.dat",x_2,1,100);
saveMat("X_CD.dat",x_3,1,100);
saveMat("X_DA.dat",x_4,1,100);
saveMat("Y_AB.dat",y_1,1,100);
saveMat("Y_BC.dat",y_2,1,100);
saveMat("Y_CD.dat",y_3,1,100);
saveMat("Y_DA.dat",y_4,1,100);
saveMat("X_BD.dat",x_6,1,100);
saveMat("Y_BD.dat",y_6,1,100);
saveMat("X_AC.dat",x_5,1,100);
saveMat("Y_AC.dat",y_5,1,100);
return 0;
}



