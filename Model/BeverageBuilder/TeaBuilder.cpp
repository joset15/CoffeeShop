#include "TeaBuilder.hpp"
#include <cassert>

void TeaBuilder::resetImpl()
{
  m_HasMilk = false;
  m_HasLemon = false;
}

bool TeaBuilder::addSugar()
{
  m_Beverage =
      m_IngredientFactory->createIngredient(Ingredient::Sugar, m_Beverage);
  return true;
};

/// @brief Adds milk to the beverage.
/// @param typeOfMilk The type of milk we are adding.
bool TeaBuilder::addMilk(Ingredient typeOfMilk)
{
  if (m_HasLemon || m_HasMilk)
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

bool TeaBuilder::addHoney()
{
  m_Beverage =
      m_IngredientFactory->createIngredient(Ingredient::Honey, m_Beverage);
  return true;
};

bool TeaBuilder::addLemon()
{
  if (m_HasMilk)
  {
    return false;
  }

  m_Beverage =
      m_IngredientFactory->createIngredient(Ingredient::Lemon, m_Beverage);

  m_HasLemon = true;
  return true;
};
