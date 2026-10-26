#include "Domain/BeverageBuilder/CoffeeDecafBuilder.hpp"
#include "Domain/BeverageBuilder/CoffeeBuilder.hpp"
#include "Domain/Beverages/BeverageVariety.hpp"

namespace coffee_shop::domain
{
void CoffeeDecafBuilder::resetImpl()
{
  setBaseBeverage(BeverageVariety::CoffeeDecaf);

  CoffeeBuilder::resetImpl();
}
} // namespace coffee_shop::domain
