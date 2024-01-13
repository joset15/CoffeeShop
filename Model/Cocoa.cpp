#include "Cocoa.hpp"

#include <stdexcept>

//Cocoa::Cocoa(BeverageVariety beverageVariety) : IBeverage(beverageVariety)
Cocoa::Cocoa() : IBeverage()
{
  /*
  if (beverageVariety != BeverageVariety::CocoaMilk &&
      beverageVariety != BeverageVariety::CocoaSoyMilk &&
      beverageVariety != BeverageVariety::CocoaWater)
  {
    throw std::runtime_error("Invalid main ingredient for Cocoa");
  }*/
}

/*
bool Cocoa::addExtraIngredient(Ingredient extraIngredient)
{

  // No need to check m_ExtraIngredientMap[Ingredient::Sugar]
  if (extraIngredient != Ingredient::Sugar)
  {
    return false;
  }

  m_ExtraIngredientSet.insert(extraIngredient);

  return true;
}
*/
