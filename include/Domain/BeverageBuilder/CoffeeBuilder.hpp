#ifndef COFFEE_BUILDER_HPP
#define COFFEE_BUILDER_HPP

#include "Domain/BeverageBuilder/BeverageBuilderBase.hpp"

namespace coffee_shop::domain
{
class CoffeeBuilder : public BeverageBuilderBase
{
public:
  /// @brief Adds sugar to the beverage.
  /// @return Always true.
  bool addSugar() override;

  /// @brief Adds milk to the beverage.
  /// @param typeOfMilk The type of milk we are adding.
  /// @return False if a kind of milk was already added.
  bool addMilk(Ingredient typeOfMilk) override;

  /// @brief Adds honey to the beverage.
  bool addHoney() override { return false; }

  /// @brief Adds lemon to the beverage.
  bool addLemon() override { return false; }

  /// @brief Adds water to the beverage.
  bool addWater() override { return false; }

protected:
  CoffeeBuilder(IBeverageFactory &beverageFactory,
                IIngredientFactory &ingredientFactory)
      : BeverageBuilderBase(beverageFactory, ingredientFactory)
  {
    resetState();
  }

  /// @brief Resets the coffee state (no milk yet). Concrete coffees call it
  /// from their own resetImpl().
  void resetState();

private:
  /// @brief True if the beverage has milk.
  bool m_HasMilk = false;
};
} // namespace coffee_shop::domain

#endif // COFFEE_BUILDER_HPP
