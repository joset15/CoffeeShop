#ifndef TEA_BUILDER_HPP
#define TEA_BUILDER_HPP

#include "BeverageBuilderBase.hpp"

class TeaBuilder : public BeverageBuilderBase
{
public:
  /// @brief Starts a new beverage, discarding the one being built.
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
  /// @brief Only concrete teas (e.g. TeaBlackBuilder) create the base beverage.
  TeaBuilder(IBeverageFactory *beverageFactory,
             IIngredientFactory *ingredientFactory)
      : BeverageBuilderBase(beverageFactory, ingredientFactory)
  {
    resetImpl();
  }

  /// @brief Reset the internal variable status (Milk, Lemon).
  void resetImpl();

private:
  /// @brief True once a kind of milk has been added.
  bool m_HasMilk = false;

  /// @brief True once lemon has been added.
  bool m_HasLemon = false;
};

#endif // TEA_BUILDER_HPP