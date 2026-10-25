#include "InterfaceAdapters/BeverageController.hpp"

#include "Application/UseCases/AddNewOrderUC.hpp"
#include "Application/UseCases/ListOrdersUC.hpp"

void BeverageController::addOrder(const NewOrderReq &newOrderReq,
                                  IAddNewOrderOutputPort &outputPort) const
{
  AddNewOrderUC addNewOrderUC("AddNewOrderUC", newOrderReq, *m_OrderRepository,
                              outputPort);
  addNewOrderUC.execute();
}

void BeverageController::listOrders(IListOrdersOutputPort &outputPort) const
{
  ListOrdersUC listOrdersUC("ListOrdersUC", *m_OrderRepository, outputPort);
  listOrdersUC.execute();
}
