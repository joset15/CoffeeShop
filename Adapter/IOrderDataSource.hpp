#ifndef IORDERDATASOURCE_HPP
#define IORDERDATASOURCE_HPP

#include "Domain/Beverages/IBeverage.hpp"

class IOrderDataSource
{
public:
  IOrderDataSource(){};

  virtual bool Save(const IBeverage &newBeverage) = 0;
};

#endif // IORDERDATASOURCE_HPP
