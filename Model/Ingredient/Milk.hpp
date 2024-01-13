#ifndef MILK_HPP
#define MILK_HPP
#pragma once

#include "IngredientDecorator.hpp"

class Milk : public IngredientDecorator
{
public:
  /// \brief
  Milk(std::shared_ptr<IBeverage> beverage) : IngredientDecorator(beverage) { }
  //Sugar(IBeverage* beverage) : IngredientDecorator(beverage) { }

  /// @brief Gets the description of the ingredient.
  /// @return The description.
  std::string getDescription() const override { return m_Beverage->getDescription() + ", Milk"; }
};

#endif // MILK_HPP

