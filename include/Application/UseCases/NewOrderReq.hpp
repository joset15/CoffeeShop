#ifndef NEW_ORDER_REQ_HPP
#define NEW_ORDER_REQ_HPP

#include "IRequest.hpp"

#include "Domain/Beverages/BeverageVariety.hpp"
#include "Domain/Ingredients/Ingredients.hpp"

#include <list>

namespace coffee_shop::application
{
/// @brief The data of a "new order" request: one beverage and its ingredients.
struct NewOrderReq : IRequest
{
public:
  NewOrderReq() = delete;

  /// @brief Creates the request.
  /// @param beverageVariety The beverage to order.
  /// @param ingredients The ingredients to add to it.
  NewOrderReq(domain::BeverageVariety beverageVariety,
              const std::list<domain::Ingredient> &ingredients)
      : m_BeverageVariety(beverageVariety), m_Ingredients(ingredients)
  {
  }

  /// @return The beverage to order.
  [[nodiscard]] domain::BeverageVariety getBeverageVariety() const
  {
    return m_BeverageVariety;
  }
  /// @return The ingredients to add.
  [[nodiscard]] const std::list<domain::Ingredient> &getIngredients() const
  {
    return m_Ingredients;
  }

private:
  domain::BeverageVariety m_BeverageVariety;
  std::list<domain::Ingredient> m_Ingredients;
};
} // namespace coffee_shop::application

#endif // NEW_ORDER_REQ_HPP