#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double left_rectangular_metod(double a,double b, unsigned int n);
double right_rectangular_metod(double a,double b, unsigned int n);
double trap_metod(double a,double b, unsigned int n);
double Simps_metod(double a,double b, unsigned int n);
double integral( double x );
//----------------------------------
int main()
{
    double left_boundary_a=0, right_boundary_b=0, I1=0, I2=0, integral_s, max_pohibka = 0.00001;;
    int intervals, var, i,  pohibka = 0;;
//----------------------------------
    printf("Enter the left boundary X1:");
    scanf("%lf", &left_boundary_a);
    printf("Enter the right boundary X2:");
    scanf("%lf", &right_boundary_b);
    while(intervals <= 0)
    {
        printf("Enter the number of partition intervals (N>0):");
        scanf("%u", &intervals);
    }
    system("CLS");
    printf("Choose the method of calculating:\n");
    printf("1 - By Left Rectangles;\n");
    printf("2 - By Right Rectangles;\n");
    printf("3 - By Trapeze method;\n");
    printf("4 - By integral_Simps's method (parabola method);\n");
    while(1)
    {
        printf("Metod:");
        scanf("%u", &var);
        if (var!=1 && var!=2 &&var!=3 && var!=4 )
        {
            printf("\nError, please try again:\n");
        }
        else
        {
            break;
        }
    }
    system("cls");
    switch(var)
    {
        case 1:
            do{
                pohibka += 2;
                I1 = left_rectangular_metod(left_boundary_a, right_boundary_b, pohibka);
                I2 = left_rectangular_metod(left_boundary_a,right_boundary_b, pohibka + 2);
            }while (fabs(I2 - I1) > max_pohibka);
            integral_s = left_rectangular_metod(left_boundary_a,right_boundary_b, intervals);
            printf("*******Left Rectangles method*******\n");
            break;
        case 2:
            do{
                pohibka += 2;
                I1 = right_rectangular_metod(left_boundary_a, right_boundary_b, pohibka);
                I2 = right_rectangular_metod(left_boundary_a,right_boundary_b, pohibka + 2);
            }while (fabs(I2 - I1) > max_pohibka);
            integral_s = right_rectangular_metod(left_boundary_a,right_boundary_b, intervals);
            printf("*******Right Rectangles method*******\n");
            break;
        case 3:
            do{
                pohibka += 2;
                I1 = trap_metod(left_boundary_a, right_boundary_b, pohibka);
                I2 = trap_metod(left_boundary_a,right_boundary_b, pohibka + 2);
            }while (fabs(I2 - I1) > max_pohibka);
            integral_s = trap_metod(left_boundary_a,right_boundary_b, intervals);
            printf("*******Trapezia method*******\n");
            break;
        case 4:
            do{
                pohibka += 2;
                I1 = Simps_metod(left_boundary_a, right_boundary_b, pohibka);
                I2 = Simps_metod(left_boundary_a,right_boundary_b, pohibka + 2);
            }while (fabs(I2 - I1) > max_pohibka);
            integral_s = Simps_metod(left_boundary_a,right_boundary_b, intervals);
            printf("*******Simps's method*******\n");
    }
    printf("a = %.2lf \nb = %.2lf \nIntegral = %.8lf \nN = %d \ni1 = %.8lf \npohibka = %d",left_boundary_a, right_boundary_b, integral_s, intervals, I1, pohibka);
    printf("\n*****************************\n");
    return 0;
}
//----------------------------------
double left_rectangular_metod(double a,double b, unsigned int n)
{
    double s=0, x=0, h;
    unsigned int i;
    h = ( b - a ) / n;
    x = a;
    for (i = 0; i <=(n-1); i++ )
    {
        s += integral(x);
        x += h;
    }
    return s*h;
}
//----------------------------------------------------------------
double right_rectangular_metod(double a,double b, unsigned int n)
{
    double s=0, x=0, h;
    unsigned int i;
    h = ( b - a ) / n;
    x = a+h;
    for (i = 0; i <= n; i++ )
    {
        s += integral(x);
        x += h;
    }
    return s*h;
}
//----------------------------------------------------------------
double trap_metod(double a,double b, unsigned int n)
{
    double s=0, x1=0,x2=0, h;
    unsigned int i;
    h = ( b - a ) / n;
    x1=0;
    x2 = a;
    for (i = 0; i <= (n); i++ )
    {
        s += (integral(x1)+integral(x2))/2;
        x1=x2;
        x2 += h;
    }
    s += (integral(x1)+integral(x2))/2;
    return s*h;
}
//----------------------------------------------------------------
double Simps_metod(double a,double b, unsigned int n)
{
    double s=0, x=0, h,s1=0,s2=0;
    unsigned int i;
    int k=1;
    h = ( b - a ) / n;
    x=a;
    s=integral(x);
    for (i = 0; i < (n); i++ )
    {
        if(i%2==1)
        {
            s += 4*integral(x);
        }
        else
        {
            s += 2*integral(x);
        }
        x += h;
    }
    s+=integral(x);
    return(h*s/3);
}
//----------------------------------------------------------------
double integral( double x )
{
    return pow(x,2)*exp(2-x);
}
