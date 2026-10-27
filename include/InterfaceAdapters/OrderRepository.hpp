#ifndef ORDER_REPOSITORY_HPP
#define ORDER_REPOSITORY_HPP

#include "Domain/Beverages/IBeverage.hpp"

#include "Application/UseCases/IOrderRepository.hpp"

#include "InterfaceAdapters/IOrderDataSource.hpp"

#include <cstddef>
#include <memory>
#include <string>
#include <vector>

namespace coffee_shop::interface_adapters
{
/// @brief Keeps the orders in memory.
class OrderRepository : public application::IOrderRepository
{
public:
  /// @brief The default destructor.
  ~OrderRepository() override = default;

  /// @brief Stores a new order, taking ownership of it.
  /// @param newBeverage The ordered beverage.
  /// @return Always true.
  bool save(std::unique_ptr<domain::IBeverage> newBeverage) override;

  /// @brief Describes the stored orders.
  /// @return One description per order, in the order they were saved.
  [[nodiscard]] std::vector<std::string> describeOrders() const override;

  /// @brief Cancels (removes) all the stored orders.
  /// @return How many orders were cancelled (0 if there were none).
  std::size_t cancelOrders() override;

  /// @brief Not implemented yet: always returns true.
  static bool storeOrders();

private:
  /// @brief The repository owns the stored orders.
  std::vector<std::unique_ptr<domain::IBeverage>> m_CurrentOrders;

  // TODO: Persist the orders through an injected IOrderDataSource.
};
} // namespace coffee_shop::interface_adapters

#endif // ORDER_REPOSITORY_HPP
