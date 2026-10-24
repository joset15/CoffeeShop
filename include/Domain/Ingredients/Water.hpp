#ifndef WATER_HPP
#define WATER_HPP
#pragma once

#include "IngredientDecorator.hpp"

class Water : public IngredientDecorator
{
public:
  /// @brief Takes ownership of the beverage to decorate.
  using IngredientDecorator::IngredientDecorator;

  /// @brief Gets the description of the ingredient.
  /// @return The description.
  [[nodiscard]] std::string getDescription() const override
  {
    return getDecoratedBeverage().getDescription() + ", Water";
  }
};

#endif // WATER_HPP
