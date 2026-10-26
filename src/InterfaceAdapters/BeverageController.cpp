#include "InterfaceAdapters/BeverageController.hpp"

#include "Application/UseCases/AddNewOrderUC.hpp"
#include "Application/UseCases/ListOrdersUC.hpp"

namespace coffee_shop::interface_adapters
{
void BeverageController::addOrder(
    const application::NewOrderReq &newOrderReq,
    application::IAddNewOrderOutputPort &outputPort) const
{
  application::AddNewOrderUC addNewOrderUC("AddNewOrderUC", newOrderReq,
                                           *m_OrderRepository, outputPort);
  addNewOrderUC.execute();
}

void BeverageController::listOrders(
    application::IListOrdersOutputPort &outputPort) const
{
  application::ListOrdersUC listOrdersUC("ListOrdersUC", *m_OrderRepository,
                                         outputPort);
  listOrdersUC.execute();
}
} // namespace coffee_shop::interface_adapters
