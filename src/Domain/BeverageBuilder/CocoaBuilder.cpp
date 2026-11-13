#include "Domain/BeverageBuilder/CocoaBuilder.hpp"

#include "Domain/Beverages/BeverageVariety.hpp"
#include "Domain/Ingredients/Ingredient.hpp"

namespace coffee_shop::domain
{
void CocoaBuilder::resetImpl()
{
  setBaseBeverage(BeverageVariety::Cocoa);
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
  case Ingredient::Cream:
  case Ingredient::Sugar:
  case Ingredient::Honey:
  case Ingredient::Lemon:
  case Ingredient::Water:
    // Cocoa only accepts milk or soy milk: cream, and what isn't milk, is
    // rejected.
    return false;
  }

  m_HasMilk = true;
  return true;
}
} // namespace coffee_shop::domain
