#include <iostream>

using namespace std;

bool isLetter(char c)
{
	if (c >= 'a' && c <= 'z')
		return true;
	else if (c >= 'A' && c <= 'Z')
		return true;
	else
		return false;
}

bool checkLength(const char* password)//+ 
{
	size_t size = 0;
	for (int i = 0; password[i] != 0; i++) 
	{
		size++;
	}

	return (size >= 8);
}//1

bool checkDifferentChars(const char* password)//FIXME
{
	size_t size = 0;
	for (int i = 0; password[i] != 0; i++) 
	{
		size++;
	}
	
	int commonChars = 0;
	for (int i = 0; password[i] != 0; i++) 
	{
		for (int j = 0; j < i; j++) 
		{
			if ((j != i) && (password[i] == password[j])) 
			{
				commonChars++;
			}
		}
	}

	return (size - commonChars > 6);
	
}//2

bool checkDigit(const char* password)
{
	bool isThereAnyDigit;
	for (int i = 0; password[i] != 0; i++) 
	{
		if (password[i] >= '0' && password[i] <= '9')
		{
			isThereAnyDigit = true;
			break;
		}
		else 
		{
			isThereAnyDigit = false;
		}
	}

	return isThereAnyDigit;
}//3

bool checkUppercase(const char* password)//+ 
{
	for (int i = 0; password[i] != 0; i++)
	{
		if (password[i] >= 'A' && password[i] <= 'Z') 
		{
			return true;
			break;
		}
		else 
		{
			return false;
		}
	}
}//4

bool checkLowercase(const char* password)//+
{
	bool isThereAnyLowercase;
	for (int i = 0; password[i] != 0; i++)
	{
		if (password[i] >= 'a' && password[i] <= 'z')
		{
			isThereAnyLowercase = true;
			break;
		}
		else
		{
			isThereAnyLowercase = false;
		}
	}

	return isThereAnyLowercase;
}//5

bool CheckAlphanumeric(const char* password)
{
	bool isThereAnyAlphanumeric;
	for (int i = 0; password[i] != 0; i++)
	{		
		if (!isLetter(password[i]) && !(password[i] >= '0' && password[i] <= '9'))
		{
			isThereAnyAlphanumeric = true;
			break;
		}
		else
		{
			isThereAnyAlphanumeric = false;
		}
	}

	return isThereAnyAlphanumeric;
}//6

bool checkpass(const char* password) 
{	
	bool length, differentChars, digit, uppercase, lowercase, alphaNumeric, isPasswordCorrect = true;
	
	for (int i = 0; i < 6; i++) 
	{
		switch (i) 
		{
		case 1: //length
			if (checkLength(password))
			{
				length = true;
			}
			else
			{
				length = false;
				break;
			}
		case 2: //different chars
			if (checkDifferentChars(password)) 
			{
				differentChars = true;
			}
			else 
			{
				differentChars = false;
				break;
			}
		case 3: //digit
			if (checkDigit(password))
			{
				digit = true;
			}
			else
			{
				digit = false;
				break;
			}
		case 4: //uppercase
			if (checkUppercase(password))
			{
				uppercase = true;
			}
			else
			{
				uppercase = false;
				break;
			}
		case 5: //lowercase
			if (checkLowercase(password))
			{
				lowercase = true;
			}
			else
			{
				lowercase = false;
				break;
			}
		case 6: //alphanumeric
			if (CheckAlphanumeric(password))
			{
				alphaNumeric = true;
			}
			else
			{
				alphaNumeric = false;
				break;
			}
		}
	}


	if (!length)
	{
		cout << password << " Password is to short" << endl;
		isPasswordCorrect = false;
	}
	if (!differentChars)
	{
		cout << password << " Password must contain 6 different characters" << endl;
		isPasswordCorrect = false;
	}
	if (!digit)
	{
		cout << password << " Password must contain at least 1 digit" << endl;
		isPasswordCorrect = false;
	}
	if (!uppercase)
	{
		cout << password << " Password must contain at least 1 uppercase character" << endl;
		isPasswordCorrect = false;
	}
	if (!lowercase)
	{
		cout << password << " Password must contain at least 1 lowercase character" << endl;
		isPasswordCorrect = false;
	}
	if (!alphaNumeric)
	{
		cout << password << " Password must contain at least 1 non-alphanumeric character" << endl;
		isPasswordCorrect = false;
	}
	cout << '\n';

	return isPasswordCorrect;
}

int main() 
{	
	const char* passes[] = { "AbcDe93", "A1b:A1b>", "Ab:Acb<", "abc123><", "Zorro@123", nullptr };
	
	for (int i = 0; passes[i] != nullptr; i++) 
	{
		if (checkpass(passes[i]))
			cout << passes[i] << " password is okay\n" << endl;
	}

	return 0;
}