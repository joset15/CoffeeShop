#ifndef COFFEE_LATTE_BUILDER_HPP
#define COFFEE_LATTE_BUILDER_HPP
#pragma once

#include "CoffeeBuilder.hpp"

/// @brief Builds a coffee latte: like an espresso, but it already has milk.
class CoffeeLatteBuilder : public CoffeeBuilder
{
public:
  /// @brief The constructor.
  CoffeeLatteBuilder(IBeverageFactory *beverageFactory,
                     IIngredientFactory *ingredientFactory)
      : CoffeeBuilder(beverageFactory, ingredientFactory)
  {
    resetImpl();
  }

  /// @brief Starts a new beverage, discarding the one being built.
  void reset() override { resetImpl(); }

  /// @brief A latte already has milk, so no milk (of any kind) can be added.
  /// @return Always false.
  bool addMilk(Ingredient /*typeOfMilk*/) override { return false; }

private:
  /// @brief Creates the base beverage and resets the CoffeeBuilder state.
  void resetImpl();
};

#endif // COFFEE_LATTE_BUILDER_HPP
