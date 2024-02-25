#include "CoffeeBuilder.hpp"
#include <cassert>

void CoffeeBuilder::resetImpl() { m_HasMilk = false; }

bool CoffeeBuilder::addSugar()
{
  m_Beverage =
      m_IngredientFactory->createIngredient(Ingredient::Sugar, m_Beverage);
  return true;
};

bool CoffeeBuilder::addMilk(Ingredient typeOfMilk)
{
  if (m_HasMilk)
  {
    return false;
  }

  switch (typeOfMilk)
  {
  case Ingredient::Milk:
    m_Beverage =
        m_IngredientFactory->createIngredient(Ingredient::Milk, m_Beverage);
    break;
  case Ingredient::Cream:
    m_Beverage =
        m_IngredientFactory->createIngredient(Ingredient::Cream, m_Beverage);
    break;
  case Ingredient::SoyMilk:
    m_Beverage =
        m_IngredientFactory->createIngredient(Ingredient::SoyMilk, m_Beverage);
    break;
  default:
    assert(false && "Invalid type of milk");
    return false;
  }

  m_HasMilk = true;

  return true;
};
