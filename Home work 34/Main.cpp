#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

template <typename T>
void show_arr(T arr[], const int length) {
	cout << '[';
	for (int i = 0; i < length; i++)
		cout << arr[i] << ", ";
	cout << "\b\b]\n";
}
template <typename T>
void fill_arr(T arr[], const int length, int begin, int end) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (end - begin) + begin;
}
//Задача 1
template <typename T>
void uniq(T arr1[], T arr2[], const int length1, const int length2) {
	int tmp = 0; 
	for (int i = 0; i < length1; i++)
	{
		bool inBoth = false;
		for (int j = 0; j < length2; j++)
		{
			if (arr1[i] == arr2[j]) {
				inBoth = true;
				break;
			}
		}
		if (!inBoth)
			tmp++;
	}
	for (int i = 0; i < length2; i++)
	{
		bool inBoth = false;
		for (int j = 0; j < length1; j++)
		{
			if (arr2[i] == arr1[j]) {
				inBoth = true;
				break;
			}
		}
		if (!inBoth)
			tmp++;
	}
	
	int length3 = tmp;
	int* arr3 = new int[length3];
	tmp = 0;

	for (int i = 0; i < length1; i++)
	{
		bool inBoth = false;
		for (int j = 0; j < length2; j++)
		{
			if (arr1[i] == arr2[j]) {
				inBoth = true;
				break;
			}
		}
		if (!inBoth)
			arr3[tmp++] = arr1[i];
	}

	for (int i = 0; i < length2; i++)
	{
		bool inBoth = false;
		for (int j = 0; j < length1; j++)
		{
			if (arr2[i] == arr1[j]) {
				inBoth = true;
				break;
			}
		}
		if (!inBoth)
			arr3[tmp++] = arr2[i];
	}
	 show_arr(arr3, length3);
		}
//Задача 2
 double fract(double k) {
	 double p, fraction;
	fraction = modf(k, &p);
	p;
	return fraction;
}
//Задача 3
double double_rand() {
	srand(time(NULL));
	return (rand() % 101) / 100.0;
}

int main() {
	setlocale(LC_ALL, "Russian");
	cout << "Задача 1\n";
	int n;
	const int size1 = 5;
	const int size2 = 5;
	int mass1[size1];
	int mass2[size2];
	fill_arr(mass1, size1,1, 15);
	fill_arr(mass2, size2,1, 17);
	cout << "Массив 1: \n";
	show_arr(mass1, size1);
	cout << "Массив 2: \n";
	show_arr(mass2, size2);
	cout << "Массив с уникальными элементами: \n";
	uniq(mass1, mass2, size1, size2);
	cout << "Задача 2\n";
	double m;
	cout << "Введите вещественное число: \n";
	cin >> m;
	cout << fract(m) << '\n';
	cout << "Задача 3\n";
	cout << "Рандомное число: \n";
	cout << double_rand();

	return 0;
}