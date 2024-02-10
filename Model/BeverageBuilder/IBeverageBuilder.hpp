#ifndef IBEVERAGE_BUILDER_HPP
#define IBEVERAGE_BUILDER_HPP
#pragma once

#include "../Beverages/IBeverage.hpp"
#include "../Ingredient/Ingredients.hpp"

#include <memory>

class IBeverageBuilder
{
public:
  virtual ~IBeverageBuilder() = default;

  /// @brief Gets the beverage.
  /// @return A pointer to the beverage.
  virtual std::shared_ptr<IBeverage> getBeverage() = 0;

  /// @brief
  virtual void reset() = 0;

  /// @brief Adds sugar to the beverage.
  virtual bool addSugar() = 0;

  /// @brief Adds milk to the beverage.
  /// @param typeOfMilk The type of milk we are adding.
  virtual bool addMilk(Ingredient typeOfMilk) = 0;

  /// @brief Adds honey to the beverage.
  virtual bool addHoney() = 0;

  /// @brief Adds lemon to the beverage.
  virtual bool addLemon() = 0;

  /// @brief Adds Water to the beverage.
  virtual bool addWater() = 0;

protected:
  std::shared_ptr<IBeverage> m_Beverage;
};

#endif // IBEVERAGE_BUILDER_HPP