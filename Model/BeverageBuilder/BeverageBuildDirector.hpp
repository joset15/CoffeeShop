#ifndef BEVERAGE_BUILD_DIRECTOR_HPP
#define BEVERAGE_BUILD_DIRECTOR_HPP
#pragma once

#include "../Ingredient/Ingredients.hpp"
#include "IBeverageBuilder.hpp"

#include <memory>

class BeverageBuildDirector
{
public:
  // BeverageBuildDirector() = delete;

  void setBuilder(std::shared_ptr<IBeverageBuilder> beverageBuilder)
  {
    m_BeverageBuilder = beverageBuilder;
  }

  void buildCoffee(const std::list<Ingredient> &ingredients);

  void buildTea(const std::list<Ingredient> &ingredients);

private:
  void addSugar(const std::list<Ingredient> &ingredients);

  void addMilk(const std::list<Ingredient> &ingredients);

  void addHoney(const std::list<Ingredient> &ingredients);

  void addLemon(const std::list<Ingredient> &ingredients);

  std::shared_ptr<IBeverageBuilder> m_BeverageBuilder;
};

#endif // BEVERAGE_BUILD_DIRECTOR_HPP