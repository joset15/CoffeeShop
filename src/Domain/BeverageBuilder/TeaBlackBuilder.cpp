#include "Domain/BeverageBuilder/TeaBlackBuilder.hpp"

void TeaBlackBuilder::resetImpl()
{
  setBaseBeverage(BeverageVariety::TeaBlack);

  TeaBuilder::resetImpl();
}