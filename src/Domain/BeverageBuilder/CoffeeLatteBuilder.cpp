#include "Domain/BeverageBuilder/CoffeeLatteBuilder.hpp"

#include "Domain/BeverageBuilder/CoffeeBuilder.hpp"
#include "Domain/Beverages/BeverageVariety.hpp"

namespace coffee_shop::domain
{
void CoffeeLatteBuilder::resetImpl()
{
  setBaseBeverage(BeverageVariety::CoffeeLatte);

  CoffeeBuilder::resetImpl();
}
} // namespace coffee_shop::domain
