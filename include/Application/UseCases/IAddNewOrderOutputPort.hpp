#ifndef IADD_NEW_ORDER_OUTPUT_PORT_HPP
#define IADD_NEW_ORDER_OUTPUT_PORT_HPP

#include <string_view>

namespace coffee_shop::application
{
/// @brief Receives the result of the "add new order" use case (output port).
class IAddNewOrderOutputPort
{
public:
  /// @brief Allows deleting an implementation through this interface.
  virtual ~IAddNewOrderOutputPort() = default;

  /// @brief The order was added.
  /// @param description The description of the ordered beverage, e.g.
  /// "CoffeeLatte, Sugar".
  virtual void orderAdded(std::string_view description) = 0;

  /// @brief The order could not be added (unknown variety or an ingredient
  /// that the beverage doesn't accept).
  virtual void orderRejected() = 0;
};
} // namespace coffee_shop::application

#endif // IADD_NEW_ORDER_OUTPUT_PORT_HPP
