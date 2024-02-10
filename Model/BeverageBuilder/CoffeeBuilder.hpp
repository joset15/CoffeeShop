#ifndef COFFEE_BUILDER_HPP
#define COFFEE_BUILDER_HPP
#pragma once

#include "../Beverages/Coffee.hpp"
#include "../Ingredient/Ingredients.hpp"
#include "IBeverageBuilder.hpp"

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
  /// @return
  bool addSugar() override
  {
    m_Beverage = std::make_shared<Sugar>(m_Beverage);
    return true;
  };

  /// @brief Adds milk to the beverage.
  /// @param typeOfMilk The type of milk we are adding.
  /// @return
  bool addMilk(Ingredient typeOfMilk) override;

  /// @brief Adds honey to the beverage.
  bool addHoney() override { return false; }

  /// @brief Adds lemon to the beverage.
  bool addLemon() override { return false; }

  /// @brief Adds water to the beverage.
  bool addWater() override { return false; }

  /// @brief Returns if Milk has been added to the beverage.
  /// @return True if milk was added.
  bool hasMilk() const { return m_HasMilk; }

  /// @brief Sets if milk has been added to the beverage.
  /// @param hasMilk True if milk has been added, False otherwise.
  void setHasMilk(bool hasMilk) { m_HasMilk = hasMilk; }

protected:
  /// @brief True if the beverage has milk.
  bool m_HasMilk = false;
};

#endif // COFFEEBUILDER_HPP