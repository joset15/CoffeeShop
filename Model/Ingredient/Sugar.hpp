#ifndef SUGAR_HPP
#define SUGAR_HPP
#pragma once

#include "IngredientDecorator.hpp"

static const std::string SugarName = "Sugar";

class Sugar : public IngredientDecorator
{
public:
  /// @brief
  /// @param beverage
  explicit Sugar(const std::shared_ptr<IBeverage> &beverage)
      : IngredientDecorator(beverage)
  {
  }

  /// @brief Gets the description of the ingredient.
  /// @return The description.
  std::string getDescription() const override
  {
    return m_Beverage->getDescription() + ", " + SugarName;
  }
};

#endif // INGREDIENT_DECORATOR_HPP
