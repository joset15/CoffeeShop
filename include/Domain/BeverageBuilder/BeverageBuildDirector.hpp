#ifndef BEVERAGE_BUILD_DIRECTOR_HPP
#define BEVERAGE_BUILD_DIRECTOR_HPP
#pragma once

#include "Domain/Beverages/BeverageVariety.hpp"
#include "Domain/Ingredients/Ingredients.hpp"
#include "IBeverageBuilder.hpp"

#include <list>
#include <memory>

/// @brief Builds a beverage with a builder, adding the requested ingredients
/// in a fixed order (Builder pattern director).
class BeverageBuildDirector
{
public:
  /// @brief Sets the builder used by the next build.
  void setBuilder(const std::shared_ptr<IBeverageBuilder> &beverageBuilder)
  {
    m_BeverageBuilder = beverageBuilder;
  }

  /// @brief Builds a beverage of the given variety.
  /// @param beverageVariety The variety; it must match the builder.
  /// @param ingredients The requested ingredients.
  /// @return False if there is no builder, the variety can't be built yet, or
  /// an ingredient can't be added (e.g. water, or two kinds of milk).
  bool buildBeverage(BeverageVariety beverageVariety,
                     const std::list<Ingredient> &ingredients);

  /// @brief Builds an espresso. See buildBeverage().
  bool buildCoffeeEspresso(const std::list<Ingredient> &ingredients);

  /// @brief Builds a black tea. See buildBeverage().
  bool buildTeaBlack(const std::list<Ingredient> &ingredients);

  /// @brief Builds a cocoa. See buildBeverage().
  bool buildCocoa(const std::list<Ingredient> &ingredients);

private:
  bool buildWithIngredients(const std::list<Ingredient> &ingredients);

  bool addSugar(const std::list<Ingredient> &ingredients);

  bool addMilk(const std::list<Ingredient> &ingredients);

  bool addHoney(const std::list<Ingredient> &ingredients);

  bool addLemon(const std::list<Ingredient> &ingredients);

  bool addWater(const std::list<Ingredient> &ingredients);

  static bool hasSeveralMilks(const std::list<Ingredient> &ingredients);

  static bool find(const std::list<Ingredient> &ingredients,
                   Ingredient ingredient);

  std::shared_ptr<IBeverageBuilder> m_BeverageBuilder;
};

#endif // BEVERAGE_BUILD_DIRECTOR_HPP