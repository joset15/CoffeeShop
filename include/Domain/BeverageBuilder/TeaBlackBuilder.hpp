#ifndef TEA_BLACK_BUILDER_HPP
#define TEA_BLACK_BUILDER_HPP

#include "TeaBuilder.hpp"

class TeaBlackBuilder : public TeaBuilder
{
public:
  TeaBlackBuilder(IBeverageFactory *beverageFactory,
                  IIngredientFactory *ingredientFactory)
      : TeaBuilder(beverageFactory, ingredientFactory)
  {
    resetImpl();
  }

  /// @brief Starts a new beverage, discarding the one being built.
  void reset() override { resetImpl(); }

protected:
  /// @brief Creates the base beverage and resets the builder state.
  void resetImpl();
};

#endif // TEA_BLACK_BUILDER_HPP