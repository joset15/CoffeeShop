#ifndef INGREDIENT_FACTORY_HPP
#define INGREDIENT_FACTORY_HPP

#include "Domain/BeverageFactories/IIngredientFactory.hpp"
#include <memory>

namespace coffee_shop::domain
{
/// @brief Creates the ingredient decorators.
class IngredientFactory final : public IIngredientFactory
{
public:
  /// @brief Wraps a beverage with the decorator of an ingredient.
  /// @param ingredient The ingredient to add.
  /// @param beverage The beverage to decorate; the decorator takes ownership.
  /// @return The decorated beverage (nullptr only for an invalid Ingredient
  /// value).
  std::unique_ptr<IBeverage>
  createIngredient(Ingredient ingredient,
                   std::unique_ptr<IBeverage> beverage) override;
};
} // namespace coffee_shop::domain

#endif // INGREDIENT_FACTORY_HPP
