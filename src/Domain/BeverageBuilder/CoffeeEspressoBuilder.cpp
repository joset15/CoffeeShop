#include "Domain/BeverageBuilder/CoffeeEspressoBuilder.hpp"

void CoffeeEspressoBuilder::resetImpl()
{
  setBaseBeverage(BeverageVariety::CoffeeEspresso);

  CoffeeBuilder::resetImpl();
}