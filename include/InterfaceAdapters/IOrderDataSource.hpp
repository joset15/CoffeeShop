#ifndef IORDERDATASOURCE_HPP
#define IORDERDATASOURCE_HPP

#include "Domain/Beverages/IBeverage.hpp"

class IOrderDataSource
{
public:
  virtual ~IOrderDataSource() = default;

  virtual bool save(const IBeverage &newBeverage) = 0;
};

#endif // IORDERDATASOURCE_HPP
