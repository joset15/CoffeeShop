#include "BeverageBuildDirector.hpp"

void BeverageBuildDirector::buildCoffee(
    const std::list<Ingredient> &ingredients)
{
  addSugar(ingredients);
  addMilk(ingredients);
}

void BeverageBuildDirector::buildTea(const std::list<Ingredient> &ingredients)
{
  addSugar(ingredients);
  addMilk(ingredients);
  addHoney(ingredients);
  addLemon(ingredients);
}

bool BeverageBuildDirector::find(const std::list<Ingredient> &ingredients,
                                 Ingredient ingredient)
{
  return (std::find(ingredients.begin(), ingredients.end(), ingredient) !=
          ingredients.end());
}

void BeverageBuildDirector::addSugar(const std::list<Ingredient> &ingredients)
{
  if (find(ingredients, Ingredient::Sugar))
  {
    m_BeverageBuilder->addSugar();
  }
}

void BeverageBuildDirector::addMilk(const std::list<Ingredient> &ingredients)
{
  if (find(ingredients, Ingredient::Milk))
  {
    m_BeverageBuilder->addMilk(Ingredient::Milk);
  }
  else if (find(ingredients, Ingredient::SoyMilk))
  {
    m_BeverageBuilder->addMilk(Ingredient::SoyMilk);
  }
  else if (find(ingredients, Ingredient::Cream))
  {
    m_BeverageBuilder->addMilk(Ingredient::Cream);
  }
}

void BeverageBuildDirector::addHoney(const std::list<Ingredient> &ingredients)
{
  if (find(ingredients, Ingredient::Honey))
  {
    m_BeverageBuilder->addHoney();
  }
}

void BeverageBuildDirector::addLemon(const std::list<Ingredient> &ingredients)
{
  if (find(ingredients, Ingredient::Lemon))
  {
    m_BeverageBuilder->addLemon();
  }
}
