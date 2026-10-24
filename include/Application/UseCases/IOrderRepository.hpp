#ifndef IORDER_REPOSITORY_HPP
#define IORDER_REPOSITORY_HPP

#include "Domain/Beverages/IBeverage.hpp"

#include <memory>

class IOrderRepository
{
public:
  /// @brief The default destructor.
  virtual ~IOrderRepository() = default;

  /// @brief Stores a new order, taking ownership of it.
  /// @param beverage The ordered beverage.
  /// @return True if the order was stored.
  virtual bool save(std::unique_ptr<IBeverage> beverage) = 0;
};

#endif // IORDER_REPOSITORY_HPP
