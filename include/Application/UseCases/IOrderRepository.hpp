#ifndef IORDER_REPOSITORY_HPP
#define IORDER_REPOSITORY_HPP

#include "Domain/Beverages/IBeverage.hpp"

#include <memory>
#include <string>
#include <vector>

/// @brief Stores the orders (output port to the storage).
class IOrderRepository
{
public:
  /// @brief Allows deleting an implementation through this interface.
  virtual ~IOrderRepository() = default;

  /// @brief Stores a new order, taking ownership of it.
  /// @param beverage The ordered beverage.
  /// @return True if the order was stored.
  virtual bool save(std::unique_ptr<IBeverage> beverage) = 0;

  /// @brief Describes the stored orders.
  /// @return One description per order, in the order they were saved.
  [[nodiscard]] virtual std::vector<std::string> describeOrders() const = 0;
};

#endif // IORDER_REPOSITORY_HPP
