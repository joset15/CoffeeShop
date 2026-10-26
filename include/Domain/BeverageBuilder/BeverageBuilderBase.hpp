#ifndef BEVERAGE_BUILDER_BASE_HPP
#define BEVERAGE_BUILDER_BASE_HPP

#include "IBeverageBuilder.hpp"

#include "Domain/BeverageFactories/IBeverageFactory.hpp"
#include "Domain/BeverageFactories/IIngredientFactory.hpp"
#include "Domain/Beverages/BeverageVariety.hpp"

#include <memory>
#include <utility>

namespace coffee_shop::domain
{
/// @brief Common state and helpers for the concrete beverage builders.
class BeverageBuilderBase : public IBeverageBuilder
{
public:
  /// @brief Takes the built beverage and resets the builder.
  /// @return The beverage. The caller becomes its owner.
  std::unique_ptr<IBeverage> takeBeverage() final
  {
    auto beverage = std::move(m_Beverage);
    reset();
    return beverage;
  }

protected:
  /// @brief Stores the factories used to build the beverage.
  /// @param beverageFactory Creates the base beverages (not owned; must
  /// outlive the builder).
  /// @param ingredientFactory Creates the ingredient decorators (not owned;
  /// must outlive the builder).
  BeverageBuilderBase(IBeverageFactory &beverageFactory,
                      IIngredientFactory &ingredientFactory)
      : m_BeverageFactory(&beverageFactory),
        m_IngredientFactory(&ingredientFactory)
  {
  }

  /// @brief Starts a new beverage, discarding the one being built.
  /// @param beverageVariety The base beverage to create.
  void setBaseBeverage(BeverageVariety beverageVariety)
  {
    m_Beverage = m_BeverageFactory->createBeverage(beverageVariety);
  }

  /// @brief Wraps the beverage being built with an ingredient decorator.
  /// @param ingredient The ingredient to add.
  void decorateWith(Ingredient ingredient)
  {
    m_Beverage =
        m_IngredientFactory->createIngredient(ingredient, std::move(m_Beverage));
  }

private:
  /// @brief The beverage that will be built.
  std::unique_ptr<IBeverage> m_Beverage;

  /// @brief The factory that creates base beverages (not owned, never null).
  IBeverageFactory *m_BeverageFactory;

  /// @brief The factory that creates ingredient decorators (not owned, never
  /// null).
  IIngredientFactory *m_IngredientFactory;
};
} // namespace coffee_shop::domain

#endif // BEVERAGE_BUILDER_BASE_HPP
