#include "Domain/BeverageBuilder/CoffeeDecafBuilder.hpp"

namespace coffee_shop::domain
{
void CoffeeDecafBuilder::resetImpl()
{
  setBaseBeverage(BeverageVariety::CoffeeDecaf);

  CoffeeBuilder::resetImpl();
}
} // namespace coffee_shop::domain
