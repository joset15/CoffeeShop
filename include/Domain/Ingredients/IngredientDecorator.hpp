#ifndef INGREDIENT_DECORATOR_HPP
#define INGREDIENT_DECORATOR_HPP

#include "Domain/Beverages/IBeverage.hpp"

#include <memory>
#include <stdexcept>
#include <string>
#include <string_view>
#include <utility>

namespace coffee_shop::domain
{
class IngredientDecorator : public IBeverage
{
public:
  /// @brief Wraps a beverage, taking ownership of it.
  /// @param beverage The beverage to decorate. Must not be null.
  /// @throw std::invalid_argument If beverage is null.
  explicit IngredientDecorator(std::unique_ptr<IBeverage> beverage)
      : m_Beverage(std::move(beverage))
  {
    if (!m_Beverage)
    {
      throw std::invalid_argument("IngredientDecorator: null beverage");
    }
  }

protected:
  /// @brief The beverage this decorator wraps.
  [[nodiscard]] const IBeverage &getDecoratedBeverage() const
  {
    return *m_Beverage;
  }

  /// @brief Describes the decorated beverage followed by this ingredient.
  /// @param ingredientName The name of this ingredient.
  /// @return For example "Coffee, Sugar".
  [[nodiscard]] std::string describeWith(std::string_view ingredientName) const
  {
    return getDecoratedBeverage().getDescription().append(", ").append(
        ingredientName);
  }

private:
  /// @brief The decorator owns the decorated object.
  std::unique_ptr<IBeverage> m_Beverage;
};
} // namespace coffee_shop::domain

#endif // INGREDIENT_DECORATOR_HPP
