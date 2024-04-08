#ifndef ADD_NEW_ORDER_UC_HPP
#define ADD_NEW_ORDER_UC_HPP

#include "UseCase.hpp"

#include "IRequest.hpp"
#include "NewOrderReq.hpp"

//*
#include "../Model/Beverages/BeverageVariety.hpp"
#include "../Model/Beverages/IBeverage.hpp"
#include "../Model/Ingredient/Ingredients.hpp"

#include "IOrderOutput.hpp"
#include "IOrderRepository.hpp"
//*/

class AddNewOrderUC : public UseCase
{
public:
  /*
  AddNewOrderUC(const std::string &name, IOrderOutput &output,
                IOrderRepository &orderRepository)
      : UseCase(name), m_Output(output), m_OrderRepository(orderRepository){};
  */
  AddNewOrderUC(const std::string &name, const NewOrderReq &request)
      : UseCase(name), m_NewOrderReq(request){};

  // TODO bool execute() or execute(Args<T>) ver servidor y virtual execute() en
  // base, no parece que una lista genérica sea lo mejor
  // sino una estructura de datos para request y otra para response https
  //    : //
  //    bocato.medium.com/encapsulating-business-logic-using-the-command-pattern-dee6460cbf20

  // TODO return ErrorCode
  // bool execute(const NewOrderReq &request) override;
  bool execute() override;

private:
  bool addNewOrder(IBeverage::BeverageType beverageType,
                   BeverageVariety beverageVariety,
                   const std::list<Ingredient> &ingredients);

  // IOrderOutput &m_Output;
  // IOrderRepository &m_OrderRepository;

  const NewOrderReq &m_NewOrderReq;
};

#endif // ADD_NEW_ORDER_UC_HPP
