#include "InterfaceAdapters/OrderRepository.hpp"

#include <utility>

bool OrderRepository::save(std::unique_ptr<IBeverage> newBeverage)
{
  m_CurrentOrders.push_back(std::move(newBeverage));

  return true;
}

bool OrderRepository::cancelExistingOrders() { return true; }

bool OrderRepository::storeOrders() { return true; }
