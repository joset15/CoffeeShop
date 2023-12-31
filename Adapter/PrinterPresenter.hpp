#ifndef PRINTER_PRESENTER_HPP
#define PRINTER_PRESENTER_HPP

#include "..\Model\IBeverage.hpp"
#include "..\UseCase\IOrderOutput.hpp"

#include <iostream>
#include <memory>

class PrinterPresenter : public IOrderOutput
{
public:
  /// \brief
  bool printOutOrders(
    const std::list<std::shared_ptr<IBeverage>>& orderList) override
  {
    for (auto&& beverage : orderList)
    {
      //JT qDebug() << QString::fromStdString(beverage->description());
      std::cout << beverage->description() << std::endl;
    }

    return true;
  }
};

#endif // PRINTER_PRESENTER_HPP
