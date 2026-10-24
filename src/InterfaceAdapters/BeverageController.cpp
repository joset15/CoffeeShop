#include "InterfaceAdapters/BeverageController.hpp"

#include "Application/UseCases/AddNewOrderResponseMessage.hpp"
#include "Application/UseCases/AddNewOrderUC.hpp"

AddNewOrderResponseMessage
BeverageController::execAddOrderUC(const NewOrderReq &newOrderReq) const
{
  AddNewOrderUC addNewOrderUC(std::string("AddNewOrderUC"), newOrderReq,
                              *m_OrderRepository);

  const bool success = addNewOrderUC.execute();
  const std::string_view message =
      success ? OrderAddedMessage : OrderNotAddedMessage;

  return {success, std::string(message)};
}
