#ifndef BEVERAGE_BUILD_DIRECTOR_HPP
#define BEVERAGE_BUILD_DIRECTOR_HPP
#pragma once

#include "../Ingredient/Ingredients.hpp"
#include "IBeverageBuilder.hpp"

#include <list>
#include <memory>

class BeverageBuildDirector
{
public:
  void setBuilder(const std::shared_ptr<IBeverageBuilder> &beverageBuilder)
  {
    m_BeverageBuilder = beverageBuilder;
  }

  bool buildBeverage(BeverageVariety beverageVariety,
                     const std::list<Ingredient> &ingredients);

  bool buildCoffeeEspresso(const std::list<Ingredient> &ingredients);

  bool buildTeaBlack(const std::list<Ingredient> &ingredients);

private:
  bool buildCoffee(const std::list<Ingredient> &ingredients);

  bool buildTea(const std::list<Ingredient> &ingredients);

  bool addSugar(const std::list<Ingredient> &ingredients);

  bool addMilk(const std::list<Ingredient> &ingredients);

  bool addHoney(const std::list<Ingredient> &ingredients);

  bool addLemon(const std::list<Ingredient> &ingredients);

  static bool find(const std::list<Ingredient> &ingredients,
                   Ingredient ingredient);

  std::shared_ptr<IBeverageBuilder> m_BeverageBuilder;
};

#endif // BEVERAGE_BUILD_DIRECTOR_HPP