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

#endif // INGREDIENTS_HPP
