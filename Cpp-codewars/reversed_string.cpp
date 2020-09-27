#include <iostream>
#include <string>

std::string reversed_string(std::string s)
{
    std::string result;

    for (size_t i = s.size() - 1; i != -1; i--)
    {
        if (s[i] != ' ')
        {
            result += s[i];
        }
    }

    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            result.insert(i, " ");
        }
    }

    return result;
}

int main(int argc, const char* argv[]) 
{
    std::cout << reversed_string("your code rocks") << std::endl;
    return 0;
}