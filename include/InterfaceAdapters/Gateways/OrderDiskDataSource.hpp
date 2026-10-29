#ifndef ORDERDISKDATASOURCE_HPP
#define ORDERDISKDATASOURCE_HPP

#include "InterfaceAdapters/IOrderDataSource.hpp"

namespace coffee_shop::interface_adapters::gateways
{
class OrderDiskDataSource : public IOrderDataSource
{
public:
  OrderDiskDataSource();
};
} // namespace coffee_shop::interface_adapters::gateways

#endif // ORDERDISKDATASOURCE_HPP
