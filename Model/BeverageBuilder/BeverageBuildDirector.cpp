#include "BeverageBuildDirector.hpp"

void BeverageBuildDirector::buildCoffee(
    const std::list<Ingredient> &ingredients)
{
  // m_BeverageBuilder.reset();

  addSugar(ingredients);
  addMilk(ingredients);
}

void BeverageBuildDirector::buildTea(const std::list<Ingredient> &ingredients)
{
  // m_BeverageBuilder.reset();

  addSugar(ingredients);
  addMilk(ingredients);
  addHoney(ingredients);
  addLemon(ingredients);
}

void BeverageBuildDirector::addSugar(const std::list<Ingredient> &ingredients)
{
  if (std::find(ingredients.begin(), ingredients.end(), Ingredient::Sugar) !=
      ingredients.end())
  {
    m_BeverageBuilder->addSugar();
  }
}

void BeverageBuildDirector::addMilk(const std::list<Ingredient> &ingredients)
{
  if (std::find(ingredients.begin(), ingredients.end(), Ingredient::Milk) !=
      ingredients.end())
  {
    m_BeverageBuilder->addMilk(Ingredient::Milk);
  }
  else if (std::find(ingredients.begin(), ingredients.end(),
                     Ingredient::SoyMilk) != ingredients.end())
  {
    m_BeverageBuilder->addMilk(Ingredient::SoyMilk);
  }
  else if (std::find(ingredients.begin(), ingredients.end(),
                     Ingredient::Cream) != ingredients.end())
  {
    m_BeverageBuilder->addMilk(Ingredient::Cream);
  }
}

void BeverageBuildDirector::addHoney(const std::list<Ingredient> &ingredients)
{
  if (std::find(ingredients.begin(), ingredients.end(), Ingredient::Honey) !=
      ingredients.end())
  {
    m_BeverageBuilder->addHoney();
  }
}

void BeverageBuildDirector::addLemon(const std::list<Ingredient> &ingredients)
{
  if (std::find(ingredients.begin(), ingredients.end(), Ingredient::Lemon) !=
      ingredients.end())
  {
    m_BeverageBuilder->addLemon();
  }
}
