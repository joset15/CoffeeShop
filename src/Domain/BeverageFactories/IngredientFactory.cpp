#include "Domain/BeverageFactories/IngredientFactory.hpp"
#include <cassert>
#include <utility>

std::unique_ptr<IBeverage>
IngredientFactory::createIngredient(Ingredient ingredient,
                                    std::unique_ptr<IBeverage> beverage)
{
  std::unique_ptr<IBeverage> newIngredient = nullptr;

  switch (ingredient)
  {
  case Ingredient::Sugar:
    newIngredient = std::make_unique<Sugar>(std::move(beverage));
    break;
  case Ingredient::Milk:
    newIngredient = std::make_unique<Milk>(std::move(beverage));
    break;
  case Ingredient::Cream:
    newIngredient = std::make_unique<Cream>(std::move(beverage));
    break;
  case Ingredient::Honey:
    newIngredient = std::make_unique<Honey>(std::move(beverage));
    break;
  case Ingredient::Lemon:
    newIngredient = std::make_unique<Lemon>(std::move(beverage));
    break;
  case Ingredient::SoyMilk:
    newIngredient = std::make_unique<SoyMilk>(std::move(beverage));
    break;
  case Ingredient::Water:
    newIngredient = std::make_unique<Water>(std::move(beverage));
    break;
  default:
    assert(false && "Unexpected beverageType");
    break;
  }

  return newIngredient;
}
