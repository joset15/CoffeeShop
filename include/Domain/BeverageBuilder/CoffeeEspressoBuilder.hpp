#ifndef COFFEE_ESPRESSO_BUILDER_HPP
#define COFFEE_ESPRESSO_BUILDER_HPP
#pragma once

#include "CoffeeBuilder.hpp"
#include "IBeverageBuilder.hpp"

class CoffeeEspressoBuilder : public CoffeeBuilder
{
public:
  /// @brief The constructor.
  CoffeeEspressoBuilder(IBeverageFactory *beverageFactory,
                        IIngredientFactory *ingredientFactory)
      : CoffeeBuilder(beverageFactory, ingredientFactory)
  {
    resetImpl();
  }

  /// @brief Resets. the builder.
  void reset() override { resetImpl(); }

private:
  /// @brief
  void resetImpl();
};

#endif // COFFEE_ESPRESSO_BUILDER_HPP