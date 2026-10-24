#ifndef LEMON_HPP
#define LEMON_HPP
#pragma once

#include "IngredientDecorator.hpp"

static const std::string LemonName = "Lemon";

class Lemon : public IngredientDecorator
{
public:
  /// @brief Takes ownership of the beverage to decorate.
  using IngredientDecorator::IngredientDecorator;

  /// @brief Gets the description of the ingredient.
  /// @return The description.
  std::string getDescription() const override
  {
    return m_Beverage->getDescription() + ", " + LemonName;
  }
};

#endif // LEMON_HPP
