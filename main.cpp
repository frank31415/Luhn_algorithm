#include<iostream>
#include<stdio.h>
#include<string>

using namespace std;

bool checkNumber(const string& s) 
{
	int len = s.length();
	for (int i = 0; i < len; i++) {
		if (s[i] < '0' || s[i] > '9') {
			return false;
		}
	}
	return true;
}


int main()
{
	string ccnumber;
	cout << "Enter 'exit' to exit the program. \n" << endl;

	while (true)
	{
		cout << "Enter a credit card number: \n"; cin >> ccnumber;

		if (ccnumber == "exit") {
			break;
		}
		else if (!checkNumber(ccnumber))
		{
			cout << "Bad input!";
			continue;
		}

		int l = ccnumber.length();
		int partial = 0;

		//Double every 2nd digit and if the result is a 2 digit number sum the digits.
		//Finally calculate the sum of all the sums.
		//48 is the ASCII code for '0'
		for (int i = l - 2; i > 0; i = i - 2)
		{	
			int doubled = (ccnumber[i] - 48) * 2;
			if (doubled > 9) {
				doubled = (doubled / 10) + (doubled % 10);
			}
			partial = partial + doubled;
		}

		//Finally add every odd place digit to the sum
		for (int i = l - 1; i >= 0; i = i - 2)
		{
			partial = partial + (ccnumber[i] - 48);
		}
		//Last step check if sum is a multiple of 10:

		if (partial % 10 == 0) {
			cout << "Valid card number! \n";
		}
		else {
			cout << "Not a valid number! \n";
		}
	}

	return 0;
}
