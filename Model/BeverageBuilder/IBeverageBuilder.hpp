#ifndef IBEVERAGE_BUILDER_HPP
#define IBEVERAGE_BUILDER_HPP
#pragma once

#include "../IBeverage.hpp"
#include "../Ingredient/Ingredients.hpp"

#include <memory>

class IBeverageBuilder
{
public:
  virtual ~IBeverageBuilder(){};

  /// @brief Gets the beverage.
  /// @return A pointer to the beverage.
  virtual std::shared_ptr<IBeverage> getBeverage() = 0;

  /// @brief
  virtual void reset() = 0;

  /// @brief Adds sugar to the beverage.
  virtual void addSugar() = 0;

  /// @brief Adds milk to the beverage.
  /// @param typeOfMilk The type of milk we are adding.
  virtual void addMilk(Ingredient typeOfMilk) = 0;

  /// @brief Adds honey to the beverage.
  virtual void addHoney() = 0;

  /// @brief Adds lemon to the beverage.
  virtual void addLemon() = 0;

protected:
  std::shared_ptr<IBeverage> m_Beverage;
};

#endif // IBEVERAGE_BUILDER_HPP