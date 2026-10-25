#ifndef TEA_GREEN_BUILDER_HPP
#define TEA_GREEN_BUILDER_HPP
#pragma once

#include "TeaBuilder.hpp"

/// @brief Builds a green tea, with the same rules as a black tea.
class TeaGreenBuilder : public TeaBuilder
{
public:
  /// @brief The constructor.
  TeaGreenBuilder(IBeverageFactory *beverageFactory,
                  IIngredientFactory *ingredientFactory)
      : TeaBuilder(beverageFactory, ingredientFactory)
  {
    resetImpl();
  }

  /// @brief Starts a new beverage, discarding the one being built.
  void reset() override { resetImpl(); }

private:
  /// @brief Creates the base beverage and resets the TeaBuilder state.
  void resetImpl();
};

#endif // TEA_GREEN_BUILDER_HPP
