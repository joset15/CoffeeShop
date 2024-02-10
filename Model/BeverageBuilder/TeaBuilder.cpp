#include "TeaBuilder.hpp"

void TeaBuilder::resetImpl()
{
  m_Beverage = std::make_shared<Tea>();
  m_HasMilk = false;
  m_HasLemon = false;
}

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

bool TeaBuilder::addLemon()
{
  if (m_HasMilk)
  {
    return false;
  }

  m_Beverage = std::make_shared<Lemon>(m_Beverage);
  m_HasLemon = true;
  return true;
};
