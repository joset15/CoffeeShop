#include "OrderRepository.hpp"

bool OrderRepository::save(std::shared_ptr<IBeverage> newBeverage)
{
  m_CurrentOrders.push_back(std::move(newBeverage));

  // TODO Refactor datasource
  // m_OrderDataSource.add(newBeverage);

  return true;
}

bool OrderRepository::cancelExistingOrders() { return true; }

bool OrderRepository::storeOrders() { return true; }
