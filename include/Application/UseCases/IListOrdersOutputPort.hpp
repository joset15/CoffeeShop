#ifndef ILIST_ORDERS_OUTPUT_PORT_HPP
#define ILIST_ORDERS_OUTPUT_PORT_HPP

#include <string>
#include <vector>

namespace coffee_shop::application
{
/// @brief Receives the result of the "list orders" use case (output port).
class IListOrdersOutputPort
{
public:
  /// @brief Allows deleting an implementation through this interface.
  virtual ~IListOrdersOutputPort() = default;

  /// @brief The current orders.
  /// @param descriptions One description per order, in the order they were
  /// added (empty if there are no orders).
  virtual void ordersListed(const std::vector<std::string> &descriptions) = 0;
};
} // namespace coffee_shop::application

#endif // ILIST_ORDERS_OUTPUT_PORT_HPP
