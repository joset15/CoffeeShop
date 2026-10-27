#ifndef CANCEL_ORDERS_UC_HPP
#define CANCEL_ORDERS_UC_HPP

#include "Application/UseCases/ICancelOrdersOutputPort.hpp"
#include "Application/UseCases/IOrderRepository.hpp"

namespace coffee_shop::application
{
/// @brief Cancels all the current orders and reports how many there were.
class CancelOrdersUC
{
public:
  /// @brief Creates the use case.
  /// @param orderRepository Where the orders are cancelled.
  /// @param outputPort Receives how many orders were cancelled.
  CancelOrdersUC(IOrderRepository &orderRepository,
                 ICancelOrdersOutputPort &outputPort);

  /// @brief Cancels the orders and sends their number to the output port.
  /// @return Always true (cancelling no orders is not an error).
  bool execute();

private:
  /// @brief Where the orders are cancelled (not owned, never null).
  IOrderRepository *m_OrderRepository;

  /// @brief Receives the result (not owned, never null).
  ICancelOrdersOutputPort *m_OutputPort;
};
} // namespace coffee_shop::application

#endif // CANCEL_ORDERS_UC_HPP
