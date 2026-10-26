#include "Domain/BeverageBuilder/CoffeeBuilder.hpp"

namespace coffee_shop::domain
{
void CoffeeBuilder::resetImpl() { m_HasMilk = false; }

bool CoffeeBuilder::addSugar()
{
  decorateWith(Ingredient::Sugar);
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
} // namespace coffee_shop::domain
