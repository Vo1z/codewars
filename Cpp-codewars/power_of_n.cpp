#include <iostream>
#include <vector>
#include <cmath>

int index(const std::vector<int> &vector, int n)
{
    if (n > (int)vector.size() - 1 || n < 0)
        return -1;
    else if (vector[n] == 0)
        return 0;

    int result = std::pow(vector[n], n);

    return result;
}

int main(int n, char** args)
{
    using namespace std;

    std::vector<int> vec{ 6,31};


    cout << index(vec, 3) << endl;
    
    return EXIT_SUCCESS;
}