#ifndef PRINTER_PRESENTER_HPP
#define PRINTER_PRESENTER_HPP

#include "..\Model\IBeverage.hpp"
#include "..\UseCase\IOrderOutput.hpp"

#include <QDebug>
#include <memory>

class PrinterPresenter : public IOrderOutput
{
public:
  /// \brief
  bool printOutOrders(
      const std::list<std::shared_ptr<IBeverage>> &orderList) override
  {
    for (auto &&beverage : orderList)
    {
      qDebug() << QString::fromStdString(beverage->description());
    }

    return true;
  }
};

#endif // PRINTER_PRESENTER_HPP
