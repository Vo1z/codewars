#include <iostream>
#include <thread>

bool is_number_prime(long long num)
{
    for (size_t i = 2; i < num / 2; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }

    return true;
}

long long nearest_prime_number(long long n)
{
    long long first_prime_number = n, second_prime_number = n;
    std::thread t1 (
        [&first_prime_number]()
        {
            while(!is_number_prime(first_prime_number))
            {
                first_prime_number--;
            }  
        }
    );
    
    std::thread t2(
        [&second_prime_number]()
        {
            while (!is_number_prime(second_prime_number))
            {
                second_prime_number++;
            }
        }
    );
    t1.join();
    t2.join();

    if((n - first_prime_number) <= (second_prime_number - n))
        return first_prime_number;
    else
        return second_prime_number;
}

int main(int argc, const char** argv)
{
    std::cout << nearest_prime_number(10000000000) << std::endl;
    return 0;
}