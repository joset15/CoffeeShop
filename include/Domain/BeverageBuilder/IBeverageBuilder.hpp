#ifndef IBEVERAGE_BUILDER_HPP
#define IBEVERAGE_BUILDER_HPP
//#pragma once

#include "Domain/Beverages/IBeverage.hpp"
#include "Domain/Ingredients/Ingredients.hpp"

#include "Domain/BeverageFactories/IBeverageFactory.hpp"
#include "Domain/BeverageFactories/IIngredientFactory.hpp"

#include <memory>
#include <utility>

class IBeverageBuilder
{
public:
  /// @brief
  /// @param beverageFactory
  /// @param ingredientFactory
  IBeverageBuilder(IBeverageFactory *beverageFactory,
                   IIngredientFactory *ingredientFactory)
      : m_BeverageFactory(beverageFactory),
        m_IngredientFactory(ingredientFactory){};

  /// @brief
  virtual ~IBeverageBuilder() = default;

  /// @brief Takes the built beverage and resets the builder.
  /// @return The beverage. The caller becomes its owner.
  virtual std::unique_ptr<IBeverage> takeBeverage() = 0;

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
  /// @brief Wraps the beverage being built with an ingredient decorator.
  /// @param ingredient The ingredient to add.
  void decorateWith(Ingredient ingredient)
  {
    m_Beverage =
        m_IngredientFactory->createIngredient(ingredient, std::move(m_Beverage));
  }

  /// @brief The beverage that will be built.
  std::unique_ptr<IBeverage> m_Beverage;

  /// @brief A reference to the beverage factory.
  IBeverageFactory *m_BeverageFactory = nullptr;

  /// @brief
  IIngredientFactory *m_IngredientFactory = nullptr;
};

#endif // IBEVERAGE_BUILDER_HPP