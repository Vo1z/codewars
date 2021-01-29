#include <iostream>
#include <vector>

template<typename T>
static void print(std::vector<T> vec);
std::vector<unsigned long long> partsSum(const std::vector<unsigned long long>& ls);

int main(int n, char* args[])
{
    partsSum({0, 1, 3, 6, 10});

    return EXIT_SUCCESS;
}

std::vector<unsigned long long> partsSum(const std::vector<unsigned long long>& ls)
{
    using std::vector;

    int to_cut = 0;
    vector<unsigned long long>* sums = new vector<unsigned long long>();

    for(size_t i = 0; i < ls.size(); i++)
    {
        sums->push_back(ls.at(i));

        for (size_t j = i + 1; j < ls.size(); j++)
        {
            sums->at(i) += ls.at(j);
        }
    }
    sums->push_back(0);

    print(*sums);

    return *sums;
}

template<typename T>
static void print(std::vector<T> vec)
{
    for(auto i = vec.begin(); i != vec.end(); i++)
        std::cout << *i << ' ';

    std::cout << std::endl;  
} 