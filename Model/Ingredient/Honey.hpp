#ifndef HONEY_HPP
#define HONEY_HPP
#pragma once

#include "IngredientDecorator.hpp"

class Honey : public IngredientDecorator
{
public:
  /// \brief
  explicit Honey(std::shared_ptr<IBeverage> beverage)
      : IngredientDecorator(beverage)
  {
  }
  // Sugar(IBeverage* beverage) : IngredientDecorator(beverage) { }

  /// @brief Gets the description of the ingredient.
  /// @return The description.
  std::string getDescription() const override
  {
    return m_Beverage->getDescription() + ", Honey";
  }
};

#endif // HONEY_HPP
