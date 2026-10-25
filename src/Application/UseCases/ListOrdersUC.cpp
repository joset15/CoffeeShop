#include "Application/UseCases/ListOrdersUC.hpp"

#include <utility>

ListOrdersUC::ListOrdersUC(std::string name,
                           const IOrderRepository &orderRepository,
                           IListOrdersOutputPort &outputPort)
    : UseCase(std::move(name)), m_OrderRepository(&orderRepository),
      m_OutputPort(&outputPort)
{
}

bool ListOrdersUC::execute()
{
  m_OutputPort->ordersListed(m_OrderRepository->describeOrders());
  return true;
}
