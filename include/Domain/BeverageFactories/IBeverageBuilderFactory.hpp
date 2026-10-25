#ifndef IBEVERAGE_BUILDER_FACTORY_HPP
#define IBEVERAGE_BUILDER_FACTORY_HPP

#include "../BeverageBuilder/BeverageBuilder.hpp"
#include "../Beverages/BeverageVariety.hpp"
#include "../Beverages/IBeverage.hpp"
#include "IBeverageFactory.hpp"
#include "IIngredientFactory.hpp"
#include <memory>

// TODO Complete doxygen comments.

/// @brief The IBeverageBuilderFactory class
class IBeverageBuilderFactory
{
public:
  /// @brief
  virtual ~IBeverageBuilderFactory() = default;

  /// @brief
  /// @param beverageVariety
  /// @return
  virtual std::shared_ptr<IBeverageBuilder>
  createBeverageBuilder(BeverageVariety beverageVariety) = 0;
};

#endif // IBEVERAGE_BUILDER_FACTORY_HPP
