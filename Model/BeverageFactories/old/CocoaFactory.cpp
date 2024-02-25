#include "CocoaFactory.hpp"
#include <assert.h>

std::shared_ptr<IBeverage>
CocoaFactory::createBeverage(BeverageVariety beverageVariety)
{
  std::shared_ptr<IBeverage> newBeverage = nullptr;

  switch (beverageVariety)
  {
  case BeverageVariety::Cocoa:
    newBeverage = std::make_shared<Cocoa>();
    break;
  default:
    assert(false && "Unexpected beverageType");
    break;
  }

  return newBeverage;
}