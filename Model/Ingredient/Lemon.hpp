#ifndef LEMON_HPP
#define LEMON_HPP
#pragma once

#include "IngredientDecorator.hpp"

class Lemon : public IngredientDecorator
{
public:
  /// \brief
  explicit Lemon(std::shared_ptr<IBeverage> beverage)
      : IngredientDecorator(beverage)
  {
  }

  /// @brief Gets the description of the ingredient.
  /// @return The description.
  std::string getDescription() const override
  {
    return m_Beverage->getDescription() + ", Lemon";
  }
};

#endif // LEMON_HPP
