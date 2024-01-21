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

  /// @brief Gets the beverage.
  /// @return A pointer to the beverage.
  std::shared_ptr<IBeverage> getBeverage() override { return m_Beverage; };

  /// @brief
  void reset() override
  {
    m_Beverage = std::make_shared<Coffee>();
    m_HasMilk = false;
  }

  /// @brief Adds sugar to the beverage.
  void addSugar() override
  {
    m_Beverage = std::make_shared<Sugar>(m_Beverage);
  };

  /// @brief Adds milk to the beverage.
  /// @param typeOfMilk The type of milk we are adding.
  void addMilk(Ingredient typeOfMilk) override;

  /// @brief Adds honey to the beverage.
  void addHoney() override{};

  /// @brief Adds lemon to the beverage.
  void addLemon() override{};

private:
  bool m_HasMilk = false;
};

#endif // COFFEEBUILDER_HPP