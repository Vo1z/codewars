#include <iostream>
#include <vector>

class Kata
{
public:
    void swap(int* n1, int* n2)
    {
        int copy = *n1;
        *n1 = *n2;
        *n2 = copy;
    }

    std::vector<int> selectionSort(std::vector<int> array)  
    {  
        int i, j, min_idx;

        for (i = 0; i < array.size() - 1; i++)  
        {   
            min_idx = i;  
            for (j = i + 1; j < array.size(); j++)
            {  
                if (array[j] < array[min_idx])
                {  
                    min_idx = j;  
                }
            }

            swap(&array[min_idx], &array[i]);  
        }

        return array;  
    }  

    std::vector<int> extract_odd_numbers(std::vector<int> array)
    {
        for(int i = 0; i < array.size(); i++)
        {
            if (array[i] % 2 == 0 || array[i] == 0)
            {
                array.erase(array.begin() + i);
                i--;
            }
        }

        return array;
    }

    std::vector<int> sortArray(std::vector<int> array)
    {
        if (array.size() == 0)
            return array;

        std::vector<int> odd_numbers = selectionSort(extract_odd_numbers(array));
        uint32_t odd_index = 0;

        for(int i = 0; i < array.size(); i++)
        {
            if (array[i] % 2 != 0 && array[i] != 0)
            {
                array[i] = odd_numbers[odd_index];
                odd_index++;
            }
        }
        return array;
    }
};

int main (int n, char** args)
{
    //Assign
    Kata kata;
    std::vector<int> test_array{2, 22, 1, 5, 4, 11, 37, 0};

    test_array = kata.sortArray(test_array);

    //Debug
    for (auto iter = test_array.begin(); iter != test_array.end(); ++iter)
    {
        std::cout << *iter << ' ';
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}