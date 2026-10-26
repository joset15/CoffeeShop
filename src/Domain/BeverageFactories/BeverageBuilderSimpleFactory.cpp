#include "Domain/BeverageFactories/BeverageBuilderSimpleFactory.hpp"
#include "Domain/BeverageFactories/BeverageFactory.hpp"
#include "Domain/BeverageFactories/IngredientFactory.hpp"


namespace coffee_shop::domain
{
std::unique_ptr<IBeverageBuilder>
BeverageBuilderSimpleFactory::createBeverageBuilder(
    BeverageVariety beverageVariety)
{
  std::unique_ptr<IBeverageBuilder> newBeverageBuilder = nullptr;

  switch (beverageVariety)
  {
  case BeverageVariety::CoffeeEspresso:
    newBeverageBuilder = std::make_unique<CoffeeEspressoBuilder>(
        BeverageFactory::getInstance(), IngredientFactory::getInstance());
    break;
  case BeverageVariety::CoffeeLatte:
    newBeverageBuilder = std::make_unique<CoffeeLatteBuilder>(
        BeverageFactory::getInstance(), IngredientFactory::getInstance());
    break;
  case BeverageVariety::CoffeeDecaf:
    newBeverageBuilder = std::make_unique<CoffeeDecafBuilder>(
        BeverageFactory::getInstance(), IngredientFactory::getInstance());
    break;
  case BeverageVariety::TeaBlack:
    newBeverageBuilder = std::make_unique<TeaBlackBuilder>(
        BeverageFactory::getInstance(), IngredientFactory::getInstance());
    break;
  case BeverageVariety::TeaGreen:
    newBeverageBuilder = std::make_unique<TeaGreenBuilder>(
        BeverageFactory::getInstance(), IngredientFactory::getInstance());
    break;
  case BeverageVariety::Cocoa:
    newBeverageBuilder = std::make_unique<CocoaBuilder>(
        BeverageFactory::getInstance(), IngredientFactory::getInstance());
    break;
  }

  return newBeverageBuilder;
}
} // namespace coffee_shop::domain
