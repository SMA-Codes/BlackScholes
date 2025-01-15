#include <iostream>
#include "BlackScholes.h"

int main() {
    double underlyingPrice = 100.0;   
    double strikePrice = 100.0;         
    double volatility = 0.20;           
    double riskFreeInterestRate = 0.05; 
    double dividendYield = 0.02;        
    double timeToExpiration = 1.0;      

    double d1 = calculateD1(underlyingPrice, strikePrice, volatility, riskFreeInterestRate, dividendYield, timeToExpiration);
    double d2 = calculateD2(underlyingPrice, strikePrice, volatility, riskFreeInterestRate, dividendYield, timeToExpiration);

    std::cout << "d1: " << d1 << std::endl;
    std::cout << "d2: " << d2 << std::endl;

    double callPrice = calculateCallOptionValue(underlyingPrice, strikePrice, volatility, riskFreeInterestRate, dividendYield, timeToExpiration);
    double callDelta = calculateCallOptionDelta(underlyingPrice, strikePrice, volatility, riskFreeInterestRate, dividendYield, timeToExpiration);
    double callGamma = calculateCallOptionGamma(underlyingPrice, strikePrice, volatility, riskFreeInterestRate, dividendYield, timeToExpiration);
    double callTheta = calculateCallOptionTheta(underlyingPrice, strikePrice, volatility, riskFreeInterestRate, dividendYield, timeToExpiration);
    double callVega = calculateCallOptionVega(underlyingPrice, strikePrice, volatility, riskFreeInterestRate, dividendYield, timeToExpiration);
    double callRho = calculateCallOptionRho(underlyingPrice, strikePrice, volatility, riskFreeInterestRate, dividendYield, timeToExpiration);

    std::cout << "\nCall Option Metrics:\n";
    std::cout << "Price: " << callPrice << std::endl;
    std::cout << "Delta: " << callDelta << std::endl;
    std::cout << "Gamma: " << callGamma << std::endl;
    std::cout << "Theta: " << callTheta << " per year" << std::endl;
    std::cout << "Vega: " << callVega << std::endl;
    std::cout << "Rho: " << callRho << std::endl;

    double putPrice = calculatePutOptionValue(underlyingPrice, strikePrice, volatility, riskFreeInterestRate, dividendYield, timeToExpiration);
    double putDelta = calculatePutOptionDelta(underlyingPrice, strikePrice, volatility, riskFreeInterestRate, dividendYield, timeToExpiration);
    double putGamma = calculatePutOptionGamma(underlyingPrice, strikePrice, volatility, riskFreeInterestRate, dividendYield, timeToExpiration);
    double putTheta = calculatePutOptionTheta(underlyingPrice, strikePrice, volatility, riskFreeInterestRate, dividendYield, timeToExpiration);
    double putVega = calculatePutOptionVega(underlyingPrice, strikePrice, volatility, riskFreeInterestRate, dividendYield, timeToExpiration);
    double putRho = calculatePutOptionRho(underlyingPrice, strikePrice, volatility, riskFreeInterestRate, dividendYield, timeToExpiration);

    std::cout << "\nPut Option Metrics:\n";
    std::cout << "Price: " << putPrice << std::endl;
    std::cout << "Delta: " << putDelta << std::endl;
    std::cout << "Gamma: " << putGamma << std::endl;
    std::cout << "Theta: " << putTheta << " per year" << std::endl;
    std::cout << "Vega: " << putVega << std::endl;
    std::cout << "Rho: " << putRho << std::endl;

    return 0;
}
