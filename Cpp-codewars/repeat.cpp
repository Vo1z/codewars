#include <iostream>
#include <string>


std::string repeat(std::string s)
{
    char currentChar = s[0];
    std::string result;

    result += currentChar;

    for (size_t i = 0; i < s.size(); i++)
    {
        if (currentChar != s[i])
        {
            result += s[i];
            currentChar = s[i];
        }    
    }

    return result;    
}

int main(int argc, char const *argv[])
{
    std::cout << repeat("abbcccdddda") << std::endl;
    return 0;
}