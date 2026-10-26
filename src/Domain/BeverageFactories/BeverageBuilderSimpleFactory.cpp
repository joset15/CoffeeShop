#include "Domain/BeverageFactories/BeverageBuilderSimpleFactory.hpp"
#include "Domain/BeverageBuilder/CocoaBuilder.hpp"
#include "Domain/BeverageBuilder/CoffeeDecafBuilder.hpp"
#include "Domain/BeverageBuilder/CoffeeEspressoBuilder.hpp"
#include "Domain/BeverageBuilder/CoffeeLatteBuilder.hpp"
#include "Domain/BeverageBuilder/IBeverageBuilder.hpp"
#include "Domain/BeverageBuilder/TeaBlackBuilder.hpp"
#include "Domain/BeverageBuilder/TeaGreenBuilder.hpp"
#include "Domain/Beverages/BeverageVariety.hpp"
#include <memory>

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
        *m_BeverageFactory, *m_IngredientFactory);
    break;
  case BeverageVariety::CoffeeLatte:
    newBeverageBuilder = std::make_unique<CoffeeLatteBuilder>(
        *m_BeverageFactory, *m_IngredientFactory);
    break;
  case BeverageVariety::CoffeeDecaf:
    newBeverageBuilder = std::make_unique<CoffeeDecafBuilder>(
        *m_BeverageFactory, *m_IngredientFactory);
    break;
  case BeverageVariety::TeaBlack:
    newBeverageBuilder = std::make_unique<TeaBlackBuilder>(
        *m_BeverageFactory, *m_IngredientFactory);
    break;
  case BeverageVariety::TeaGreen:
    newBeverageBuilder = std::make_unique<TeaGreenBuilder>(
        *m_BeverageFactory, *m_IngredientFactory);
    break;
  case BeverageVariety::Cocoa:
    newBeverageBuilder = std::make_unique<CocoaBuilder>(*m_BeverageFactory,
                                                        *m_IngredientFactory);
    break;
  }

  return newBeverageBuilder;
}
} // namespace coffee_shop::domain
