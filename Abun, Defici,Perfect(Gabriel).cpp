// This project will ask the user to input a POSITIVE integer.
// If the user enters a POSITIVE integer, the program will classify the number as a PERFECT, ABUNDANT, or DEFICIENT number.
// The program will also classify the number as PRIME or COMPOSITE.
// A number is PERFECT if the sum of each factors, NOT including the number itself is equal to the number.
// A number is DEFICIENT if the sum of each factors, NOT including the number itself is less than the number.
// A number is ABUNDANT if the sum of each factors, NOT including the number itself is greater than the number.
// A number is PRIME if it's only two factors are 1 and the number itself.
// A number is composite if it has more than two factors.
// If the user enters a NEGATIVE integer or zero, the program will ask the user to enter a POSITIVE integer instead.
// if the user enters a number with a decimal, the program will ask the user to enter a WHOLE integer instead.
// If the user enters a negative number with a decimal, the program will ask the user to enter a POSITIVE WHOLE integer instead.
// Perfect, Abundant, or Deficient with Prime and Composite and functions Lab
// Programmer: Gabriel Perez
// Last modified:  11/16/21  11:23 PM

#include <iostream>
using namespace std;

void printBanner();     // function prototype - // function declaration
int getPosInt();
int calcSumOfFactors(int n);   // FORMAL argument list
string classifyPDA(int n);
string classifyPrimeComposite(int n);
bool isPrime(int n);

int main() {

	system("Title All Function Types in One Program by Gabriel Perez");
	system("Color 1F");

	double numberInput;

	printBanner(); 

	while (true) {
		cout << "\n\nI can classify positive integers as Perfect, Abundant, or Deficient.\n"
			<< "I am also able to tell you if it is prime or not.\n"
			<< "\tGive me a positive integer: ";
		numberInput = getPosInt();

		cout << "\nYou gave me " << numberInput << " which is "  << classifyPDA(numberInput) << ' '
			 << classifyPrimeComposite(numberInput) << " number." << endl;

		cout << "\n   ************************************************************************\n";
	}
	return 0;
} 


//  function definitions
void printBanner() {
	cout << "\n"
		<< "\t\t              A program that demonstrates fuctions that            \n"
		<< "\t\t           calculate, classify, test, validate, and print          \n"
		<< "\t\t                         by Gabriel Perez                          \n";
}

int getPosInt() {
	double num;
	cin >> num;
	cin.ignore(100, '\n');

	while ((num <= 0) || (num != static_cast<int>(num))) {
		cout << '\t' << num << " is not a "
			<< (num <= 0 && num == static_cast<int>(num)? "POSITIVE " : "") 
			<< (num <= 0 && num != static_cast<int>(num)? "POSITIVE WHOLE " : "")
			<< (num > 0 && num - static_cast<int>(num) != 0 ? "WHOLE " : "") 
			<< "number. Try again: ";

			cin >> num;
			cin.ignore(100, '\n');
		}
	return static_cast<int>(num);
}

int calcSumOfFactors(int n) {
		int sum = 0;

		for (int i = 1; i < n; i++) {
			if (n % i == 0)
				sum += i;
		}
		return sum;
	}

string classifyPrimeComposite(int n) {
	bool prime = isPrime(n);

	if (n == 1)
		return "NOT PRIME NOR COMPOSITE";
	else
		return (prime ? "PRIME" : "COMPOSITE");
}

string classifyPDA(int n) {
		int total = calcSumOfFactors(n);   // function CALL

		if (total > n)
			return "an ABUNDANT";
		else if (total == n)
			return "a PERFECT";
		else
			return "a DEFICIENT";
	}

bool isPrime(int n) {
	bool prime = true;

	if (n <= 1)
		prime = false;

	for (int i = 2; i <= n / 2; i++) {
		if (n % i == 0) {
			prime = false;
			break;
		}
	}
	return prime;
}
	
			
		