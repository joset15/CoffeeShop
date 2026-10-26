#include "Domain/BeverageBuilder/TeaGreenBuilder.hpp"
#include "Domain/BeverageBuilder/TeaBuilder.hpp"
#include "Domain/Beverages/BeverageVariety.hpp"

namespace coffee_shop::domain
{
void TeaGreenBuilder::resetImpl()
{
  setBaseBeverage(BeverageVariety::TeaGreen);

  TeaBuilder::resetImpl();
}
} // namespace coffee_shop::domain
