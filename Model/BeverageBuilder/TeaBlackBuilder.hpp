#ifndef TEA_BLACK_BUILDER_HPP
#define TEA_BLACK_BUILDER_HPP
#pragma once

#include "../Beverages/TeaBlack.hpp"
#include "IBeverageBuilder.hpp"
#include "TeaBuilder.hpp"

#include <assert.h>

class TeaBlackBuilder : public TeaBuilder
{
public:
  TeaBlackBuilder() { resetImpl(); }

  /// @brief
  void reset() override { resetImpl(); }

private:
  /// @brief
  void resetImpl()
  {
    m_Beverage = std::make_shared<TeaBlack>();
    // TODO: TeaBuilder::reset();
    setHasMilk(false);
    setHasLemon(false);
  }
};

#endif // TEA_BLACK_BUILDER_HPP