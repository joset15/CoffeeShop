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

#include <cstdint>

namespace coffee_shop::domain
{
enum class Ingredient : std::uint8_t
{
  Sugar,
  Milk,
  Cream,
  Honey,
  Lemon,
  SoyMilk,
  Water
};
} // namespace coffee_shop::domain

#endif // INGREDIENTS_HPP
