#ifndef WATER_HPP
#define WATER_HPP
#pragma once

#include "IngredientDecorator.hpp"

class Water : public IngredientDecorator
{
public:
  /// \brief
  explicit Water(std::shared_ptr<IBeverage> beverage)
      : IngredientDecorator(beverage)
  {
  }

  /// @brief Gets the description of the ingredient.
  /// @return The description.
  std::string getDescription() const override
  {
    return m_Beverage->getDescription() + ", Water";
  }
};

#endif // WATER_HPP
