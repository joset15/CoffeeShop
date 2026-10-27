#include "Domain/BeverageBuilder/BeverageBuildDirector.hpp"

#include "Domain/Ingredients/Ingredient.hpp"

#include <algorithm>
#include <array>
#include <vector>

namespace coffee_shop::domain
{
bool BeverageBuildDirector::buildBeverage(
    const std::vector<Ingredient> &ingredients)
{
  if (hasSeveralMilks(ingredients))
  {
    return false;
  }

  // Each step returns false if the builder rejects that ingredient.
  return addSugar(ingredients) && addMilk(ingredients) &&
         addHoney(ingredients) && addLemon(ingredients) &&
         addWater(ingredients);
}

bool BeverageBuildDirector::hasSeveralMilks(
    const std::vector<Ingredient> &ingredients)
{
  // Kinds of milk, not occurrences: asking twice for milk is still one kind.
  constexpr std::array KindsOfMilk{Ingredient::Milk, Ingredient::SoyMilk,
                                   Ingredient::Cream};
  return std::ranges::count_if(KindsOfMilk, [&ingredients](Ingredient milk)
                               { return find(ingredients, milk); }) > 1;
}

bool BeverageBuildDirector::find(const std::vector<Ingredient> &ingredients,
                                 Ingredient ingredient)
{
  return std::ranges::find(ingredients, ingredient) != ingredients.end();
}

bool BeverageBuildDirector::addSugar(const std::vector<Ingredient> &ingredients)
{
  if (find(ingredients, Ingredient::Sugar))
  {
    return m_BeverageBuilder->addSugar();
  }

  return true;
}

bool BeverageBuildDirector::addMilk(const std::vector<Ingredient> &ingredients)
{
  if (find(ingredients, Ingredient::Milk))
  {
    return m_BeverageBuilder->addMilk(Ingredient::Milk);
  }

  if (find(ingredients, Ingredient::SoyMilk))
  {
    return m_BeverageBuilder->addMilk(Ingredient::SoyMilk);
  }

  if (find(ingredients, Ingredient::Cream))
  {
    return m_BeverageBuilder->addMilk(Ingredient::Cream);
  }

  return true;
}

bool BeverageBuildDirector::addHoney(const std::vector<Ingredient> &ingredients)
{
  if (find(ingredients, Ingredient::Honey))
  {
    return m_BeverageBuilder->addHoney();
  }

  return true;
}

bool BeverageBuildDirector::addLemon(const std::vector<Ingredient> &ingredients)
{
  if (find(ingredients, Ingredient::Lemon))
  {
    return m_BeverageBuilder->addLemon();
  }

  return true;
}

bool BeverageBuildDirector::addWater(const std::vector<Ingredient> &ingredients)
{
  if (find(ingredients, Ingredient::Water))
  {
    return m_BeverageBuilder->addWater();
  }

  return true;
}
} // namespace coffee_shop::domain
