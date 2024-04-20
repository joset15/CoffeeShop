#ifndef SOYMILK_HPP
#define SOYMILK_HPP
#pragma once

#include "IngredientDecorator.hpp"

class SoyMilk : public IngredientDecorator
{
public:
  /// \brief
  explicit SoyMilk(const std::shared_ptr<IBeverage> &beverage)
      : IngredientDecorator(beverage)
  {
  }
  // Sugar(IBeverage* beverage) : IngredientDecorator(beverage) { }

  /// @brief Gets the description of the ingredient.
  /// @return The description.
  std::string getDescription() const override
  {
    return m_Beverage->getDescription() + ", SoyMilk";
  }
};

#endif // SOYMILK_HPP
