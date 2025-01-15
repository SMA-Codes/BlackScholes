#include "BlackScholes.h"
#include <vector>
#include <cmath>
#include <iostream>

auto calculateD1(double underlyingPrice, double strikePrice, double volatility, double riskFreeInterestRate, double dividendYield, double timeToExpiration) -> double {
    double result = ((std::log(underlyingPrice / strikePrice)) + (timeToExpiration * (riskFreeInterestRate - dividendYield + (volatility * volatility) / 2))) / (volatility * std::sqrt(timeToExpiration));
    return result;
}

auto calculateD2(double underlyingPrice, double strikePrice, double volatility, double riskFreeInterestRate, double dividendYield, double timeToExpiration) -> double {
    double result = calculateD1(underlyingPrice, strikePrice, volatility, riskFreeInterestRate, dividendYield, timeToExpiration) - (volatility * std::sqrt(timeToExpiration));
    return result;
}

auto calculateStandardNormalPDF(double x) -> double {
    double result = std::exp(-0.5 * x * x) / std::sqrt(2 * PI);
    return result;
}

auto calculateBoolesRule(double startPoint, double endPoint, int numberOfSubIntervals) -> double {
    double result = 0;
    std::vector<double> X(numberOfSubIntervals + 1, 0.0);
    std::vector<double> Y(numberOfSubIntervals + 1, 0.0);
    double intervalWidth = (endPoint - startPoint) / static_cast<double>(numberOfSubIntervals);

    for (int i = 0; i <= numberOfSubIntervals; i++) {
        X.at(i) = startPoint + i * intervalWidth;
        Y.at(i) = calculateStandardNormalPDF(X.at(i));
    }

    for (int i = 0; i <= ((numberOfSubIntervals - 1) / 4); i++) {
        int index = 4 * i;
        result += (intervalWidth / 45) * (14 * Y[index] + 64 * Y[index + 1] + 24 * Y[index + 2] + 64 * Y[index + 3] + 14 * Y[index + 4]);
    }

    return result;
}

auto calculateNormalDistribution(double x) -> double {
    return calculateBoolesRule(START_INTERVAL, x, NUMBER_OF_SUBINTERVALS);
}

auto calculateNormalDistributionDerivative(double x) -> double {
    double result = std::exp(-0.5 * x * x) / std::sqrt(2 * PI);
    return result;
}

auto calculateCallOptionValue(double underlyingPrice, double strikePrice, double volatility, double riskFreeInterestRate, double dividendYield, double timeToExpiration) -> double {
    double d1 = calculateD1(underlyingPrice, strikePrice, volatility, riskFreeInterestRate, dividendYield, timeToExpiration);
    double d2 = calculateD2(underlyingPrice, strikePrice, volatility, riskFreeInterestRate, dividendYield, timeToExpiration);
    double result = (underlyingPrice * std::exp(-dividendYield * timeToExpiration) * calculateNormalDistribution(d1)) - (strikePrice * std::exp(-riskFreeInterestRate * timeToExpiration) * calculateNormalDistribution(d2));
    return result;
}

auto calculateCallOptionDelta(double underlyingPrice, double strikePrice, double volatility, double riskFreeInterestRate, double dividendYield, double timeToExpiration) -> double {
    double d1 = calculateD1(underlyingPrice, strikePrice, volatility, riskFreeInterestRate, dividendYield, timeToExpiration);
    double result = std::exp(-dividendYield * timeToExpiration) * calculateNormalDistribution(d1);
    return result;
}

auto calculateCallOptionGamma(double underlyingPrice, double strikePrice, double volatility, double riskFreeInterestRate, double dividendYield, double timeToExpiration) -> double {
    double d1 = calculateD1(underlyingPrice, strikePrice, volatility, riskFreeInterestRate, dividendYield, timeToExpiration);
    double result = (std::exp(-dividendYield * timeToExpiration) / (underlyingPrice * volatility * std::sqrt(timeToExpiration))) * calculateNormalDistributionDerivative(d1);
    return result;
}

auto calculateCallOptionTheta(double underlyingPrice, double strikePrice, double volatility, double riskFreeInterestRate, double dividendYield, double timeToExpiration) -> double {
    int numberOfDays = 365;
    double d1 = calculateD1(underlyingPrice, strikePrice, volatility, riskFreeInterestRate, dividendYield, timeToExpiration);
    double d2 = calculateD2(underlyingPrice, strikePrice, volatility, riskFreeInterestRate, dividendYield, timeToExpiration);
    double result = (1.0 / numberOfDays) *
                   ((-underlyingPrice * volatility * std::exp(-dividendYield * timeToExpiration) * calculateNormalDistributionDerivative(d1)) / (2 * std::sqrt(timeToExpiration))
                    - riskFreeInterestRate * strikePrice * std::exp(-riskFreeInterestRate * timeToExpiration) * calculateNormalDistribution(d2)
                    + dividendYield * underlyingPrice * std::exp(-dividendYield * timeToExpiration) * calculateNormalDistribution(d1));
    return result;
}

