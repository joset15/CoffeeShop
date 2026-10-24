#ifndef SOYMILK_HPP
#define SOYMILK_HPP
#pragma once

#include "IngredientDecorator.hpp"

class SoyMilk : public IngredientDecorator
{
public:
  /// @brief Takes ownership of the beverage to decorate.
  using IngredientDecorator::IngredientDecorator;

  /// @brief Gets the description of the ingredient.
  /// @return The description.
  [[nodiscard]] std::string getDescription() const override
  {
    return getDecoratedBeverage().getDescription() + ", SoyMilk";
  }
};

#endif // SOYMILK_HPP
