#ifndef BEVERAGE_CONTROLLER_HPP
#define BEVERAGE_CONTROLLER_HPP

#include "Application/UseCases/IAddNewOrderOutputPort.hpp"
#include "Application/UseCases/IListOrdersOutputPort.hpp"
#include "Application/UseCases/IOrderRepository.hpp"
#include "Application/UseCases/NewOrderReq.hpp"

/// @brief Entry point from the UI to the use cases (Clean Architecture
/// controller). Each call gets the output port that receives the result.
class BeverageController
{
public:
  /// @brief Creates a controller that works on the given repository.
  /// @param orderRepository Where the use cases store and read the orders.
  explicit BeverageController(IOrderRepository &orderRepository)
      : m_OrderRepository(&orderRepository)
  {
  }

  /// @brief Runs the "add new order" use case.
  /// @param newOrderReq The requested beverage and ingredients.
  /// @param outputPort Receives whether the order was added.
  void addOrder(const NewOrderReq &newOrderReq,
                IAddNewOrderOutputPort &outputPort) const;

  /// @brief Runs the "list orders" use case.
  /// @param outputPort Receives the list of orders.
  void listOrders(IListOrdersOutputPort &outputPort) const;

private:
  /// @brief Where the orders are stored (not owned, never null: set from a
  /// reference).
  IOrderRepository *m_OrderRepository;
};

#endif // BEVERAGE_CONTROLLER_HPP
