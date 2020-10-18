#include <iostream>
#include <string>

const char ZERO[6][7] = 
{
    " **** ",
    "**  **",
    "**  **",
    "**  **",
    "**  **",
    " **** "
};

const char ONE[6][7] = 
{
    " ***  ",
    "* **  ",
    "  **  ",
    "  **  ",
    "  **  ",
    "******"
};

const char TWO[6][7]
{
    " **** ",
    "**  **",
    "   ** ",
    "  **  ",
    " **   ",
    "******"
};

const char THREE[7][7]
{
    " **** ",
    "**  **",
    "   ** ",
    "   ** ",
    "**  **",
    " **** "
};

const char FOUR[6][7]
{
    "**  **",
    "**  **",
    "**  **",
    " *****",
    "    **",
    "    **"
};

const char FIVE[6][7]
{
    "******",
    "**    ",
    "***** ",
    "    **",
    "    **",
    "***** "
};

const char SIX[6][7]
{
    "   ** ",
    "  **  ",
    " **** ",
    "**  **",
    "**  **",
    " **** "
};

const char SEVEN[6][7]
{
    "******",
    "**  **",
    "   ** ",
    "  **  ",
    " **   ",
    " **   "
};

const char EIGHT[6][7]
{
    " **** ",
    "**  **",
    " **** ",
    " **** ",
    "**  **",
    " **** "
};

const char NINE[6][7]
{
    " **** ",
    "**  **",
    "**  **",
    " **** ",
    "  **  ",
    " **   "
};

void debug(const char* char_array[])
{
    using namespace std;

    for(const char* a : char_array)
    {
        std::cout << a << std::endl;
    }
}

void create_borders(char** str, const char sign, const size_t& y_size, const size_t& x_size)
{
    for(size_t y = 0; y < y_size; y++)
    {
        for(size_t x = 0; x < x_size; x++)
        {
            if(y == 0 || y == y_size - 1 || x == 0 || x == x_size - 1)
            {
                str[y][x] = sign;
            }        
        }
    }
}

void get_tabled_number(const unsigned num, const char ch)
{
    // char result[10][41]

    // create_borders(result, '$', 10, 41);
    // debug(result, 10, 41); 
}

int main(int argc, char const** argv)
{
    using namespace std;
    // cout << sizeof(NINE) << endl;

    debug(NINE);

    return 0;
}