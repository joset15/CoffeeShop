#include "Domain/BeverageBuilder/TeaBlackBuilder.hpp"

#include "Domain/BeverageBuilder/TeaBuilder.hpp"
#include "Domain/Beverages/BeverageVariety.hpp"

namespace coffee_shop::domain
{
void TeaBlackBuilder::resetImpl()
{
  setBaseBeverage(BeverageVariety::TeaBlack);

  TeaBuilder::resetState();
}
} // namespace coffee_shop::domain
