#ifndef BEVERAGE_CONTROLLER_HPP
#define BEVERAGE_CONTROLLER_HPP

// #include "UseCase/IUseCaseOutputPort.hpp"

#include "Application/UseCases/NewOrderReq.hpp"

/*
#include "Model/Beverages/BeverageVariety.hpp"
#include "Model/Beverages/Coffee.hpp"
#include "Model/Beverages/IBeverage.hpp"

#include "Model/Ingredient/Ingredients.hpp"
*/

#include "Application/UseCases/IOrderRepository.hpp"

#include "Domain/BeverageFactories/BeverageFactory.hpp"
#include "Domain/BeverageFactories/IngredientFactory.hpp"

#include "Application/UseCases/AddNewOrderResponseMessage.hpp"
#include "Domain/BeverageBuilder/BeverageBuilder.hpp"

#include <string_view>

class BeverageController
{
public:
  /// @brief Message returned when an order is added.
  static constexpr std::string_view OrderAddedMessage = "Info: Order added.";

  /// @brief Message returned when an order cannot be added.
  static constexpr std::string_view OrderNotAddedMessage =
      "Error: Order could not be added.";

  explicit BeverageController(IOrderRepository &orderRepository)
      : m_OrderRepository(&orderRepository) {};

  /// @brief Runs the "add new order" use case.
  /// @param newOrderReq The requested beverage and ingredients.
  /// @return Whether the order was added, and a message for the user.
  [[nodiscard]] AddNewOrderResponseMessage
  execAddOrderUC(const NewOrderReq &newOrderReq) const;

  // void execListOrderUC(const ListOrderReq &listOrderReq) {}
  void execListOrderUC(const IRequest &listOrderReq) { (void)listOrderReq; }

private:
  /// @brief Where new orders are saved (not owned, never null: set from a
  /// reference).
  IOrderRepository *m_OrderRepository;
};

#endif // BEVERAGE_CONTROLLER_HPP
