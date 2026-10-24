#ifndef COCOA_BUILDER_HPP
#define COCOA_BUILDER_HPP
#pragma once

//#include "../Beverages/Cocoa.hpp"
#include "IBeverageBuilder.hpp"

class CocoaBuilder : public IBeverageBuilder
{
public:
  CocoaBuilder(IBeverageFactory *beverageFactory,
               IIngredientFactory *ingredientFactory)
      : IBeverageBuilder(beverageFactory, ingredientFactory)
  {
    resetImpl();
  }

  /// @brief Takes the built beverage and resets the builder.
  /// @return The beverage. The caller becomes its owner.
  std::unique_ptr<IBeverage> takeBeverage() override
  {
    auto beverage = std::move(m_Beverage);
    reset();
    return beverage;
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