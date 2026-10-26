#include "Domain/BeverageFactories/BeverageFactory.hpp"

#include "Domain/Beverages/BeverageVariety.hpp"
#include "Domain/Beverages/Cocoa.hpp"
#include "Domain/Beverages/CoffeeDecaf.hpp"
#include "Domain/Beverages/CoffeeEspresso.hpp"
#include "Domain/Beverages/CoffeeLatte.hpp"
#include "Domain/Beverages/IBeverage.hpp"
#include "Domain/Beverages/TeaBlack.hpp"
#include "Domain/Beverages/TeaGreen.hpp"

#include <memory>

namespace coffee_shop::domain
{
std::unique_ptr<IBeverage>
BeverageFactory::createBeverage(BeverageVariety beverageVariety)
{
  std::unique_ptr<IBeverage> newBeverage = nullptr;

  switch (beverageVariety)
  {
  case BeverageVariety::CoffeeEspresso:
    newBeverage = std::make_unique<CoffeeEspresso>();
    break;
  case BeverageVariety::CoffeeLatte:
    newBeverage = std::make_unique<CoffeeLatte>();
    break;
  case BeverageVariety::CoffeeDecaf:
    newBeverage = std::make_unique<CoffeeDecaf>();
    break;
  case BeverageVariety::TeaBlack:
    newBeverage = std::make_unique<TeaBlack>();
    break;
  case BeverageVariety::TeaGreen:
    newBeverage = std::make_unique<TeaGreen>();
    break;
  case BeverageVariety::Cocoa:
    newBeverage = std::make_unique<Cocoa>();
    break;
  }

  return newBeverage;
}
} // namespace coffee_shop::domain
