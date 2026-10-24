#ifndef MILK_HPP
#define MILK_HPP
#pragma once

#include "IngredientDecorator.hpp"

static const std::string MilkName = "Milk";

class Milk : public IngredientDecorator
{
public:
  /// @brief Takes ownership of the beverage to decorate.
  using IngredientDecorator::IngredientDecorator;

  /// @brief Gets the description of the ingredient.
  /// @return The description.
  std::string getDescription() const override
  {
    return m_Beverage->getDescription() + ", " + MilkName;
  }
};

#endif // MILK_HPP
