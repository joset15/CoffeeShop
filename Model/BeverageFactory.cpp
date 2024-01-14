#include "BeverageFactory.hpp"

//#include "..\Model\Cocoa.hpp"
//#include "..\Model\Coffee.hpp"
//#include "..\Model\Tea.hpp"

#include <assert.h>

/// \brief
std::shared_ptr<IBeverage>
BeverageFactory::createBeverage(BeverageVariety beverageVariety)
{
  std::shared_ptr<IBeverage> newBeverage = nullptr;

  try
  {
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
  }
  catch (...)
  {
    // newBeverage.reset(nullptr);
    newBeverage.reset();
  }

  return newBeverage;
}

std::shared_ptr<IBeverage>
BeverageFactory::createBeverage(IBeverage::BeverageType beverageType,
                                BeverageVariety beverageVariety)
{
  std::shared_ptr<IBeverage> newBeverage = nullptr;

  /*
  try
  {
    switch (beverageType)
    {
    case IBeverage::BeverageType::Coffee:
      newBeverage = std::make_unique<Coffee>(beverageVariety);
      break;
    case IBeverage::BeverageType::Tea:
      newBeverage = std::make_unique<Tea>(beverageVariety);
      break;
    case IBeverage::BeverageType::Cocoa:
      newBeverage = std::make_unique<Cocoa>(beverageVariety);
      break;
    default:
      assert(false && "Unexpected beverageType");
      break;
    }
  }
  catch (...)
  {
    // newBeverage.reset(nullptr);
    newBeverage.reset();
  }
  */

  return newBeverage;
}
