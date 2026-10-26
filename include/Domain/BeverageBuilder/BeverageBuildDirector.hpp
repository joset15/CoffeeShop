#ifndef BEVERAGE_BUILD_DIRECTOR_HPP
#define BEVERAGE_BUILD_DIRECTOR_HPP

#include "Domain/Ingredients/Ingredients.hpp"
#include "IBeverageBuilder.hpp"

#include <vector>

namespace coffee_shop::domain
{
/// @brief Builds a beverage with a builder, adding the requested ingredients
/// in a fixed order (Builder pattern director).
class BeverageBuildDirector
{
public:
  /// @brief Creates a director that builds with the given builder.
  /// @param beverageBuilder The builder to use. It isn't owned and must
  /// outlive the director.
  explicit BeverageBuildDirector(IBeverageBuilder &beverageBuilder)
      : m_BeverageBuilder(&beverageBuilder)
  {
  }

  /// @brief Builds a beverage with the builder. The builder decides which
  /// beverage it is; take it with IBeverageBuilder::takeBeverage().
  /// @param ingredients The requested ingredients.
  /// @return False if an ingredient can't be added (e.g. water, lemon in
  /// cocoa, milk in a latte, or two kinds of milk).
  bool buildBeverage(const std::vector<Ingredient> &ingredients);

private:
  bool addSugar(const std::vector<Ingredient> &ingredients);

  bool addMilk(const std::vector<Ingredient> &ingredients);

  bool addHoney(const std::vector<Ingredient> &ingredients);

  bool addLemon(const std::vector<Ingredient> &ingredients);

  bool addWater(const std::vector<Ingredient> &ingredients);

  static bool hasSeveralMilks(const std::vector<Ingredient> &ingredients);

  static bool find(const std::vector<Ingredient> &ingredients,
                   Ingredient ingredient);

  /// @brief The builder (not owned, never null: set from a reference).
  IBeverageBuilder *m_BeverageBuilder;
};
} // namespace coffee_shop::domain

#endif // BEVERAGE_BUILD_DIRECTOR_HPP