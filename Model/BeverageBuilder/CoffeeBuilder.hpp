#ifndef COFFEE_BUILDER_HPP
#define COFFEE_BUILDER_HPP
#pragma once

#include "IBeverageBuilder.hpp"

class CoffeeBuilder : public IBeverageBuilder
{
public:
  CoffeeBuilder(IBeverageFactory *beverageFactory,
                IIngredientFactory *ingredientFactory)
      : IBeverageBuilder(beverageFactory, ingredientFactory)
  {
    resetImpl();
  }

  /// @brief Gets the beverage.
  /// @return A pointer to the beverage.
  std::shared_ptr<IBeverage> getBeverage() override { return m_Beverage; };

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

  /// @brief Returns if Milk has been added to the beverage.
  /// @return True if milk was added.
  // bool getHasMilk() const { return m_HasMilk; }

  /// @brief Sets if milk has been added to the beverage.
  /// @param hasMilk True if milk has been added, False otherwise.
  // void setHasMilk(bool hasMilk) { m_HasMilk = hasMilk; }

protected:
  void resetImpl();

private:
  /// @brief True if the beverage has milk.
  bool m_HasMilk = false;
};

#endif // COFFEEBUILDER_HPP