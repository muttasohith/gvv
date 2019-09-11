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

//slope of OA
double** m = linalg_sub(A,O,2,1);
double  d= linalg_norm(m,2 );

printf("%lf",d);
 

print(A,2,1);
return 0;
}
