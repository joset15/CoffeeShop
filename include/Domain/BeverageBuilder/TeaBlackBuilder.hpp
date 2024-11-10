#ifndef TEA_BLACK_BUILDER_HPP
#define TEA_BLACK_BUILDER_HPP
#pragma once

#include "TeaBuilder.hpp"

class TeaBlackBuilder : public TeaBuilder
{
public:
  TeaBlackBuilder(IBeverageFactory *beverageFactory,
                  IIngredientFactory *ingredientFactory)
      : TeaBuilder(beverageFactory, ingredientFactory)
  {
    resetImpl();
  }

  /// @brief
  void reset() override { resetImpl(); }

protected:
  /// @brief
  void resetImpl();
};

#endif // TEA_BLACK_BUILDER_HPP