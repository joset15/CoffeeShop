#include "InterfaceAdapters/OrderRepository.hpp"

#include "Domain/Beverages/IBeverage.hpp"

#include <memory>
#include <string>
#include <utility>
#include <vector>

namespace coffee_shop::interface_adapters
{
bool OrderRepository::save(std::unique_ptr<domain::IBeverage> newBeverage)
{
  m_CurrentOrders.push_back(std::move(newBeverage));

  return true;
}

std::vector<std::string> OrderRepository::describeOrders() const
{
  std::vector<std::string> descriptions;
  descriptions.reserve(m_CurrentOrders.size());
  for (const auto &order : m_CurrentOrders)
  {
    descriptions.push_back(order->getDescription());
  }
  return descriptions;
}

bool OrderRepository::cancelExistingOrders() { return true; }

bool OrderRepository::storeOrders() { return true; }
} // namespace coffee_shop::interface_adapters
