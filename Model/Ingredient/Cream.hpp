#ifndef CREAM_HPP
#define CREAM_HPP
#pragma once

#include "IngredientDecorator.hpp"

class Cream : public IngredientDecorator
{
public:
  /// \brief
  Cream(std::shared_ptr<IBeverage> beverage) : IngredientDecorator(beverage) {}

  /// @brief Gets the description of the ingredient.
  /// @return The description.
  std::string getDescription() const override
  {
    return m_Beverage->getDescription() + ", Cream";
  }
};

#endif // CREAM_HPP
