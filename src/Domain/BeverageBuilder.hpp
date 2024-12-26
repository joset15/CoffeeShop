#ifndef BEVERAGE_BUILDER_HPP
#define BEVERAGE_BUILDER_HPP

#include "Domain/Beverages/BeverageVariety.hpp"
#include "Domain/Beverages/IBeverage.hpp"
#include "Domain/Ingredients/IngredientDecorator.hpp"

#include <memory>

// TODO Refactor

class BeverageBuilder final
{
public:
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

private:
  BeverageBuilder() = default;
  ~BeverageBuilder() = default;

  BeverageBuilder(const BeverageBuilder &) = delete;
  BeverageBuilder &operator=(const BeverageBuilder &) = delete;

  BeverageBuilder(BeverageBuilder &&) = delete;
  BeverageBuilder &operator=(BeverageBuilder &&) = delete;
};

#endif // BEVERAGE_BUILDER_HPP
