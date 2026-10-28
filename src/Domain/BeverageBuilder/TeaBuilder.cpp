#include "Domain/BeverageBuilder/TeaBuilder.hpp"

#include "Domain/Ingredients/Ingredient.hpp"

namespace coffee_shop::domain
{
void TeaBuilder::resetState()
{
  m_HasMilk = false;
  m_HasLemon = false;
}

bool TeaBuilder::addSugar()
{
  decorateWith(Ingredient::Sugar);
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
    decorateWith(Ingredient::Milk);
    break;
  case Ingredient::Cream:
    decorateWith(Ingredient::Cream);
    break;
  case Ingredient::SoyMilk:
    decorateWith(Ingredient::SoyMilk);
    break;
  default:
    // Not a kind of milk.
    return false;
  }

  m_HasMilk = true;
  return true;
};

bool TeaBuilder::addHoney()
{
  decorateWith(Ingredient::Honey);
  return true;
};

bool TeaBuilder::addLemon()
{
  if (m_HasMilk)
  {
    return false;
  }

  decorateWith(Ingredient::Lemon);

  m_HasLemon = true;
  return true;
};
} // namespace coffee_shop::domain
