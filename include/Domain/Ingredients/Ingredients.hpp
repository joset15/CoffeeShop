#ifndef INGREDIENTS_HPP
#define INGREDIENTS_HPP

#include "Cream.hpp"
#include "Honey.hpp"
#include "IngredientDecorator.hpp"
#include "Lemon.hpp"
#include "Milk.hpp"
#include "SoyMilk.hpp"
#include "Sugar.hpp"
#include "Water.hpp"

namespace coffee_shop::domain
{
enum class Ingredient
{
  Sugar,
  Milk,
  Cream,
  Honey,
  Lemon,
  SoyMilk,
  Water,
  LastIngredient
};
} // namespace coffee_shop::domain

#endif // INGREDIENTS_HPP
