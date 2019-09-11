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

double** O = createMat(2,1);
 
double** O= 0.5*(linalg_sub(double **A, double **C, int 2, int 1));
