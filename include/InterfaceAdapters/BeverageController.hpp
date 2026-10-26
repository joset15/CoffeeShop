#ifndef BEVERAGE_CONTROLLER_HPP
#define BEVERAGE_CONTROLLER_HPP

#include "Domain/BeverageFactories/IBeverageBuilderFactory.hpp"

#include "Application/UseCases/IAddNewOrderOutputPort.hpp"
#include "Application/UseCases/IListOrdersOutputPort.hpp"
#include "Application/UseCases/IOrderRepository.hpp"
#include "Application/UseCases/NewOrderReq.hpp"

namespace coffee_shop::interface_adapters
{
/// @brief Entry point from the UI to the use cases (Clean Architecture
/// controller). Each call gets the output port that receives the result.
class BeverageController
{
public:
  /// @brief Creates a controller that works with the given dependencies.
  /// @param beverageBuilderFactory Creates the builders of new orders.
  /// @param orderRepository Where the use cases store and read the orders.
  BeverageController(domain::IBeverageBuilderFactory &beverageBuilderFactory,
                     application::IOrderRepository &orderRepository)
      : m_BeverageBuilderFactory(&beverageBuilderFactory),
        m_OrderRepository(&orderRepository)
  {
  }

  /// @brief Runs the "add new order" use case.
  /// @param newOrderReq The requested beverage and ingredients.
  /// @param outputPort Receives whether the order was added.
  void addOrder(const application::NewOrderReq &newOrderReq,
                application::IAddNewOrderOutputPort &outputPort) const;

  /// @brief Runs the "list orders" use case.
  /// @param outputPort Receives the list of orders.
  void listOrders(application::IListOrdersOutputPort &outputPort) const;

private:
  /// @brief Creates the builders (not owned, never null: set from a
  /// reference).
  domain::IBeverageBuilderFactory *m_BeverageBuilderFactory;

  /// @brief Where the orders are stored (not owned, never null: set from a
  /// reference).
  application::IOrderRepository *m_OrderRepository;
};
} // namespace coffee_shop::interface_adapters

#endif // BEVERAGE_CONTROLLER_HPP
