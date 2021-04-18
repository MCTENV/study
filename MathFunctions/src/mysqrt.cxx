#include "my_math.h"

double my_fabs(double num)
{
    return num > 0 ? num : -num;
}

double my_sqrt(double num)
{
    if (num<0)
    {
        return 0;
    }
    
    double x0, x1;
    x0 = num / 2;
    x1 = (x0 + num / x0) / 2;
    do
    {
        x0 = x1;
        x1 = (x0 + num / x0) / 2;
    } while (my_fabs(x0 - x1) >= EPS);
    return x1;
}