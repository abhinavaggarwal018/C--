// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
#include<queue>
#include<functional>

using namespace std;

int main()
{
	int arr[][5] = { { 0, 1, 1, 0, 1 },
	{ 1, 1, 0, 1, 0 },
	{ 0, 1, 1, 1, 0 },
	{ 1, 1, 1, 1, 0 },
	{ 1, 1, 1, 1, 1 },
	{ 0, 0, 0, 0, 0 } };;
	int n = sizeof(arr[0]) / sizeof(arr[0][0]);


	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (arr[i][j])
			{
				arr[i][j] = min(arr[i - 1][j - 1], min(arr[i - 1][j], arr[i][j - 1])) + 1;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	cin >> arr[0][0];
}

