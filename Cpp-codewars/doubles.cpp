#include <iostream>
#include <string>

std::string doubles(std::string s)
{
    for (size_t i = 0; i < s.size(); i++)
    {
        if ((i++ < s.size()) && (s[i] == s[i++]))
        {
            s.erase(i, i++);
        }
        
    }

    return s;
}

int main(int argc, const char* argv[]) 
{
    std::cout << doubles("zzzzykkkd") << std::endl;
    return 0;
}