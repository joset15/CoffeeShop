#include "InterfaceAdapters/BeverageController.hpp"

#include "Application/UseCases/AddNewOrderUC.hpp"
#include "Application/UseCases/CancelOrdersUC.hpp"
#include "Application/UseCases/IAddNewOrderOutputPort.hpp"
#include "Application/UseCases/ICancelOrdersOutputPort.hpp"
#include "Application/UseCases/IListOrdersOutputPort.hpp"
#include "Application/UseCases/ListOrdersUC.hpp"
#include "Application/UseCases/NewOrderReq.hpp"

namespace coffee_shop::interface_adapters
{
void BeverageController::addOrder(
    const application::NewOrderReq &newOrderReq,
    application::IAddNewOrderOutputPort &outputPort) const
{
  application::AddNewOrderUC addNewOrderUC(
      newOrderReq, *m_BeverageBuilderFactory, *m_OrderRepository, outputPort);
  addNewOrderUC.execute();
}

void BeverageController::listOrders(
    application::IListOrdersOutputPort &outputPort) const
{
  application::ListOrdersUC listOrdersUC(*m_OrderRepository, outputPort);
  listOrdersUC.execute();
}

void BeverageController::cancelOrders(
    application::ICancelOrdersOutputPort &outputPort) const
{
  application::CancelOrdersUC cancelOrdersUC(*m_OrderRepository, outputPort);
  cancelOrdersUC.execute();
}
} // namespace coffee_shop::interface_adapters
