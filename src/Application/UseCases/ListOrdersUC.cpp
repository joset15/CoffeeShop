#include "Application/UseCases/ListOrdersUC.hpp"

namespace coffee_shop::application
{
ListOrdersUC::ListOrdersUC(const IOrderRepository &orderRepository,
                           IListOrdersOutputPort &outputPort)
    : m_OrderRepository(&orderRepository), m_OutputPort(&outputPort)
{
}

bool ListOrdersUC::execute()
{
  m_OutputPort->ordersListed(m_OrderRepository->describeOrders());
  return true;
}
} // namespace coffee_shop::application
