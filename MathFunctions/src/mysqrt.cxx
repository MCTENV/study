#include <cstdio>
// #include "my_math.h"
#include "Table.h"
#include <cmath>

double my_fabs(double num)
{
    return num > 0 ? num : -num;
}

// double my_sqrt(double num)
// {
// #if defined(HAVE_LOG) && defined(HAVE_EXP)
//     fprintf("use sys log and exp\n");
//     double result = exp(log(num) * 0.5);
// #else
//     fprintf(stdout, "use my math\n");
//     if (num<0)
//     {
//         return 0;
//     }

//     double x0, result;
//     x0 = num / 2;
//     result = (x0 + num / x0) / 2;
//     do
//     {
//         x0 = result;
//         result = (x0 + num / x0) / 2;
//     } while (my_fabs(x0 - result) >= EPS);
// #endif
//     return result;
// }
double my_sqrt(double x)
{
    if (x <= 0)
    {
        return 0;
    }

    // use the table to help find an initial value
    double result = x;
    if (x >= 1 && x < 10)
    {
        printf("Use the table to help find an initial value \n");
        result = sqrtTable[static_cast<int>(x)];
    }

    // do ten iterations
    for (int i = 0; i < 10; ++i)
    {
        if (result <= 0)
        {
            result = 0.1;
        }
        double delta = x - (result * result);
        result = result + 0.5 * delta / result;
        printf("Computing sqrt of %lf to be %lf\n", x, result);
    }

    return result;
}