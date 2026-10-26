#include "Domain/BeverageBuilder/CoffeeLatteBuilder.hpp"

namespace coffee_shop::domain
{
void CoffeeLatteBuilder::resetImpl()
{
  setBaseBeverage(BeverageVariety::CoffeeLatte);

  CoffeeBuilder::resetImpl();
}
} // namespace coffee_shop::domain
