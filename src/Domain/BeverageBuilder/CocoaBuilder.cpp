#include "Domain/BeverageBuilder/CocoaBuilder.hpp"

#include <cassert>

void CocoaBuilder::resetImpl()
{
  m_Beverage = m_BeverageFactory->createBeverage(BeverageVariety::Cocoa);
  m_HasMilk = false;
}

bool CocoaBuilder::addMilk(Ingredient typeOfMilk)
{
  if (m_HasMilk)
  {
    return false;
  }

  switch (typeOfMilk)
  {
  case Ingredient::Milk:
    decorateWith(Ingredient::Milk);
    break;
  case Ingredient::SoyMilk:
    decorateWith(Ingredient::SoyMilk);
    break;
  default:
    assert(false && "Invalid type of milk");
    return false;
  }

  m_HasMilk = true;
  return true;
};
