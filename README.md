# Black-Scholes Model Implementation

## Overview

This project implements the Black-Scholes model for pricing European options, including calculations for key financial metrics known as the Greeks. It supports both call and put options and provides a practical demonstration of how the model can be used for financial analysis.

## Features

- Calculates option prices for both call and put options.
- Computes Greeks:
  - Delta
  - Gamma
  - Theta
  - Vega
  - Rho
- User-configurable input parameters such as spot price, strike price, volatility, risk-free rate, and time to maturity.
- Outputs results in a user-friendly format.

## Usage

1. Run the script to calculate option prices and Greeks:
   ```bash
   python black_scholes.py
   ```

2. Modify input parameters in the `black_scholes.py` file to match your scenario:
   ```python
   spot_price = 100.0      # Current price of the underlying asset
   strike_price = 110.0    # Strike price of the option
   time_to_maturity = 1.0  # Time to maturity in years
   risk_free_rate = 0.05   # Annual risk-free interest rate
   volatility = 0.2        # Annualized volatility of the underlying asset
   ```

3. The output includes:
   - Option price
   - Values for Delta, Gamma, Theta, Vega, and Rho

## Example Output

```text
Call Option Price: 6.04
Put Option Price: 11.38

Greeks:
Delta: 0.53
Gamma: 0.02
Theta: -0.01
Vega: 0.24
Rho: 0.15
```

## Future Enhancements

- Add support for American options using numerical methods.
- Implement graphical visualization for option prices and Greeks.
- Extend functionality to support portfolio management tools.

## Contributing

Contributions are welcome! Feel free to fork the repository and submit pull requests with detailed descriptions of changes.

## License

This project is licensed under the MIT License.

## Contact

For questions, feedback, or suggestions:

- GitHub: [SMA-Codes](https://github.com/SMA-Codes)

---
Explore the world of financial modeling with this Black-Scholes implementation!

