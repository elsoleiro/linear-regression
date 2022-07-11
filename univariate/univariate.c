#include <stdio.h>

struct dataset
{
    float pop;
    float profit;
};

float h(float x, float theta_0, float theta_1)
{
    return theta_0+theta_1*x;
}

float dj_dt0(float x, float y, float theta_0, float theta_1, float alpha)
{
    double val = (1.0/97.0)*alpha*(h(x, theta_0, theta_1)-y);
    return val;
}

float dj_dt1(float x, float y, float theta_0, float theta_1, float alpha)
{
    double val = (1.0/97.0)*alpha*(h(x, theta_0, theta_1)-y)*x;
    return val;
}

int main()
{
    // READ FILE
   FILE* data_set = fopen("data2.txt", "r");
   struct dataset data[97];

   for (int k = 0; k < 97; k++)
   {
       int cap = fscanf(data_set, "%f,%f",
               &data[k].pop, &data[k].profit);

       if (cap != 2)
       {
           printf("number of input items != 2");
           break;
       }
   }
   fclose(data_set);
   /**
   for (int i = 0; i < 97; i++)
   {
       printf("%f,%f\n", data[i].pop, data[i].profit);
   }
   // struct data created and accessible by index
   **/

   float temp0, temp1, theta_0, theta_1;
   temp0 = 0.0;
   temp1 = 0.0;
   theta_0 = 0.0;
   theta_1 = 0.0;

   for (int i = 0; i < 1500; i++)
   {
       for (int k = 0; k < 97; k++)
       {
           temp0 += dj_dt0(data[k].pop, data[k].profit, theta_0, theta_1, 0.01);
           temp1 += dj_dt1(data[k].pop, data[k].profit, theta_0, theta_1, 0.01);
       }
       theta_0 = theta_0 - temp0;
       theta_1 = theta_1 - temp1;
       temp0 = 0.0;
       temp1 = 0.0;
   }

   printf("Theta_0: %f, Theta_1: %f",theta_0, theta_1);

} 
