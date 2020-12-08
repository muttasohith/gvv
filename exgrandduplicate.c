#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "coeffs.h"
double variance(char *str);
int  main(void) //main function begins
{

//Uniform random numbers
uniform("uni.dat", 1000000);

//Gaussian random numbers
gaussian("gau.dat", 1000000);

//problem random numbers
problem("pro.dat", 1000000);

//Mean of uniform
printf("uniform");
printf("%lf\n",mean("uni.dat"));#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "coeffs.h"
double variance(char *str);
int  main(void) //main function begins
{

//Uniform random numbers
uniform("uni.dat", 1000000);

//Gaussian random numbers
gaussian("gau.dat", 1000000);

//problem random numbers
problem("pro.dat", 1000000);

//Mean of uniform
printf("uniform");
printf("%lf\n",mean("uni.dat"));
printf("%lf\n",variance("uni.dat"));
printf("gaussian");
printf("%lf\n",mean("gau.dat"));
printf("%lf\n",variance("gau.dat"));

printf("problem");
printf("%lf\n",mean("pro.dat"));
printf("%lf\n",variance("pro.dat"));

return 0;
}


//Defining the function for calculating the mean of random numbers
double variance(char *str)
{
int i=0;
FILE *fp;
double x, temp=0.0;
double m=mean(str);
fp = fopen(str,"r");
//get numbers from file
while(fscanf(fp,"%lf",&x)!=EOF)
{
//Count numbers in file
i=i+1;
//Add all numbers in file
temp = temp+((x-m)*(x-m));
}
fclose(fp);
temp = temp/(i-1);
return temp;

}
//End function for calculating the mean of random numbers

printf("%lf\n",variance("uni.dat"));
printf("gaussian");
printf("%lf\n",mean("gau.dat"));
printf("%lf\n",variance("gau.dat"));

printf("problem");
printf("%lf\n",mean("pro.dat"));
printf("%lf\n",variance("pro.dat"));

return 0;
}


//Defining the function for calculating the mean of random numbers
double variance(char *str)
{
int i=0;
FILE *fp;
double x, temp=0.0;
double m=mean(str);
fp = fopen(str,"r");
//get numbers from file
while(fscanf(fp,"%lf",&x)!=EOF)
{
//Count numbers in file
i=i+1;
//Add all numbers in file
temp = temp+((x-m)*(x-m));
}
fclose(fp);
temp = temp/(i-1);
return temp;

}
//End function for calculating the mean of random numbers
