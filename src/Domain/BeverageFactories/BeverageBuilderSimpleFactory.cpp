#include "Domain/BeverageFactories/BeverageBuilderSimpleFactory.hpp"
#include "Domain/BeverageFactories/BeverageFactory.hpp"
#include "Domain/BeverageFactories/IngredientFactory.hpp"

#include <cassert>

namespace coffee_shop::domain
{
std::shared_ptr<IBeverageBuilder>
BeverageBuilderSimpleFactory::createBeverageBuilder(
    BeverageVariety beverageVariety)
{
  std::shared_ptr<IBeverageBuilder> newBeverageBuilder = nullptr;

  switch (beverageVariety)
  {
  case BeverageVariety::CoffeeEspresso:
    newBeverageBuilder = std::make_shared<CoffeeEspressoBuilder>(
        BeverageFactory::getInstance(), IngredientFactory::getInstance());
    break;
  case BeverageVariety::CoffeeLatte:
    newBeverageBuilder = std::make_shared<CoffeeLatteBuilder>(
        BeverageFactory::getInstance(), IngredientFactory::getInstance());
    break;
  case BeverageVariety::CoffeeDecaf:
    newBeverageBuilder = std::make_shared<CoffeeDecafBuilder>(
        BeverageFactory::getInstance(), IngredientFactory::getInstance());
    break;
  case BeverageVariety::TeaBlack:
    newBeverageBuilder = std::make_shared<TeaBlackBuilder>(
        BeverageFactory::getInstance(), IngredientFactory::getInstance());
    break;
  case BeverageVariety::TeaGreen:
    newBeverageBuilder = std::make_shared<TeaGreenBuilder>(
        BeverageFactory::getInstance(), IngredientFactory::getInstance());
    break;
  case BeverageVariety::Cocoa:
    newBeverageBuilder = std::make_shared<CocoaBuilder>(
        BeverageFactory::getInstance(), IngredientFactory::getInstance());
    break;
  default:
    assert(false && "Unexpected beverageType");
    break;
  }

  return newBeverageBuilder;
}
} // namespace coffee_shop::domain
