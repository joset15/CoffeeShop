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
  default:
    // Cocoa only accepts milk or soy milk (e.g. cream is rejected).
    return false;
  }

  m_HasMilk = true;
  return true;
};
} // namespace coffee_shop::domain
