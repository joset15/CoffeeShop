#ifndef ADD_NEW_ORDER_UC_HPP
#define ADD_NEW_ORDER_UC_HPP

#include "Application/UseCases/NewOrderReq.hpp"

#include "Domain/BeverageFactories/IBeverageBuilderFactory.hpp"
#include "Domain/Beverages/BeverageVariety.hpp"
#include "Domain/Beverages/IBeverage.hpp"
#include "Domain/Ingredients/Ingredient.hpp"

#include "Application/UseCases/IAddNewOrderOutputPort.hpp"
#include "Application/UseCases/IOrderRepository.hpp"

#include <utility>
#include <vector>

namespace coffee_shop::application
{
/// @brief Builds the requested beverage and saves it as a new order.
class AddNewOrderUC
{
public:
  /// @brief Creates the use case for one request.
  /// @param request The beverage and ingredients to order.
  /// @param beverageBuilderFactory Creates the builder of the beverage.
  /// @param orderRepository Where the new order is saved.
  /// @param outputPort Receives whether the order was added.
  AddNewOrderUC(NewOrderReq request,
                domain::IBeverageBuilderFactory &beverageBuilderFactory,
                IOrderRepository &orderRepository,
                IAddNewOrderOutputPort &outputPort)
      : m_BeverageBuilderFactory(&beverageBuilderFactory),
        m_OrderRepository(&orderRepository), m_OutputPort(&outputPort),
        m_NewOrderReq(std::move(request))
  {
  }

  /// @brief Builds the beverage, saves the order and reports the result to
  /// the output port (orderAdded() or orderRejected()).
  /// @return False if the order was rejected.
  bool execute();

private:
  bool addNewOrder(domain::BeverageVariety beverageVariety,
                   const std::vector<domain::Ingredient> &ingredients);

  /// @brief Creates the builders (not owned, never null: set from a
  /// reference).
  domain::IBeverageBuilderFactory *m_BeverageBuilderFactory;

  /// @brief Where new orders are saved (not owned, never null: set from a
  /// reference).
  IOrderRepository *m_OrderRepository;

  /// @brief Receives the result (not owned, never null: set from a reference).
  IAddNewOrderOutputPort *m_OutputPort;

  NewOrderReq m_NewOrderReq;
};
} // namespace coffee_shop::application

#endif // ADD_NEW_ORDER_UC_HPP
