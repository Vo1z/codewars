#include<iostream>
#include<cmath>

static inline int factorial(int n);
static inline int find_integer_part(double n, double divisor);
static double calculate_sin_of_x(double x);

int main()
{
    using namespace std;
    double x = 0;

    printf("Enter X for sin(X): ");
    cin >> x;
    
    printf("Result: %f\n", calculate_sin_of_x(x));
    printf("Terminating...");
}

static inline int factorial(int n)
{
    return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

static inline int find_integer_part(double n, double divisor)
{
    return (int)(n / divisor);
}

double calculate_sin_of_x(double x)
{
    int series_num = 6, integerPart = 0;
    double series_result = 0, sign = -1;
    
    x = x - (M_PI * (integerPart = find_integer_part(x, M_PI)));

    for(size_t i = 3; series_num > 0; i += 2)
    {
        double element_fraction = pow(x, i) / factorial(i);
        series_result += element_fraction * sign;
        
        sign = -sign;
        series_num--;
    }

    x = abs(integerPart % 2) == 1? -(x + series_result) : x + series_result;
    return x;
}