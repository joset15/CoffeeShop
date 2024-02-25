#include "TeaFactory.hpp"
#include <assert.h>

std::shared_ptr<IBeverage>
TeaFactory::createBeverage(BeverageVariety beverageVariety)
{
  std::shared_ptr<IBeverage> newBeverage = nullptr;

  switch (beverageVariety)
  {
  case BeverageVariety::TeaBlack:
    newBeverage = std::make_shared<TeaBlack>();
    break;
  case BeverageVariety::TeaGreen:
    newBeverage = std::make_shared<TeaGreen>();
    break;
  default:
    assert(false && "Unexpected beverageType");
    break;
  }

  return newBeverage;
}