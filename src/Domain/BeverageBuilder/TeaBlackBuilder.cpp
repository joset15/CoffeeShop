#include "Domain/BeverageBuilder/TeaBlackBuilder.hpp"

namespace coffee_shop::domain
{
void TeaBlackBuilder::resetImpl()
{
  setBaseBeverage(BeverageVariety::TeaBlack);

  TeaBuilder::resetImpl();
}
} // namespace coffee_shop::domain
