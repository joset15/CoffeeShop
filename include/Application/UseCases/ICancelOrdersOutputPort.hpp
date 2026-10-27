#ifndef ICANCEL_ORDERS_OUTPUT_PORT_HPP
#define ICANCEL_ORDERS_OUTPUT_PORT_HPP

#include <cstddef>

namespace coffee_shop::application
{
/// @brief Receives the result of the "cancel orders" use case (output port).
class ICancelOrdersOutputPort
{
public:
  /// @brief Allows deleting an implementation through this interface.
  virtual ~ICancelOrdersOutputPort() = default;

  /// @brief The current orders were cancelled.
  /// @param count How many orders were cancelled (0 if there were none).
  virtual void ordersCancelled(std::size_t count) = 0;
};
} // namespace coffee_shop::application

#endif // ICANCEL_ORDERS_OUTPUT_PORT_HPP
