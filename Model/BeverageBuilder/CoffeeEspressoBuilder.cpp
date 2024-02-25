#include "CoffeeEspressoBuilder.hpp"

void CoffeeEspressoBuilder::resetImpl()
{
  m_Beverage =
      m_BeverageFactory->createBeverage(BeverageVariety::CoffeeEspresso);

  CoffeeBuilder::resetImpl();
}