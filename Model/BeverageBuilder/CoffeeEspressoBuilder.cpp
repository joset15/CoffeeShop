#include "CoffeeEspressoBuilder.hpp"

void CoffeeEspressoBuilder::resetImpl()
{
  m_Beverage = std::make_shared<CoffeeEspresso>();
  setHasMilk(false);
}