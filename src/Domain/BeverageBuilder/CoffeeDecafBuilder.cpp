#include "Domain/BeverageBuilder/CoffeeDecafBuilder.hpp"

void CoffeeDecafBuilder::resetImpl()
{
  setBaseBeverage(BeverageVariety::CoffeeDecaf);

  CoffeeBuilder::resetImpl();
}
