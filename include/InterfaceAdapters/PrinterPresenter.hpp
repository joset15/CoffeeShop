#ifndef PRINTER_PRESENTER_HPP
#define PRINTER_PRESENTER_HPP

#include "Application/UseCases/IOrderOutput.hpp"
#include "Domain/Beverages/IBeverage.hpp"

#include <iostream>
#include <memory>

/// @brief Sends the orders to the printer.
class PrinterPresenter : public IOrderOutput
{
public:
  /// @brief Prints the orders, one per line (on the console for now).
  /// @param orderList The orders to print.
  /// @return Always true.
  bool printOutOrders(
      const std::list<std::unique_ptr<IBeverage>> &orderList) override
  {
    for (const auto &beverage : orderList)
    {
      std::cout << beverage->getDescription() << std::endl;
    }

    return true;
  }
};

#endif // PRINTER_PRESENTER_HPP