auto calculateCallOptionVega(double underlyingPrice, double strikePrice, double volatility, double riskFreeInterestRate, double dividendYield, double timeToExpiration) -> double {
    double d1 = calculateD1(underlyingPrice, strikePrice, volatility, riskFreeInterestRate, dividendYield, timeToExpiration);
    double result = underlyingPrice * std::exp(-dividendYield * timeToExpiration) * std::sqrt(timeToExpiration) * calculateNormalDistributionDerivative(d1);
    return result;
}

auto calculateCallOptionRho(double underlyingPrice, double strikePrice, double volatility, double riskFreeInterestRate, double dividendYield, double timeToExpiration) -> double {
    double d2 = calculateD2(underlyingPrice, strikePrice, volatility, riskFreeInterestRate, dividendYield, timeToExpiration);
    double result = strikePrice * timeToExpiration * std::exp(-riskFreeInterestRate * timeToExpiration) * calculateNormalDistribution(d2);
    return result;
}

auto calculatePutOptionValue(double underlyingPrice, double strikePrice, double volatility, double riskFreeInterestRate, double dividendYield, double timeToExpiration) -> double {
    double d1 = calculateD1(underlyingPrice, strikePrice, volatility, riskFreeInterestRate, dividendYield, timeToExpiration);
    double d2 = calculateD2(underlyingPrice, strikePrice, volatility, riskFreeInterestRate, dividendYield, timeToExpiration);
    double result = (strikePrice * std::exp(-riskFreeInterestRate * timeToExpiration) * calculateNormalDistribution(-d2)) - (underlyingPrice * std::exp(-dividendYield * timeToExpiration) * calculateNormalDistribution(-d1));
    return result;
}

auto calculatePutOptionDelta(double underlyingPrice, double strikePrice, double volatility, double riskFreeInterestRate, double dividendYield, double timeToExpiration) -> double {
    double d1 = calculateD1(underlyingPrice, strikePrice, volatility, riskFreeInterestRate, dividendYield, timeToExpiration);
    double result = std::exp(-dividendYield * timeToExpiration) * (calculateNormalDistribution(d1) - 1);
    return result;
}

auto calculatePutOptionGamma(double underlyingPrice, double strikePrice, double volatility, double riskFreeInterestRate, double dividendYield, double timeToExpiration) -> double {
    double d1 = calculateD1(underlyingPrice, strikePrice, volatility, riskFreeInterestRate, dividendYield, timeToExpiration);
    double result = (std::exp(-dividendYield * timeToExpiration) / (underlyingPrice * volatility * std::sqrt(timeToExpiration))) * calculateNormalDistributionDerivative(d1);
    return result;
}

auto calculatePutOptionTheta(double underlyingPrice, double strikePrice, double volatility, double riskFreeInterestRate, double dividendYield, double timeToExpiration) -> double {
    int numberOfDays = 365;
    double d1 = calculateD1(underlyingPrice, strikePrice, volatility, riskFreeInterestRate, dividendYield, timeToExpiration);
    double d2 = calculateD2(underlyingPrice, strikePrice, volatility, riskFreeInterestRate, dividendYield, timeToExpiration);
    double result = (1.0 / numberOfDays) *
                   ((-underlyingPrice * volatility * std::exp(-dividendYield * timeToExpiration) * calculateNormalDistributionDerivative(d1)) / (2 * std::sqrt(timeToExpiration))
                    + riskFreeInterestRate * strikePrice * std::exp(-riskFreeInterestRate * timeToExpiration) * calculateNormalDistribution(-d2)
                    - dividendYield * underlyingPrice * std::exp(-dividendYield * timeToExpiration) * calculateNormalDistribution(-d1));
    return result;
}

auto calculatePutOptionVega(double underlyingPrice, double strikePrice, double volatility, double riskFreeInterestRate, double dividendYield, double timeToExpiration) -> double {
    double d1 = calculateD1(underlyingPrice, strikePrice, volatility, riskFreeInterestRate, dividendYield, timeToExpiration);
    double result = underlyingPrice * std::exp(-dividendYield * timeToExpiration) * std::sqrt(timeToExpiration) * calculateNormalDistributionDerivative(d1);
    return result;
}

auto calculatePutOptionRho(double underlyingPrice, double strikePrice, double volatility, double riskFreeInterestRate, double dividendYield, double timeToExpiration) -> double {
    double d2 = calculateD2(underlyingPrice, strikePrice, volatility, riskFreeInterestRate, dividendYield, timeToExpiration);
    double result = -strikePrice * timeToExpiration * std::exp(-riskFreeInterestRate * timeToExpiration) * calculateNormalDistribution(-d2);
    return result;
}
