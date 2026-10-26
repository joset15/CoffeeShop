#ifndef BEVERAGE_BUILDER_SIMPLE_FACTORY_HPP
#define BEVERAGE_BUILDER_SIMPLE_FACTORY_HPP

#include "Domain/BeverageFactories/IBeverageBuilderFactory.hpp"
#include "Domain/BeverageFactories/IBeverageFactory.hpp"
#include "Domain/BeverageFactories/IIngredientFactory.hpp"
#include "Domain/Beverages/BeverageVariety.hpp"
#include <memory>

namespace coffee_shop::domain
{
/// @brief Creates the builder for each beverage variety.
class BeverageBuilderSimpleFactory final : public IBeverageBuilderFactory
{
public:
  /// @brief Creates a factory whose builders use the given factories.
  /// @param beverageFactory Creates the base beverages (not owned; must
  /// outlive this factory and the builders it creates).
  /// @param ingredientFactory Creates the ingredient decorators (not owned;
  /// same lifetime rule).
  BeverageBuilderSimpleFactory(IBeverageFactory &beverageFactory,
                               IIngredientFactory &ingredientFactory)
      : m_BeverageFactory(&beverageFactory),
        m_IngredientFactory(&ingredientFactory)
  {
  }

  /// @brief Creates the builder for a beverage variety.
  /// @param beverageVariety The variety to build.
  /// @return The builder (nullptr only for an invalid BeverageVariety value).
  std::unique_ptr<IBeverageBuilder>
  createBeverageBuilder(BeverageVariety beverageVariety) override;

private:
  /// @brief Creates the base beverages (not owned, never null).
  IBeverageFactory *m_BeverageFactory;

  /// @brief Creates the ingredient decorators (not owned, never null).
  IIngredientFactory *m_IngredientFactory;
};
} // namespace coffee_shop::domain

#endif // BEVERAGE_BUILDER_SIMPLE_FACTORY_HPP
