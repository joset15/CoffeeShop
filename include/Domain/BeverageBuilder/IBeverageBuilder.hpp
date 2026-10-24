#ifndef IBEVERAGE_BUILDER_HPP
#define IBEVERAGE_BUILDER_HPP

#include "Domain/Beverages/IBeverage.hpp"
#include "Domain/Ingredients/Ingredients.hpp"

#include <memory>

/// @brief Builds a beverage step by step (Builder pattern).
class IBeverageBuilder
{
public:
  /// @brief
  virtual ~IBeverageBuilder() = default;

  /// @brief Takes the built beverage and resets the builder.
  /// @return The beverage. The caller becomes its owner.
  virtual std::unique_ptr<IBeverage> takeBeverage() = 0;

  /// @brief Starts a new beverage, discarding the one being built.
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
};

#endif // IBEVERAGE_BUILDER_HPP
