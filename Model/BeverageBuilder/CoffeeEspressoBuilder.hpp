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
  CoffeeEspressoBuilder() { resetImpl(); }

  /// @brief
  void reset() override { resetImpl(); }

private:
  /// @brief
  void resetImpl();
};

#endif // COFFEE_ESPRESSO_BUILDER_HPP