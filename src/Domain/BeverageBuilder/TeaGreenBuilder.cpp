#include "Domain/BeverageBuilder/TeaGreenBuilder.hpp"

void TeaGreenBuilder::resetImpl()
{
  setBaseBeverage(BeverageVariety::TeaGreen);

  TeaBuilder::resetImpl();
}
