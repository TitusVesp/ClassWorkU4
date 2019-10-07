// ClassWorkU4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

void Enter(int n, double temp, double arr[], double &first, double&second, int&numFirst, int&numSecond, double&min)
{
	cout << "Enter 10 elem.: " << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		if (i == 0) min = temp;
		arr[i] = temp;
		if (i != 0 && min > arr[i]) min = arr[i];
		if (i != 0 && first == 0 && 0 > arr[i]) { numFirst = i; first = arr[i]; }
		else if (i != 0 && second == 0 && 0 > arr[i]) { numSecond = i; second = arr[i]; }
	}
}

void Sum(int n,  int& numFirst, int& numSecond, double &sum, double arr[])
{
	for (int i = 0; i < n; i++)
	{
		if (i > numFirst && i < numSecond) sum += arr[i];
	}
}

void Show(int n, double arr[], double& sum, double& min)
{
	cout << "Until: " << endl;
	for (int i = 0; i < n; i++) cout << arr[i] << " ";

	cout << endl << "After: " << endl;
	for (int i = 0; i < n; i++) { if (abs(arr[i]) < 1) { cout << arr[i] << " "; arr[i] = 0.85672999999999999; } }
	for (int i = 0; i < n; i++) { if (arr[i] != 0.85672999999999999) cout << arr[i] << " "; }
	cout << endl << "Sum of interval: " << sum << endl;
	cout << "Min element: " << min << endl;
}

void main()
{
	const int n = 10;
	double  arr[n], temp = 0.0, first = 0.0, second = 0.0, sum = 0.0, min = 0;
	int numFirst = 0, numSecond = 0;
	
	Enter(n, temp, arr, first, second, numFirst, numSecond, min);

	Sum(n, numFirst, numSecond, sum, arr);

	Show(n, arr, sum, min);

}

