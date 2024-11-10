#ifndef IORDEROUTPUT_H
#define IORDEROUTPUT_H

#include "Domain/Beverages/IBeverage.hpp"

#include <list>
#include <memory>

class IOrderOutput
{
public:
  virtual bool
  printOutOrders(const std::list<std::shared_ptr<IBeverage>> &orderList) = 0;
};

#endif // IORDEROUTPUT_H
