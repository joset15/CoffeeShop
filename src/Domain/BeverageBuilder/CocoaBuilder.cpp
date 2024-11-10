#include "Domain/BeverageBuilder/CocoaBuilder.hpp"

void CocoaBuilder::resetImpl()
{
  m_Beverage = std::make_shared<Cocoa>();
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
    m_Beverage = std::make_shared<Milk>(m_Beverage);
    break;
  case Ingredient::SoyMilk:
    m_Beverage = std::make_shared<SoyMilk>(m_Beverage);
    break;
  default:
    assert(false && "Invalid type of milk");
    return false;
  }

  m_HasMilk = true;
  return true;
};
