#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

char alfabet();
int conditionWin();

int main()
{
	cout << "====================================================" << endl;
	cout << "====================  HANGAROO  ====================" << endl;
	cout << "====================================================" << endl;
	cout << endl;
	alfabet();
	
}

char alfabet()
{
	
	char alphabet;
	for ( alphabet = 'a'; alphabet <= 'z'; ++alphabet )
	{
		cout << "+===+" << endl;
		cout << "| " << alphabet << " |" << endl;
		cout << "+===+" << endl;
		cout << endl;
	}
	
}


