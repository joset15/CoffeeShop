#include "Domain/BeverageFactories/BeverageFactory.hpp"
#include <cassert>

std::shared_ptr<IBeverage>
BeverageFactory::createBeverage(BeverageVariety beverageVariety)
{
  std::shared_ptr<IBeverage> newBeverage = nullptr;

  switch (beverageVariety)
  {
  case BeverageVariety::CoffeeEspresso:
    newBeverage = std::make_shared<CoffeeEspresso>();
    break;
  case BeverageVariety::CoffeeLatte:
    newBeverage = std::make_shared<CoffeeLatte>();
    break;
  case BeverageVariety::CoffeeDecaf:
    newBeverage = std::make_shared<CoffeeDecaf>();
    break;
  case BeverageVariety::TeaBlack:
    newBeverage = std::make_shared<TeaBlack>();
    break;
  case BeverageVariety::TeaGreen:
    newBeverage = std::make_shared<TeaGreen>();
    break;
  case BeverageVariety::Cocoa:
    newBeverage = std::make_shared<Cocoa>();
    break;
  default:
    assert(false && "Unexpected beverageType");
    break;
  }

  return newBeverage;
}
