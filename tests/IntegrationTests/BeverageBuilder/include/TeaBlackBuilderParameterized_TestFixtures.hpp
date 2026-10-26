#ifndef TEA_BLACK_BUILDER_TESTFIXTURES_HPP
#define TEA_BLACK_BUILDER_TESTFIXTURES_HPP

#include "Domain/BeverageBuilder/BeverageBuildDirector.hpp"
#include "Domain/BeverageBuilder/TeaBlackBuilder.hpp"

#include "DomainFactories_TestHelpers.hpp"

#include <gtest/gtest.h>
#include <memory>
#include <tuple>
#include <vector>

namespace coffee_shop::domain
{
/// @brief A fixture for testing a TeaBlackBuilder.
class GivenSomeIngredientsForTeaBlackBuilder
    : public ::testing::TestWithParam<
          std::tuple<std::vector<Ingredient>, bool, std::string>>
{
protected:
  void SetUp() override
  {
    m_TeaBlackBuilder = std::make_unique<TeaBlackBuilder>(
        m_Factories.m_BeverageFactory, m_Factories.m_IngredientFactory);
    m_BeverageBuildDirector =
        std::make_unique<BeverageBuildDirector>(*m_TeaBlackBuilder);
  }

  test_support::DomainFactories m_Factories;
  std::unique_ptr<TeaBlackBuilder> m_TeaBlackBuilder;
  std::unique_ptr<BeverageBuildDirector> m_BeverageBuildDirector;
};
} // namespace coffee_shop::domain

#endif // TEA_BLACK_BUILDER_TESTFIXTURES_HPP