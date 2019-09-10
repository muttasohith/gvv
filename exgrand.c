#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "coeffs.h"
double variance(char*str);
int  main(void) //main function begins
{
 
//Uniform random numbers
uniform("uni.dat", 1000000);

//Gaussian random numbers
gaussian("gau.dat", 1000000);

//Gaussian random numbers
//problem("pro.dat", 1000000);

//Mean of uniform
printf("Uniform : \n");
printf("%lf\n",mean("uni.dat"));
printf("%lf\n",variance("uni.dat"));


//variance of uniform
printf("gaussian:\n");
printf("%lf\n",mean("gau.dat"));
printf("%lf\n",variance("gau.dat"));

//Mean of uniform
//printf("problem : \n");
//printf("%lf\n",mean("pro.dat"));
//printf("%lf\n",variance("pro.dat"));


return 0;
}

//defing variance
double variance(char *str)
{
int i=0;
double avg=mean(str);
FILE *fp;
double x, temp=0.0;

fp = fopen(str,"r");
//get numbers from file
while(fscanf(fp,"%lf",&x)!=EOF)
{
//Count numbers in file
i=i+1;
//Add all numbers in file
temp = temp+(x-avg)*(x-avg);
}
fclose(fp);
temp = temp/(i-1);
return temp;
}
