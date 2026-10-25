#include "Domain/BeverageBuilder/CoffeeLatteBuilder.hpp"

void CoffeeLatteBuilder::resetImpl()
{
  setBaseBeverage(BeverageVariety::CoffeeLatte);

  CoffeeBuilder::resetImpl();
}
