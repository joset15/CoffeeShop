#ifndef COFFEE_DECAF_BUILDER_HPP
#define COFFEE_DECAF_BUILDER_HPP

#include "Domain/BeverageBuilder/CoffeeBuilder.hpp"

namespace coffee_shop::domain
{
/// @brief Builds a decaf coffee, with the same rules as an espresso.
class CoffeeDecafBuilder : public CoffeeBuilder
{
public:
  /// @brief The constructor.
  CoffeeDecafBuilder(IBeverageFactory &beverageFactory,
                     IIngredientFactory &ingredientFactory)
      : CoffeeBuilder(beverageFactory, ingredientFactory)
  {
    resetImpl();
  }

  /// @brief Starts a new beverage, discarding the one being built.
  void reset() override { resetImpl(); }

private:
  /// @brief Creates the base beverage and resets the CoffeeBuilder state.
  void resetImpl();
};
} // namespace coffee_shop::domain

#endif // COFFEE_DECAF_BUILDER_HPP
