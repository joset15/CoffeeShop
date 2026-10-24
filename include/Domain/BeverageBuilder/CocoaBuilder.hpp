#ifndef COCOA_BUILDER_HPP
#define COCOA_BUILDER_HPP
#pragma once

//#include "../Beverages/Cocoa.hpp"
#include "BeverageBuilderBase.hpp"

class CocoaBuilder : public BeverageBuilderBase
{
public:
  CocoaBuilder(IBeverageFactory *beverageFactory,
               IIngredientFactory *ingredientFactory)
      : BeverageBuilderBase(beverageFactory, ingredientFactory)
  {
    resetImpl();
  }

  /// @brief
  void reset() override { resetImpl(); }

  /// @brief Adds sugar to the beverage.
  bool addSugar() override
  {
    decorateWith(Ingredient::Sugar);
    return true;
  };

  /// @brief Adds milk to the beverage.
  /// @param typeOfMilk The type of milk we are adding.
  bool addMilk(Ingredient typeOfMilk) override;

  /// @brief Adds honey to the beverage.
  bool addHoney() override
  {
    decorateWith(Ingredient::Honey);
    return true;
  };

  /// @brief Adds lemon to the beverage.
  bool addLemon() override { return false; }

  /// @brief Adds water to the beverage.
  bool addWater() override { return false; }

private:
  /// @brief
  void resetImpl();

  /// @brief
  bool m_HasMilk = false;
};

#endif // COCOA_BUILDER_HPP