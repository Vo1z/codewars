#include <iostream>

bool is_number_prime(long long num)
{
    for(size_t i = 2; i <= num / 2 ; i++)
    {
        if (num % i == 0)
            return false;
    }

    return true;
}

long long nearest_prime_number(long long n)
{
    long long first_prime_number = n, second_prime_number = n;

    while(!is_number_prime(first_prime_number))
    {
        first_prime_number--;
    }

    while (!is_number_prime(second_prime_number))
    {
        second_prime_number++;
    }

    if((n - first_prime_number) <= (second_prime_number - n))
        return first_prime_number;
    else
        return second_prime_number;
}

int main(int argc, const char** argv)
{
    std::cout << nearest_prime_number(1110) << std::endl;
    return 0;
}