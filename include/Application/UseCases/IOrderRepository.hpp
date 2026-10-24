#ifndef IORDER_REPOSITORY_HPP
#define IORDER_REPOSITORY_HPP

#include "Domain/Beverages/IBeverage.hpp"

#include <memory>

class IOrderRepository
{
public:
  /// @brief The default destructor.
  virtual ~IOrderRepository() = default;

  /// @brief
  /// @param
  /// @return
  virtual bool save(std::shared_ptr<IBeverage>) = 0;
};

#endif // IORDER_REPOSITORY_HPP
