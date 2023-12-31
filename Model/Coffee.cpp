#include "Coffee.hpp"

#include <stdexcept>


Coffee::Coffee(BeverageVariety beverageVariety) : IBeverage(beverageVariety)
{
  if (beverageVariety != BeverageVariety::CoffeeLatte &&
    beverageVariety != BeverageVariety::CoffeeEspresso &&
    beverageVariety != BeverageVariety::CoffeeDecaf)
  {
    throw std::runtime_error("Invalid main ingredient for Coffee");
  }
}

bool Coffee::addExtraIngredient(Ingredient extraIngredient)
{
  if (extraIngredient == Ingredient::Honey ||
    extraIngredient == Ingredient::Lemon)
  {
    return false;
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

std::string Coffee::description() const
{
  std::string description;
  switch (m_BeverageVariety)
  {
  case BeverageVariety::CoffeeEspresso:
    description = "Coffee Expresso";
    break;

  case BeverageVariety::CoffeeLatte:
    description = "Coffee Latte";
    break;

  case BeverageVariety::CoffeeDecaf:
    description = "Coffee Decaf";
    break;

  default:
    description = "Coffee unknown";
  }

  /// \brief
  if (m_ExtraIngredientSet.size() > 0)
  {
    description = description + ". Extra ingredients: ";

    std::unordered_set<Ingredient>::iterator it;
    for (it = m_ExtraIngredientSet.begin(); it != m_ExtraIngredientSet.end();
      ++it)
    {
      Ingredient ing = *it;

      switch (ing)
      {
      case Ingredient::Sugar:
        description = description + " sugar";
        break;
      default:
        description = description + " unexpected ingredient";
        break;
      }
    }
  }

  return description;
}
