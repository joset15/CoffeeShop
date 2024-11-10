#include "Domain/BeverageBuilder/CoffeeEspressoBuilder.hpp"

void CoffeeEspressoBuilder::resetImpl()
{
  m_Beverage =
      m_BeverageFactory->createBeverage(BeverageVariety::CoffeeEspresso);

  CoffeeBuilder::resetImpl();
}