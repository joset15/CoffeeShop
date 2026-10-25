#ifndef ADD_NEW_ORDER_UC_HPP
#define ADD_NEW_ORDER_UC_HPP

#include "UseCase.hpp"

#include "IRequest.hpp"
#include "NewOrderReq.hpp"

#include "Domain/Beverages/BeverageVariety.hpp"
#include "Domain/Beverages/IBeverage.hpp"
#include "Domain/Ingredients/Ingredients.hpp"

#include "IOrderOutput.hpp"
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
  AddNewOrderUC(std::string name, NewOrderReq request,
                IOrderRepository &orderRepository)
      : UseCase(std::move(name)), m_OrderRepository(&orderRepository),
        m_NewOrderReq(std::move(request)) {};

  /// @brief Builds the beverage and saves the order.
  /// @return False if the beverage can't be built (invalid variety or
  /// ingredient mix).
  // TODO: Consider a request struct in and a response struct out, instead of a
  // bool (see the command pattern:
  // https://bocato.medium.com/encapsulating-business-logic-using-the-command-pattern-dee6460cbf20).
  bool execute() override;

private:
  bool addNewOrder(BeverageVariety beverageVariety,
                   const std::list<Ingredient> &ingredients);

  // TODO: Report the result through an output port (presenter).
  /// @brief Where new orders are saved (not owned, never null: set from a
  /// reference).
  IOrderRepository *m_OrderRepository;

  NewOrderReq m_NewOrderReq;
};

#endif // ADD_NEW_ORDER_UC_HPP
