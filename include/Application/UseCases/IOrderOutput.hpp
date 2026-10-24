#ifndef IORDEROUTPUT_H
#define IORDEROUTPUT_H

#include "Domain/Beverages/IBeverage.hpp"

#include <list>
#include <memory>

class IOrderOutput
{
public:
  /// @brief The default destructor.
  virtual ~IOrderOutput() = default;

  virtual bool
  printOutOrders(const std::list<std::unique_ptr<IBeverage>> &orderList) = 0;
};

#endif // IORDEROUTPUT_H
