#include "Domain/BeverageBuilder/BeverageBuildDirector.hpp"

#include <algorithm>

bool BeverageBuildDirector::buildBeverage(
    const std::list<Ingredient> &ingredients)
{
  if (!m_BeverageBuilder || hasSeveralMilks(ingredients))
  {
    return false;
  }

  // Each step returns false if the builder rejects that ingredient.
  return addSugar(ingredients) && addMilk(ingredients) &&
         addHoney(ingredients) && addLemon(ingredients) &&
         addWater(ingredients);
}

bool BeverageBuildDirector::hasSeveralMilks(
    const std::list<Ingredient> &ingredients)
{
  const int kindsOfMilk =
      static_cast<int>(find(ingredients, Ingredient::Milk)) +
      static_cast<int>(find(ingredients, Ingredient::SoyMilk)) +
      static_cast<int>(find(ingredients, Ingredient::Cream));
  return kindsOfMilk > 1;
}

bool BeverageBuildDirector::find(const std::list<Ingredient> &ingredients,
                                 Ingredient ingredient)
{
  return (std::find(ingredients.begin(), ingredients.end(), ingredient) !=
          ingredients.end());
}

bool BeverageBuildDirector::addSugar(const std::list<Ingredient> &ingredients)
{
  if (find(ingredients, Ingredient::Sugar))
  {
    return m_BeverageBuilder->addSugar();
  }

  return true;
}

bool BeverageBuildDirector::addMilk(const std::list<Ingredient> &ingredients)
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

bool BeverageBuildDirector::addHoney(const std::list<Ingredient> &ingredients)
{
  if (find(ingredients, Ingredient::Honey))
  {
    return m_BeverageBuilder->addHoney();
  }

  return true;
}

bool BeverageBuildDirector::addLemon(const std::list<Ingredient> &ingredients)
{
  if (find(ingredients, Ingredient::Lemon))
  {
    return m_BeverageBuilder->addLemon();
  }

  return true;
}

bool BeverageBuildDirector::addWater(const std::list<Ingredient> &ingredients)
{
  if (find(ingredients, Ingredient::Water))
  {
    return m_BeverageBuilder->addWater();
  }

  return true;
}
