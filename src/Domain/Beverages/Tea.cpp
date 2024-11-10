#include "Domain/Beverages/Tea.hpp"

#include <stdexcept>

/*
Tea::Tea(BeverageVariety beverageVariety) : IBeverage(beverageVariety)
{
  if (beverageVariety != BeverageVariety::TeaBlack &&
    beverageVariety != BeverageVariety::TeaGreen)
  {
    throw std::runtime_error("Invalid main ingredient for Tea");
  }
}
*/

/*
bool Tea::addExtraIngredient(Ingredient extraIngredient)
{
  if (extraIngredient == Ingredient::Lemon)
  {
    if (m_ExtraIngredientSet.find(Ingredient::Milk) !=
      m_ExtraIngredientSet.end() ||
      m_ExtraIngredientSet.find(Ingredient::SoyMilk) !=
      m_ExtraIngredientSet.end() ||
      m_ExtraIngredientSet.find(Ingredient::Cream) !=
      m_ExtraIngredientSet.end())

    {
      return false;
    }
  }

  switch (extraIngredient)
  {
  case Ingredient::Milk:
    if (m_ExtraIngredientSet.find(Ingredient::SoyMilk) !=
      m_ExtraIngredientSet.end() ||
      m_ExtraIngredientSet.find(Ingredient::Cream) !=
      m_ExtraIngredientSet.end())
    {
      return false;
    }
    break;

  case Ingredient::SoyMilk:
    if (m_ExtraIngredientSet.find(Ingredient::Milk) !=
      m_ExtraIngredientSet.end() ||
      m_ExtraIngredientSet.find(Ingredient::Cream) !=
      m_ExtraIngredientSet.end())
    {
      return false;
    }
    break;

  case Ingredient::Cream:
    if (m_ExtraIngredientSet.find(Ingredient::Milk) !=
      m_ExtraIngredientSet.end() ||
      m_ExtraIngredientSet.find(Ingredient::SoyMilk) !=
      m_ExtraIngredientSet.end())
    {
      return false;
    }
    break;
  }

  m_ExtraIngredientSet.insert(extraIngredient);

  return true;
}
*/