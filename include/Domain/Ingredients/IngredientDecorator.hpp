#ifndef INGREDIENT_DECORATOR_HPP
#define INGREDIENT_DECORATOR_HPP

#include "../Beverages/IBeverage.hpp"

#include <memory>
#include <stdexcept>
#include <string>
#include <utility>

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
  /// @brief The decorator owns the decorated object.
  std::unique_ptr<IBeverage> m_Beverage;
};

#endif // INGREDIENT_DECORATOR_HPP
