#ifndef IORDEROUTPUT_H
#define IORDEROUTPUT_H

#include "..\Model\IBeverage.hpp"

#include <memory>
class IOrderOutput
{
public:
  virtual bool
  printOutOrders(const std::list<std::shared_ptr<IBeverage>> &orderList) = 0;
};

#endif // IORDEROUTPUT_H
