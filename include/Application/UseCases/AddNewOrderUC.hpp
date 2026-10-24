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

#include <string>
#include <utility>

class AddNewOrderUC : public UseCase
{
public:
  AddNewOrderUC(std::string name, NewOrderReq request,
                IOrderRepository &orderRepository)
      : UseCase(std::move(name)), m_OrderRepository(&orderRepository),
        m_NewOrderReq(std::move(request)) {};

  // TODO bool execute() or execute(Args<T>) ver servidor y virtual execute() en
  // base, no parece que una lista genérica sea lo mejor
  // sino una estructura de datos para request y otra para response
  // https://bocato.medium.com/encapsulating-business-logic-using-the-command-pattern-dee6460cbf20

  bool execute() override;

private:
  bool addNewOrder(BeverageVariety beverageVariety,
                   const std::list<Ingredient> &ingredients);

  // TODO: IUseCaseOutputPort &m_Presenter;
  /// @brief Where new orders are saved (not owned, never null: set from a
  /// reference).
  IOrderRepository *m_OrderRepository;

  NewOrderReq m_NewOrderReq;
};

#endif // ADD_NEW_ORDER_UC_HPP
