#ifndef BEVERAGE_BUILDER_HPP
#define BEVERAGE_BUILDER_HPP

#include "Beverages/BeverageVariety.hpp"
#include "Beverages/IBeverage.hpp"
#include "Ingredient/IngredientDecorator.hpp"

#include <memory>

// TODO Refactor

class BeverageBuilder
{
public:
  BeverageBuilder() = default;

  /// \brief
  static BeverageBuilder *getInstance()
  {
    static BeverageBuilder m_BeverageBuilderInstance;
    return &m_BeverageBuilderInstance;
  }

  std::shared_ptr<IBeverage>
  getBeverage(IBeverage::BeverageType beverageType,
              BeverageVariety beverageVariety,
              // IngredientDecorator extraIngredient);
              IngredientDecorator *extraIngredient);
};

#endif // BEVERAGE_BUILDER_HPP
