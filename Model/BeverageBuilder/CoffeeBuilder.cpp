#include "CoffeeBuilder.hpp"

bool CoffeeBuilder::addMilk(Ingredient typeOfMilk)
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
  case Ingredient::Cream:
    m_Beverage = std::make_shared<Cream>(m_Beverage);
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
