#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

#include "functions.cpp"

int main() {
	setlocale(LC_ALL, "pl_PL.UTF-8");

	double amount;
	string sourceCurrency, targetCurrency;

	cout << "Podaj kwotę do przeliczenia: ";
	cin >> amount;
	cout << "Podaj walutę zrodlowa (dostępne tylko: EUR, USD, PLN, GBP): ";
	cin >> sourceCurrency;
	cout << "Podaj walutę docelową (dostępne tylko: EUR, USD, PLN, GBP): ";
	cin >> targetCurrency;

	double ConvertedAmount = Convert(amount, sourceCurrency, targetCurrency);
	if (ConvertedAmount !=-1) {
		cout << amount << " " << sourceCurrency << " to " << ConvertedAmount << " " << targetCurrency << endl;
	}
	else {
		cout << "Jedna z podanych walut nie istnieje. Spróbuj ponownie." << endl;
	}
	return 0;
}
