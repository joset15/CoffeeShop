#ifndef COFFEE_BUILDER_HPP
#define COFFEE_BUILDER_HPP
#pragma once

#include "../Coffee.hpp"
#include "IBeverageBuilder.hpp"

#include "../Ingredient/Ingredients.hpp"

#include <assert.h>

class CoffeeBuilder : public IBeverageBuilder
{
public:
  CoffeeBuilder() { reset(); }

  //~CoffeeBuilder() { m_Beverage.reset(); };

  /// @brief Gets the beverage.
  /// @return A pointer to the beverage.
  std::shared_ptr<IBeverage> getBeverage() override { return m_Beverage; };

  /// @brief
  void reset() override { m_Beverage = std::make_shared<Coffee>(); }

  /// @brief Adds sugar to the beverage.
  void addSugar() override
  {
    m_Beverage = std::make_shared<Sugar>(m_Beverage);
  };

  /// @brief Adds milk to the beverage.
  /// @param typeOfMilk The type of milk we are adding.
  void addMilk(Ingredient typeOfMilk) override
  {
    switch (typeOfMilk)
    {
    case Ingredient::Milk:
      m_Beverage = std::make_shared<Milk>(m_Beverage);
      break;
    case Ingredient::Cream:
      m_Beverage = std::make_shared<Cream>(m_Beverage);
      break;
    case Ingredient::SoyMilk:
      m_Beverage = std::make_shared<SoyMilk>(m_Beverage);
      break;
    default:
      assert(false && "Invalid type of milk");
    }
  };

  /// @brief Adds honey to the beverage.
  void addHoney() override{};

  /// @brief Adds lemon to the beverage.
  void addLemon() override{};
};

#endif // COFFEEBUILDER_HPP