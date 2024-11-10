#ifndef MILK_HPP
#define MILK_HPP
#pragma once

#include "IngredientDecorator.hpp"

static const std::string MilkName = "Milk";

class Milk : public IngredientDecorator
{
public:
  /// @brief
  /// @param beverage
  explicit Milk(const std::shared_ptr<IBeverage> &beverage)
      : IngredientDecorator(beverage)
  {
  }

  /// @brief Gets the description of the ingredient.
  /// @return The description.
  std::string getDescription() const override
  {
    return m_Beverage->getDescription() + ", " + MilkName;
  }
};

#endif // MILK_HPP
