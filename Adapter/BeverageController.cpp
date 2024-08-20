#include "BeverageController.hpp"

#include "../UseCase/AddNewOrderResponseMessage.hpp"
#include "../UseCase/AddNewOrderUC.hpp"

AddNewOrderResponseMessage
BeverageController::execAddOrderUC(const NewOrderReq &newOrderReq) const
{
  AddNewOrderUC addNewOrderUC(std::string("AddNewOrderUC"), newOrderReq,
                              m_OrderRepository);

  bool response = addNewOrderUC.execute();

  std::string stringResponse;
  if (response)
  {
    stringResponse = "Info: Coffee Espresso with Sugar ordered";
  }
  else
  {
    stringResponse = "Error: Couldn't order an Espresso with sugar";
  }

  bool success = true;
  // std::vector<std::string> errors;
  AddNewOrderResponseMessage responseMessage(success, stringResponse);

  return responseMessage;
}
