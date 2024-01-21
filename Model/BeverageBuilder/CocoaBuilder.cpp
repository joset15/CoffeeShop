#include "CocoaBuilder.hpp"

void CocoaBuilder::addMilk(Ingredient typeOfMilk)
{
  if (m_HasMilk)
  {
    return;
  }

  switch (typeOfMilk)
  {
  case Ingredient::Milk:
    m_Beverage = std::make_shared<Milk>(m_Beverage);
    m_HasMilk = true;
    break;
  case Ingredient::SoyMilk:
    m_Beverage = std::make_shared<SoyMilk>(m_Beverage);
    m_HasMilk = true;
    break;
  default:
    assert(false && "Invalid type of milk");
  }
};
