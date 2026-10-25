#ifndef IBEVERAGE_BUILDER_FACTORY_HPP
#define IBEVERAGE_BUILDER_FACTORY_HPP

#include "../BeverageBuilder/BeverageBuilder.hpp"
#include "../Beverages/BeverageVariety.hpp"
#include "../Beverages/IBeverage.hpp"
#include "IBeverageFactory.hpp"
#include "IIngredientFactory.hpp"
#include <memory>

/// @brief Creates the builder for each beverage variety.
class IBeverageBuilderFactory
{
public:
  /// @brief Allows deleting an implementation through this interface.
  virtual ~IBeverageBuilderFactory() = default;

  /// @brief Creates the builder for a beverage variety.
  /// @param beverageVariety The variety to build.
  /// @return The builder.
  virtual std::shared_ptr<IBeverageBuilder>
  createBeverageBuilder(BeverageVariety beverageVariety) = 0;
};

#endif // IBEVERAGE_BUILDER_FACTORY_HPP
