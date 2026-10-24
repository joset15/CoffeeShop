#ifndef ADD_NEW_ORDER_UC_HPP
#define ADD_NEW_ORDER_UC_HPP

#include "UseCase.hpp"

#include "IRequest.hpp"
#include "NewOrderReq.hpp"

//*
#include "Domain/Beverages/BeverageVariety.hpp"
#include "Domain/Beverages/IBeverage.hpp"
#include "Domain/Ingredients/Ingredients.hpp"

#include "IOrderOutput.hpp"
#include "IOrderRepository.hpp"
//*/

class AddNewOrderUC : public UseCase
{
public:
  AddNewOrderUC(const std::string &name, const NewOrderReq &request,
                const IOrderRepository &orderRepository)
      : UseCase(name), m_OrderRepository(orderRepository),
        m_NewOrderReq(request) {};

  // TODO bool execute() or execute(Args<T>) ver servidor y virtual execute() en
  // base, no parece que una lista genérica sea lo mejor
  // sino una estructura de datos para request y otra para response
  // https://bocato.medium.com/encapsulating-business-logic-using-the-command-pattern-dee6460cbf20

  bool execute() override;

private:
  bool addNewOrder(BeverageVariety beverageVariety,
                   const std::list<Ingredient> &ingredients) const;

  // TODO: IUseCaseOutputPort &m_Presenter;
  const IOrderRepository &m_OrderRepository;

  NewOrderReq m_NewOrderReq;
};

#endif // ADD_NEW_ORDER_UC_HPP
