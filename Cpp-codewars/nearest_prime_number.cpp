#include <iostream>
#include <thread>

bool is_number_prime(const long long& num)
{   
    for (long long i = 2; i <= num / 2; i++)
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
    bool is_thread_1_working = true, is_thread_2_working = true;

    std::thread t1 (
        [&first_prime_number, &is_thread_1_working]()
        {       
            do
            {
                first_prime_number--;
            }
            while(!is_number_prime(first_prime_number) && is_thread_1_working);
        }
    );
    
    std::thread t2(
        [&second_prime_number, &is_thread_2_working]()
        {
            do
            {
                second_prime_number++;
            }
            while (!is_number_prime(second_prime_number) && is_thread_2_working);
        }
    );

    if (is_number_prime(n))
    {
        is_thread_1_working = false;
        is_thread_2_working = false;
        t1.join();
        t2.join();
        return n;
    }
    else
    {
        t1.join();
        t2.join();

        if((n - first_prime_number) <= (second_prime_number - n))
            return first_prime_number;
        else
            return second_prime_number;
    }
}

int main(int argc, const char** argv)
{
    std::cout << nearest_prime_number(1110) << std::endl;
    return 0;
}