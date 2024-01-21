#include "CoffeeBuilder.hpp"

/// @brief Adds milk to the beverage.
/// @param typeOfMilk The type of milk we are adding.
void CoffeeBuilder::addMilk(Ingredient typeOfMilk)
{
  if (m_HasMilk)
  {
    return;
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
    return;
  }

  m_HasMilk = true;
};
