#ifndef HONEY_HPP
#define HONEY_HPP
#pragma once

#include "IngredientDecorator.hpp"

class Honey : public IngredientDecorator
{
public:
  /// @brief Takes ownership of the beverage to decorate.
  using IngredientDecorator::IngredientDecorator;

  /// @brief Gets the description of the ingredient.
  /// @return The description.
  std::string getDescription() const override
  {
    return getDecoratedBeverage().getDescription() + ", Honey";
  }
};

#endif // HONEY_HPP
