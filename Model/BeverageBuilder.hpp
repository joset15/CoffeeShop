#ifndef BEVERAGEBUILDER_HPP
#define BEVERAGEBUILDER_HPP

#include "BeverageVariety.hpp"
#include "IBeverage.hpp"
#include "Ingredient/IngredientDecorator.hpp"

#include <memory>

// TODO Refactor

class BeverageBuilder
{
public:
  BeverageBuilder() = default;

  /// \brief
  static BeverageBuilder* getInstance()
  {
    static BeverageBuilder m_BeverageBuilderInstance;
    return &m_BeverageBuilderInstance;
  }

  std::shared_ptr<IBeverage> getBeverage(IBeverage::BeverageType beverageType,
    BeverageVariety beverageVariety,
    //IngredientDecorator extraIngredient);
    IngredientDecorator* extraIngredient);
};

#endif // BEVERAGEBUILDER_HPP
