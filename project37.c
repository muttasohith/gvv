#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "coeffs.h"
void matrix(char *str,double**x, int m,int n);
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

matrix("a.dat",omat,2,2);
return 0;
}



//Defining the function for generating uniform random numbers
void matrix(char *str,double**x, int m,int n)
{
int i;
FILE *fp;

fp = fopen(str,"w");
//Generate numbers
for (i = 0; i < m; i++)
{
	for (int j = 0; j < n; j++)
		fprintf(fp,"%lf ",x[i][j]);
	fprintf(fp,"\n");
}
fclose(fp);

}
//End function for generating uniform random numbers
