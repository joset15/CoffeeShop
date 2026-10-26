#include "Domain/BeverageFactories/IngredientFactory.hpp"
#include "Domain/Beverages/IBeverage.hpp"
#include "Domain/Ingredients/Cream.hpp"
#include "Domain/Ingredients/Honey.hpp"
#include "Domain/Ingredients/Ingredient.hpp"
#include "Domain/Ingredients/Lemon.hpp"
#include "Domain/Ingredients/Milk.hpp"
#include "Domain/Ingredients/SoyMilk.hpp"
#include "Domain/Ingredients/Sugar.hpp"
#include "Domain/Ingredients/Water.hpp"
#include <memory>
#include <utility>

namespace coffee_shop::domain
{
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
  }

  return newIngredient;
}
} // namespace coffee_shop::domain
