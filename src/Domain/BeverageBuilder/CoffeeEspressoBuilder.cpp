#include "Domain/BeverageBuilder/CoffeeEspressoBuilder.hpp"

#include "Domain/BeverageBuilder/CoffeeBuilder.hpp"
#include "Domain/Beverages/BeverageVariety.hpp"

namespace coffee_shop::domain
{
void CoffeeEspressoBuilder::resetImpl()
{
  setBaseBeverage(BeverageVariety::CoffeeEspresso);

  CoffeeBuilder::resetState();
}
} // namespace coffee_shop::domain
