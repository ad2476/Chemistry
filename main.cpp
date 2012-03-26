#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	char choice;
	
	cout << "Welcome to Chemistry!" << endl;
	cout << "---------------------" << endl;
	cout << "A) Calculate molar mass\n";
	cout << "B) Calculate percent composition\n";
	cout << "C) Calculate percent yield" << endl;
	
	cout << "> ";
	cin >> choice;
	
	return 0;
}