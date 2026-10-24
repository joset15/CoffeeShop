#ifndef PRINTER_PRESENTER_HPP
#define PRINTER_PRESENTER_HPP

#include "Application/UseCases/IOrderOutput.hpp"
#include "Domain/Beverages/IBeverage.hpp"

#include <iostream>
#include <memory>

class PrinterPresenter : public IOrderOutput
{
public:
  /// \brief
  bool printOutOrders(
      const std::list<std::unique_ptr<IBeverage>> &orderList) override
  {
    for (const auto &beverage : orderList)
    {
      // JT qDebug() << QString::fromStdString(beverage->description());
      std::cout << beverage->getDescription() << std::endl;
    }

    return true;
  }
};

#endif // PRINTER_PRESENTER_HPP
