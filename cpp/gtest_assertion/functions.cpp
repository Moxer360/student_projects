#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

double ExchangeRate(const string& sourceCurrency, const string& targetCurrency) {
	map<pair<string, string>, double> exchangeRates{
		{{"usd", "eur"}, 0.92},
		{{"usd", "gbp"}, 0.79},
		{{"usd", "pln"}, 3.96},
		{{"pln", "usd"}, 0.25},
		{{"pln", "eur"}, 0.23},
		{{"pln", "gbp"}, 0.20},
		{{"eur", "usd"}, 1.08},
		{{"eur", "gbp"}, 0.86},
		{{"eur", "pln"}, 4.29},
		{{"gbp", "usd"}, 1.27},
		{{"gbp", "eur"}, 1.17},
		{{"gbp", "pln"}, 5.01}
	};
	string source = sourceCurrency;
	string target = targetCurrency;
	transform(source.begin(), source.end(), source.begin(), ::tolower);
	transform(target.begin(), target.end(), target.begin(), ::tolower);

	auto FindCurrency = exchangeRates.find({ source, target });
	if (FindCurrency != exchangeRates.end()) {
		return FindCurrency->second;
	}
	else {
		return -1;
	}
}

double Convert(double amount, const string& sourceCurrency, const string& targetCurrency) {
	if (amount == 0) {
		return -1;
	}

	double exchangeRate = ExchangeRate(sourceCurrency, targetCurrency);
	if (exchangeRate != -1) {
		return amount * exchangeRate;
	}
	else {
		return -1;
	}
}
