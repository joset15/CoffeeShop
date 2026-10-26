#ifndef LIST_ORDERS_UC_HPP
#define LIST_ORDERS_UC_HPP

#include "IListOrdersOutputPort.hpp"
#include "IOrderRepository.hpp"
#include "UseCase.hpp"

#include <string>

namespace coffee_shop::application
{
/// @brief Sends the current orders to its output port.
class ListOrdersUC : public UseCase
{
public:
  /// @brief Creates the use case.
  /// @param name The name of the use case.
  /// @param orderRepository Where the orders are read from.
  /// @param outputPort Where the list of orders is sent.
  ListOrdersUC(std::string name, const IOrderRepository &orderRepository,
               IListOrdersOutputPort &outputPort);

  /// @brief Sends the descriptions of the orders to the output port.
  /// @return Always true.
  bool execute() override;

private:
  /// @brief Where the orders are read from (not owned, never null).
  const IOrderRepository *m_OrderRepository;

  /// @brief Where the list of orders is sent (not owned, never null).
  IListOrdersOutputPort *m_OutputPort;
};
} // namespace coffee_shop::application

#endif // LIST_ORDERS_UC_HPP
