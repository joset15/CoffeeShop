#ifndef BEVERAGE_BUILD_DIRECTOR_HPP
#define BEVERAGE_BUILD_DIRECTOR_HPP

#include "Domain/Ingredients/Ingredients.hpp"
#include "IBeverageBuilder.hpp"

#include <list>
#include <memory>

namespace coffee_shop::domain
{
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

  /// @brief Builds a beverage with the builder set by setBuilder(). The
  /// builder decides which beverage it is.
  /// @param ingredients The requested ingredients.
  /// @return False if there is no builder or an ingredient can't be added
  /// (e.g. water, lemon in cocoa, milk in a latte, or two kinds of milk).
  bool buildBeverage(const std::list<Ingredient> &ingredients);

private:
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
} // namespace coffee_shop::domain

#endif // BEVERAGE_BUILD_DIRECTOR_HPP