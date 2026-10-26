#ifndef BEVERAGE_VARIETY_HPP
#define BEVERAGE_VARIETY_HPP

#include <cstdint>

namespace coffee_shop::domain
{
/// @brief The varieties of beverages.
enum class BeverageVariety : std::uint8_t
{
  CoffeeEspresso,
  CoffeeLatte,
  CoffeeDecaf,
  TeaBlack,
  TeaGreen,
  Cocoa
};
} // namespace coffee_shop::domain

#endif // BEVERAGE_VARIETY_HPP
