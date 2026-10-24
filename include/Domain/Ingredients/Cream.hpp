#ifndef CREAM_HPP
#define CREAM_HPP
#pragma once

#include "IngredientDecorator.hpp"

class Cream : public IngredientDecorator
{
public:
  /// @brief Takes ownership of the beverage to decorate.
  using IngredientDecorator::IngredientDecorator;

  /// @brief Gets the description of the ingredient.
  /// @return The description.
  std::string getDescription() const override
  {
    return getDecoratedBeverage().getDescription() + ", Cream";
  }
};

#endif // CREAM_HPP
