#ifndef TEA_GREEN_BUILDER_HPP
#define TEA_GREEN_BUILDER_HPP

#include "TeaBuilder.hpp"

namespace coffee_shop::domain
{
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
} // namespace coffee_shop::domain

#endif // TEA_GREEN_BUILDER_HPP
