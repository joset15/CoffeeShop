#ifndef INGREDIENT_HPP
#define INGREDIENT_HPP

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
  Water,
};
} // namespace coffee_shop::domain

#endif // INGREDIENT_HPP
