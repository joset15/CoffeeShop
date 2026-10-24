#ifndef COFFEE_BUILDER_HPP
#define COFFEE_BUILDER_HPP
#pragma once

#include "BeverageBuilderBase.hpp"

class CoffeeBuilder : public BeverageBuilderBase
{
public:
  /// @brief
  void reset() override { resetImpl(); };

  /// @brief Adds sugar to the beverage.
  /// @return
  bool addSugar() override;

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

protected:
  CoffeeBuilder(IBeverageFactory *beverageFactory,
                IIngredientFactory *ingredientFactory)
      : BeverageBuilderBase(beverageFactory, ingredientFactory)
  {
    resetImpl();
  }

  void resetImpl();

private:
  /// @brief True if the beverage has milk.
  bool m_HasMilk = false;
};

#endif // COFFEEBUILDER_HPP
