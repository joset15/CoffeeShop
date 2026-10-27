#include "Application/UseCases/CancelOrdersUC.hpp"

#include "Application/UseCases/ICancelOrdersOutputPort.hpp"
#include "Application/UseCases/IOrderRepository.hpp"

namespace coffee_shop::application
{
CancelOrdersUC::CancelOrdersUC(IOrderRepository &orderRepository,
                               ICancelOrdersOutputPort &outputPort)
    : m_OrderRepository(&orderRepository), m_OutputPort(&outputPort)
{
}

bool CancelOrdersUC::execute()
{
  m_OutputPort->ordersCancelled(m_OrderRepository->cancelOrders());
  return true;
}
} // namespace coffee_shop::application
