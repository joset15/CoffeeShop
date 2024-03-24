#include "BeverageBuildDirector.hpp"

bool BeverageBuildDirector::buildBeverage(
    BeverageVariety beverageVariety, const std::list<Ingredient> &ingredients)
{
  bool isValidBeverage = false;

  switch (beverageVariety)
  {
  case BeverageVariety::CoffeeEspresso:
    isValidBeverage = buildCoffeeEspresso(ingredients);
    break;
  case BeverageVariety::CoffeeLatte:
    // TODO add build.
    break;
  case BeverageVariety::CoffeeDecaf:
    // TODO add build.
    break;
  case BeverageVariety::TeaBlack:
    isValidBeverage = buildTeaBlack(ingredients);
    break;
  case BeverageVariety::TeaGreen:
    // TODO add build.
    break;
  case BeverageVariety::Cocoa:
    // TODO add build.
    break;
  default:
    isValidBeverage = false;
    break;
  }

  return isValidBeverage;
}

bool BeverageBuildDirector::buildCoffee(
    const std::list<Ingredient> &ingredients)
{
  if (!addSugar(ingredients))
  {
    return false;
  }

  if (!addMilk(ingredients))
  {
    return false;
  }

  if (!addHoney(ingredients))
  {
    return false;
  }

  if (!addLemon(ingredients))
  {
    return false;
  }

  return true;
}

bool BeverageBuildDirector::buildCoffeeEspresso(
    const std::list<Ingredient> &ingredients)
{
  return buildCoffee(ingredients);
}

bool BeverageBuildDirector::buildTea(const std::list<Ingredient> &ingredients)
{
  if (!addSugar(ingredients))
  {
    return false;
  }

  if (!addMilk(ingredients))
  {
    return false;
  }

  if (!addHoney(ingredients))
  {
    return false;
  }

  if (!addLemon(ingredients))
  {
    return false;
  }

  return true;
}

bool BeverageBuildDirector::buildTeaBlack(
    const std::list<Ingredient> &ingredients)
{
  return buildTea(ingredients);
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
  else if (find(ingredients, Ingredient::SoyMilk))
  {
    return m_BeverageBuilder->addMilk(Ingredient::SoyMilk);
  }
  else if (find(ingredients, Ingredient::Cream))
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
