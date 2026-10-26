#ifndef IINGREDIENT_FACTORY_HPP
#define IINGREDIENT_FACTORY_HPP

#include "Domain/Beverages/IBeverage.hpp"
#include "Domain/Ingredients/Ingredient.hpp"
#include <memory>

namespace coffee_shop::domain
{
/// @brief Wraps beverages with ingredient decorators (Abstract Factory).
class IIngredientFactory
{
public:
  /// @brief Allows deleting an implementation through this interface.
  virtual ~IIngredientFactory() = default;

  /// @brief Wraps a beverage with the decorator of an ingredient.
  /// @param ingredient The ingredient to add.
  /// @param beverage The beverage to decorate; the decorator takes ownership.
  /// @return The decorated beverage (nullptr only for an invalid Ingredient
  /// value).
  virtual std::unique_ptr<IBeverage>
  createIngredient(Ingredient ingredient,
                   std::unique_ptr<IBeverage> beverage) = 0;
};
} // namespace coffee_shop::domain

#endif // IINGREDIENT_FACTORY_HPP
