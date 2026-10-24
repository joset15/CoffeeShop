#ifndef ORDER_REPOSITORY_HPP
#define ORDER_REPOSITORY_HPP

#include "Application/UseCases/IOrderRepository.hpp"
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

  /// @brief The default destructor.
  ~OrderRepository() override = default;

  /// @brief
  bool save(std::unique_ptr<IBeverage> newBeverage) override;

  static bool cancelExistingOrders();

  static bool storeOrders();

  const std::list<std::unique_ptr<IBeverage>> &getOrders() const
  {
    return m_CurrentOrders;
  }

protected:
  /// @brief The repository owns the stored orders.
  std::list<std::unique_ptr<IBeverage>> m_CurrentOrders;

  /// \brief
  // TODO Refactor datasource
  // IOrderDataSource &m_OrderDataSource;
};

#endif // ORDER_REPOSITORY_HPP
