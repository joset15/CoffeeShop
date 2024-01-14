#ifndef BEVERAGE_VARIETY_HPP
#define BEVERAGE_VARIETY_HPP

#include "./Beverages/CoffeeDecaf.hpp"
#include "./Beverages/CoffeeEspresso.hpp"
#include "./Beverages/CoffeeLatte.hpp"
#include "./Beverages/TeaBlack.hpp"
#include "./Beverages/TeaGreen.hpp"
#include "./Cocoa.hpp"

// TODO Complete doxygen comments.

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

#endif // BEVERAGE_VARIETY_HPP
