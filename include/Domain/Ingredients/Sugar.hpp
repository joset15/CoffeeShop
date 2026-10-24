#ifndef SUGAR_HPP
#define SUGAR_HPP
#pragma once

#include "IngredientDecorator.hpp"

static const std::string SugarName = "Sugar";

class Sugar : public IngredientDecorator
{
public:
  /// @brief Takes ownership of the beverage to decorate.
  using IngredientDecorator::IngredientDecorator;

  /// @brief Gets the description of the ingredient.
  /// @return The description.
  std::string getDescription() const override
  {
    return getDecoratedBeverage().getDescription() + ", " + SugarName;
  }
};

#endif // INGREDIENT_DECORATOR_HPP
