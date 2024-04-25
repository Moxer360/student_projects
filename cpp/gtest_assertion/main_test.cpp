// main_test.cpp
#include <gtest/gtest.h>
#include "functions.cpp"

TEST(ExchangeRateTest, UsdToEur) {
    EXPECT_EQ(0.92, ExchangeRate("usd", "eur"));
}

TEST(ExchangeRateTest, EurToUsd) {
    EXPECT_EQ(1.08, ExchangeRate("eur", "usd"));
}

TEST(ExchangeRateTest, PlnToGbp) {
    EXPECT_EQ(0.20, ExchangeRate("pln", "gbp"));
}

// Testy dla funkcji Convert()
TEST(ConvertTest, UsdToEur) {
    EXPECT_EQ(92, Convert(100, "usd", "eur"));
}

TEST(ConvertTest, EurToUsd) {
    EXPECT_EQ(108, Convert(100, "eur", "usd"));
}

TEST(ConvertTest, PlnToGbp) {
    EXPECT_EQ(10, Convert(50, "pln", "gbp"));
}

TEST(ExchangeRateTest, EdgeCases) {
    EXPECT_EQ(-1, ExchangeRate("usd", "usd")); // Ta sama waluta
    EXPECT_EQ(-1, ExchangeRate("chf", "usd")); // Niepoprawna waluta
}

TEST(ConvertTest, EdgeCases) {
    EXPECT_EQ(-1, Convert(0, "usd", "eur")); // Przeliczanie z zera
    EXPECT_EQ(-1, Convert(100, "usd", "usd")); // Ta sama waluta
    EXPECT_EQ(-1, Convert(50, "chf", "usd")); // Niepoprawna waluta
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

