#ifndef IORDERDATASOURCE_HPP
#define IORDERDATASOURCE_HPP

#include "Domain/Beverages/IBeverage.hpp"

namespace coffee_shop::interface_adapters
{
class IOrderDataSource
{
public:
  virtual ~IOrderDataSource() = default;

  virtual bool save(const domain::IBeverage &newBeverage) = 0;
};
} // namespace coffee_shop::interface_adapters

#endif // IORDERDATASOURCE_HPP
