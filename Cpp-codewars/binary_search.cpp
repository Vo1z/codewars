#include <iostream>

int binary_search(int arr[], int l, int r, const int x);

int main(int n, char* args[])
{
    using namespace std;

    int array[]{1,3,6,8,22,24,55};

    cout << binary_search(array, 0, 6, 24) << endl;

    return EXIT_SUCCESS;
}

int binary_search(int arr[], int l, int r, int x)
{
    int m;

    while (l <= r)
    {
        m = l + (r - l) / 2;

        if (arr[m] == x)
            return m;

        else if (arr[m] < x)
            l = m + 1;
        
        else if (arr[m] > x)
            r = m - 1;
            
    }

    return -1;
}