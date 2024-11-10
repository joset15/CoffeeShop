#ifndef ORDER_REPOSITORY_HPP
#define ORDER_REPOSITORY_HPP

#include "../UseCase/IOrderRepository.hpp"
#include "Domain/Beverages/IBeverage.hpp"
#include "IOrderDataSource.hpp"

#include <list>
#include <memory>

class OrderRepository : public IOrderRepository
{
public:
  /// \brief
  // TODO Refactor datasource
  // OrderRepository(IOrderDataSource &dataSource)
  //    : m_OrderDataSource(dataSource){};

  /// \brief
  bool save(std::shared_ptr<IBeverage> newBeverage) override;

  bool cancelExistingOrders();

  bool storeOrders();

  const std::list<std::shared_ptr<IBeverage>> &getOrders() const
  {
    return m_CurrentOrders;
  }

protected:
  /// \brief
  std::list<std::shared_ptr<IBeverage>> m_CurrentOrders;

  /// \brief
  // TODO Refactor datasource
  // IOrderDataSource &m_OrderDataSource;
};

#endif // ORDER_REPOSITORY_HPP
