#include "BeverageBuilderFactory.hpp"
#include "BeverageFactory.hpp"
#include "IngredientFactory.hpp"

#include <assert.h>

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
    // TODO Add builder.
    break;
  case BeverageVariety::CoffeeDecaf:
    // TODO Add builder.
    break;
  case BeverageVariety::TeaBlack:
    newBeverageBuilder = std::make_shared<TeaBlackBuilder>(
        BeverageFactory::getInstance(), IngredientFactory::getInstance());
    break;
  case BeverageVariety::TeaGreen:
    // TODO Add builder.
    break;
  case BeverageVariety::Cocoa:
    newBeverageBuilder = std::make_shared<CocoaBuilder>(
        BeverageFactory::getInstance(), IngredientFactory::getInstance());
    break;
  default:
    assert(false && "Unexpected beverageType");
    break;
  }

  assert(newBeverageBuilder && "Beverage Builder not created.");

  return newBeverageBuilder;
}