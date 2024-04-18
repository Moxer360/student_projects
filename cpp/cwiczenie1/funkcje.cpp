#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "main.cpp"

using namespace std;

int main() {
	double ExchangeRate(const std::string& sourceCurrency, const std::string& targetCurrency) {
		return 3;
	}

	double Convert(double amount, const std::string& sourceCurrency, const std::string& targetCurrency) {
		double rate = ExchangeRate(sourceCurrency, targetCurrency);
		return amount * rate;
	}

	TEST(ExchangeRateTest, SameCurrency) {

	}

	return 0;
}
