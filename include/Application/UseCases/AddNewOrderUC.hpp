#ifndef ADD_NEW_ORDER_UC_HPP
#define ADD_NEW_ORDER_UC_HPP

#include "UseCase.hpp"

#include "IRequest.hpp"
#include "NewOrderReq.hpp"

#include "Domain/Beverages/BeverageVariety.hpp"
#include "Domain/Beverages/IBeverage.hpp"
#include "Domain/Ingredients/Ingredients.hpp"

#include "IAddNewOrderOutputPort.hpp"
#include "IOrderRepository.hpp"

#include <string>
#include <utility>

/// @brief Builds the requested beverage and saves it as a new order.
class AddNewOrderUC : public UseCase
{
public:
  /// @brief Creates the use case for one request.
  /// @param name The name of the use case.
  /// @param request The beverage and ingredients to order.
  /// @param orderRepository Where the new order is saved.
  /// @param outputPort Receives whether the order was added.
  AddNewOrderUC(std::string name, NewOrderReq request,
                IOrderRepository &orderRepository,
                IAddNewOrderOutputPort &outputPort)
      : UseCase(std::move(name)), m_OrderRepository(&orderRepository),
        m_OutputPort(&outputPort), m_NewOrderReq(std::move(request))
  {
  }

  /// @brief Builds the beverage, saves the order and reports the result to
  /// the output port (orderAdded() or orderRejected()).
  /// @return False if the order was rejected.
  bool execute() override;

private:
  bool addNewOrder(BeverageVariety beverageVariety,
                   const std::list<Ingredient> &ingredients);

  /// @brief Where new orders are saved (not owned, never null: set from a
  /// reference).
  IOrderRepository *m_OrderRepository;

  /// @brief Receives the result (not owned, never null: set from a reference).
  IAddNewOrderOutputPort *m_OutputPort;

  NewOrderReq m_NewOrderReq;
};

#endif // ADD_NEW_ORDER_UC_HPP
