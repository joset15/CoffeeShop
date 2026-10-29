#ifndef LIST_ORDERS_UC_HPP
#define LIST_ORDERS_UC_HPP

#include "Application/UseCases/IListOrdersOutputPort.hpp"
#include "Application/UseCases/IOrderRepository.hpp"

namespace coffee_shop::application
{
/// @brief Sends the current orders to its output port.
class ListOrdersUC
{
public:
  /// @brief Creates the use case.
  /// @param orderRepository Where the orders are read from.
  /// @param outputPort Where the list of orders is sent.
  ListOrdersUC(const IOrderRepository &orderRepository,
               IListOrdersOutputPort &outputPort);

  /// @brief Sends the descriptions of the orders to the output port.
  /// @return Always true.
  bool execute();

private:
  /// @brief Where the orders are read from (not owned, never null).
  const IOrderRepository *m_OrderRepository;

  /// @brief Where the list of orders is sent (not owned, never null).
  IListOrdersOutputPort *m_OutputPort;
};
} // namespace coffee_shop::application

#endif // LIST_ORDERS_UC_HPP
