#pragma once

constexpr double PI = 3.141592653589793;
constexpr double START_INTERVAL = -10.0;
constexpr int NUMBER_OF_SUBINTERVALS = 240;

auto calculateD1(double underlyingPrice, double strikePrice, double volatility, double riskFreeInterestRate, double dividendYield, double timeToExpiration) -> double;
auto calculateD2(double underlyingPrice, double strikePrice, double volatility, double riskFreeInterestRate, double dividendYield, double timeToExpiration) -> double;
auto calculateStandardNormalPDF(double x) -> double;
auto calculateBoolesRule(double startPoint, double endPoint, int numberOfSubIntervals) -> double;
auto calculateNormalDistribution(double x) -> double;
auto calculateNormalDistributionDerivative(double x) -> double;

auto calculateCallOptionValue(double underlyingPrice, double strikePrice, double volatility, double riskFreeInterestRate, double dividendYield, double timeToExpiration) -> double;
auto calculateCallOptionDelta(double underlyingPrice, double strikePrice, double volatility, double riskFreeInterestRate, double dividendYield, double timeToExpiration) -> double;
auto calculateCallOptionGamma(double underlyingPrice, double strikePrice, double volatility, double riskFreeInterestRate, double dividendYield, double timeToExpiration) -> double;
auto calculateCallOptionTheta(double underlyingPrice, double strikePrice, double volatility, double riskFreeInterestRate, double dividendYield, double timeToExpiration) -> double;
auto calculateCallOptionVega(double underlyingPrice, double strikePrice, double volatility, double riskFreeInterestRate, double dividendYield, double timeToExpiration) -> double;
auto calculateCallOptionRho(double underlyingPrice, double strikePrice, double volatility, double riskFreeInterestRate, double dividendYield, double timeToExpiration) -> double;

auto calculatePutOptionValue(double underlyingPrice, double strikePrice, double volatility, double riskFreeInterestRate, double dividendYield, double timeToExpiration) -> double;
auto calculatePutOptionDelta(double underlyingPrice, double strikePrice, double volatility, double riskFreeInterestRate, double dividendYield, double timeToExpiration) -> double;
auto calculatePutOptionGamma(double underlyingPrice, double strikePrice, double volatility, double riskFreeInterestRate, double dividendYield, double timeToExpiration) -> double;
auto calculatePutOptionTheta(double underlyingPrice, double strikePrice, double volatility, double riskFreeInterestRate, double dividendYield, double timeToExpiration) -> double;
auto calculatePutOptionVega(double underlyingPrice, double strikePrice, double volatility, double riskFreeInterestRate, double dividendYield, double timeToExpiration) -> double;
auto calculatePutOptionRho(double underlyingPrice, double strikePrice, double volatility, double riskFreeInterestRate, double dividendYield, double timeToExpiration) -> double;
