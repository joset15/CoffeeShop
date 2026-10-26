#include "Domain/BeverageBuilder/TeaGreenBuilder.hpp"

namespace coffee_shop::domain
{
void TeaGreenBuilder::resetImpl()
{
  setBaseBeverage(BeverageVariety::TeaGreen);

  TeaBuilder::resetImpl();
}
} // namespace coffee_shop::domain
