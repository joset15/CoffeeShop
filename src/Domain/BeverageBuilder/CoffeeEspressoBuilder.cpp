#include "Domain/BeverageBuilder/CoffeeEspressoBuilder.hpp"

namespace coffee_shop::domain
{
void CoffeeEspressoBuilder::resetImpl()
{
  setBaseBeverage(BeverageVariety::CoffeeEspresso);

  CoffeeBuilder::resetImpl();
}
} // namespace coffee_shop::domain
