#ifndef TEA_BLACK_BUILDER_HPP
#define TEA_BLACK_BUILDER_HPP

#include "Domain/BeverageBuilder/TeaBuilder.hpp"

namespace coffee_shop::domain
{
class TeaBlackBuilder : public TeaBuilder
{
public:
  TeaBlackBuilder(IBeverageFactory &beverageFactory,
                  IIngredientFactory &ingredientFactory)
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
} // namespace coffee_shop::domain

#endif // TEA_BLACK_BUILDER_HPP
