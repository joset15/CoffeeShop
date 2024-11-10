#include "Domain/BeverageBuilder/TeaBlackBuilder.hpp"

void TeaBlackBuilder::resetImpl()
{
  m_Beverage = m_BeverageFactory->createBeverage(BeverageVariety::TeaBlack);

  TeaBuilder::reset();
}