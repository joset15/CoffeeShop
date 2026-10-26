#ifndef BEVERAGE_VARIETY_HPP
#define BEVERAGE_VARIETY_HPP

#include "Cocoa.hpp"
#include "CoffeeDecaf.hpp"
#include "CoffeeEspresso.hpp"
#include "CoffeeLatte.hpp"
#include "TeaBlack.hpp"
#include "TeaGreen.hpp"

namespace coffee_shop::domain
{
/// @brief The varieties of beverages.
enum class BeverageVariety
{
  CoffeeEspresso,
  CoffeeLatte,
  CoffeeDecaf,
  TeaBlack,
  TeaGreen,
  Cocoa,
  // LastVariety
};
} // namespace coffee_shop::domain

#endif // BEVERAGE_VARIETY_HPP
