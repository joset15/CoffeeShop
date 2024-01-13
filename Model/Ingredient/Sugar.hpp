#ifndef SUGAR_HPP
#define SUGAR_HPP
#pragma once

#include "IngredientDecorator.hpp"

class Sugar : public IngredientDecorator
  //class Sugar : public IBeverage
{
public:
  /// \brief
  Sugar(std::shared_ptr<IBeverage> beverage) : IngredientDecorator(beverage) { }
  //Sugar(IBeverage* beverage) : IngredientDecorator(beverage) { }

  /// @brief Gets the description of the ingredient.
  /// @return The description.
  std::string getDescription() const override { return m_Beverage->getDescription() + ", Sugar"; }
};

#endif // INGREDIENT_DECORATOR_HPP

