#include <iostream>
#include <vector>
#include <cmath>

template<typename T, typename FunType>
std::vector<T> filter(const std::vector<T>& v, FunType p) //+
{
	std::vector<T> filteredVector;

	for (int i = 0; i < v.size(); i++) 
	{
		if (p(v.at(i)))
		{
			filteredVector.push_back(v.at(i));
		}
	}

	return filteredVector;
}

template<typename T, typename FunType1, typename FunType2>
std::vector<T> transFilt(std::vector<T>& vec, FunType1 trans, FunType2 pred)//+
{
	std::vector<T> transFiltVector;

	for (int i = 0; i < vec.size(); i++) 
	{
		T transElement = trans(vec.at(i));
		vec[i] = transElement;

		if (pred(transElement)) 
		{
			transFiltVector.push_back(transElement);
		}
	}

	return transFiltVector;
}

template<typename T>
void printVec(const std::vector<T>& v)//+
{
	std::cout << "[ ";

	for (T element : v) 
	{
		std::cout << element << " ";
	}

	std::cout << "]" << std::endl;
}

int main() 
{
	std::vector<int> v{ 1, -3, 4, -2, 6, -8, 5};
	std::vector<double> w{ 1.5,-3.1,4.0,-2.0, 6.3 };
	double mn = -0.5, mx = 0.5;
	
	//first vector
	printVec(v);

	//lamda 1
	printVec(filter(v, [](int num) -> bool {return num % 2 == 0; }));
	
	// lamda 2
	printVec(filter(v, [](int num) -> bool {return num > 0; }));
	
	//second vector of doubles
	printVec(w);

	//lamde 3 and lamda 4	
	printVec(transFilt(w, [](double num) -> double {return std::sin(num); }, [&](double num) -> bool {return (num < mx) && (num > mn); }));

	//modified vector of doubles
	printVec(w);
	
	return 0;
}