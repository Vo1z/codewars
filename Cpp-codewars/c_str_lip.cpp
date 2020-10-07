#include <iostream>

using namespace std;

size_t length(const char* cstr) //done
{
    size_t size = 0;

    for (int i = 0; cstr[i] != 0; i++)
    {
        size++;
    }

    return size;
}

bool isLetter(char c) //done
{
    if (c >= 'a' && c <= 'z')
        return true;
    else if (c >= 'A' && c <= 'Z')
        return true;
    else
        return false;
}

 char* reverse(char* cstr)
 {
   size_t len = length(cstr) - 1;

   if (len % 2 == 1)
     len--;

   for (int i = 0; i < len / 2; i++)
   {
     char tmp = cstr[i];
     cstr[i] = cstr[len - i];
     cstr[len - i] = tmp;
   }

   return cstr;
 }

size_t words(const char* cstr) //rewr
{
    size_t numberOfWords = 0;
    int letterCombo = 0;

    for (int i = 0; cstr[i] != 0; i++)
    {
        if (isLetter(cstr[i]))
        {
            letterCombo++;
        }
        else if (letterCombo > 0 && !isLetter(cstr[i]))
        {
            numberOfWords++;
            letterCombo = 0;
        }
    }

    return numberOfWords;
}

size_t words2(const char* cstr) 
{
    int wc = 0;
    
    uint32_t lc = 0;
    
    for (int i = 0; cstr[i] != 0; i++)
    {
        if (isLetter(cstr[i]))
        {
            lc++;
        }
        else if (!isLetter(cstr[i])) 
        {
            if (lc > 2) wc++;
            lc = 0;
        }
    }
    
    return wc;
}

char* concat(char* str1, const char* str2) 
{
    int i = 0;

    while (str1[i] != 0) 
    {
        i++;
    }

    int j = 0;

    while (str2[j] != 0)
    {
        str1[i] = str2[j];
        j++;
        i++;
    }

    str1[i] = 0;

    return str1;
}

int main()
{
    char s1[] = "Alice in Wonderland";
    cout << "reverse: " << reverse(s1) << endl;
    cout << "length: " << length(s1) << endl;
    char s2[] = "... for (int i = 0; i < n; ++i){...} ...";
    cout << "words : " << words(s2) << endl;
    cout << "words2 : " << words2(s2) << endl;
    char s3[100] = "Hello";
    cout << "concat : " << concat(concat(s3, ", world"), "!") << endl;

    return 0;
}


