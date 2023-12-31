#include "BeverageFactory.hpp"

#include "..\Model\Cocoa.hpp"
#include "..\Model\Coffee.hpp"
#include "..\Model\Tea.hpp"

#include <assert.h>

std::shared_ptr<IBeverage>
BeverageFactory::createBeverage(IBeverage::BeverageType beverageType,
                                BeverageVariety beverageVariety)
{
  std::shared_ptr<IBeverage> newBeverage = nullptr;

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

  return newBeverage;
}
