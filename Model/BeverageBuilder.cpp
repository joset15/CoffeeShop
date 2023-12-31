#include "BeverageBuilder.hpp"
#include "BeverageFactory.hpp"

std::shared_ptr<IBeverage>
BeverageBuilder::getBeverage(IBeverage::BeverageType beverageType,
                             BeverageVariety beverageVariety,
                             Ingredient extraIngredient)
{
  std::shared_ptr<IBeverage> newBeverage =
      BeverageFactory::getInstance()->createBeverage(beverageType,
                                                     beverageVariety);

  if (newBeverage == nullptr)
  {
    return nullptr;
  }

  if (!newBeverage->addExtraIngredient(extraIngredient))
  {
    return nullptr;
  }

  return newBeverage;
};
