#ifndef TEA_BUILDER_HPP
#define TEA_BUILDER_HPP
#pragma once

#include "IBeverageBuilder.hpp"

class TeaBuilder : public IBeverageBuilder
{
public:
  TeaBuilder(IBeverageFactory *beverageFactory,
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
  bool addSugar() override;

  /// @brief Adds milk to the beverage.
  /// @param typeOfMilk The type of milk we are adding.
  bool addMilk(Ingredient typeOfMilk) override;

  /// @brief Adds honey to the beverage.
  bool addHoney() override;

  /// @brief Adds lemon to the beverage.
  bool addLemon() override;

  /// @brief Adds water to the beverage.
  bool addWater() override { return false; }

protected:
  /// @brief Reset the internal variable status (Milk, Lemon).
  void resetImpl();

private:
  /// @brief
  bool m_HasMilk = false;

  /// @brief
  bool m_HasLemon = false;
};

#endif // TEA_BUILDER_HPP