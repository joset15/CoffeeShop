#include "Domain/BeverageFactories/IngredientFactory.hpp"
#include <assert.h>

std::shared_ptr<IBeverage>
IngredientFactory::createIngredient(Ingredient ingredient,
                                    std::shared_ptr<IBeverage> beverage)
{
  std::shared_ptr<IBeverage> newIngredient = nullptr;

  switch (ingredient)
  {
  case Ingredient::Sugar:
    newIngredient = std::make_shared<Sugar>(beverage);
    break;
  case Ingredient::Milk:
    newIngredient = std::make_shared<Milk>(beverage);
    break;
  case Ingredient::Cream:
    newIngredient = std::make_shared<Cream>(beverage);
    break;
  case Ingredient::Honey:
    newIngredient = std::make_shared<Honey>(beverage);
    break;
  case Ingredient::Lemon:
    newIngredient = std::make_shared<Lemon>(beverage);
    break;
  case Ingredient::SoyMilk:
    newIngredient = std::make_shared<SoyMilk>(beverage);
    break;
  case Ingredient::Water:
    newIngredient = std::make_shared<Water>(beverage);
    break;
  default:
    assert(false && "Unexpected beverageType");
    break;
  }

  return newIngredient;
}