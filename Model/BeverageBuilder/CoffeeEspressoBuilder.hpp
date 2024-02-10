#ifndef COFFEE_ESPRESSO_BUILDER_HPP
#define COFFEE_ESPRESSO_BUILDER_HPP
#pragma once

#include "../Beverages/CoffeeEspresso.hpp"
#include "../Ingredient/Ingredients.hpp"
#include "CoffeeBuilder.hpp"
#include "IBeverageBuilder.hpp"

#include <assert.h>

class CoffeeEspressoBuilder : public CoffeeBuilder
{
public:
  CoffeeEspressoBuilder() { reset(); }

  /// @brief
  void reset() override
  {
    m_Beverage = std::make_shared<CoffeeEspresso>();
    m_HasMilk = false;
  }
};

#endif // COFFEE_ESPRESSO_BUILDER_HPP