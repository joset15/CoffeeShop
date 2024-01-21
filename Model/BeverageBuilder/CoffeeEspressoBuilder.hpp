#ifndef COFFEE_ESPRESSO_BUILDER_HPP
#define COFFEE_ESPRESSO_BUILDER_HPP
#pragma once

#include "CoffeeBuilder.hpp"

#include "../Beverages/CoffeeEspresso.hpp"
#include "IBeverageBuilder.hpp"

#include "../Ingredient/Ingredients.hpp"

#include <assert.h>

class CoffeeEspressoBuilder : public CoffeeBuilder
{
public:
  // CoffeeBuilder() { reset(); }
  CoffeeEspressoBuilder() { reset(); }

  /// @brief Gets the beverage.
  /// @return A pointer to the beverage.
  // std::shared_ptr<IBeverage> getBeverage() override { return m_Beverage; };

  /// @brief
  void reset() override
  {
    m_Beverage = std::make_shared<CoffeeEspresso>();
    m_HasMilk = false;
  }

  /// @brief Adds sugar to the beverage.
  /*
  void addSugar() override
  {
    m_Beverage = std::make_shared<Sugar>(m_Beverage);
  };*/

  /// @brief Adds milk to the beverage.
  /// @param typeOfMilk The type of milk we are adding.
  // void addMilk(Ingredient typeOfMilk) override;

  /// @brief Adds honey to the beverage.
  // void addHoney() override{};

  /// @brief Adds lemon to the beverage.
  // void addLemon() override{};

  /// @brief Adds water to the beverage.
  // void addWater() override{};

  // private:
  //  bool m_HasMilk = false;
};

#endif // COFFEE_ESPRESSO_BUILDER_HPP