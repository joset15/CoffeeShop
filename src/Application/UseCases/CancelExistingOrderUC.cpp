#include "Application/UseCases/CancelExistingOrderUC.hpp"

#include <utility>

CancelExistingOrderUC::CancelExistingOrderUC(std::string name,
                                             IOrderRepository &orderRepository)
    : UseCase(std::move(name)), m_OrderRepository(&orderRepository)
{
}

bool CancelExistingOrderUC::execute()
{
  // TODO: Add a "cancel orders" operation to IOrderRepository and call it
  // through m_OrderRepository.
  return false;
}
