#ifndef COFFEE_ESPRESSO_BUILDER_TESTFIXTURES_HPP
#define COFFEE_ESPRESSO_BUILDER_TESTFIXTURES_HPP

#include "Domain/BeverageBuilder/BeverageBuildDirector.hpp"
#include "Domain/BeverageBuilder/CoffeeEspressoBuilder.hpp"

#include "DomainFactories_TestHelpers.hpp"

#include <gtest/gtest.h>
#include <memory>

namespace coffee_shop::domain
{
///
/// \brief A fixture for testing a CoffeeEspressoBuilder.
///
class GivenACoffeeEspressoBuilder : public ::testing::Test
{
protected:
  void SetUp() override
  {
    m_CoffeeEspressoBuilder = std::make_unique<CoffeeEspressoBuilder>(
        m_Factories.m_BeverageFactory, m_Factories.m_IngredientFactory);
    m_BeverageBuildDirector =
        std::make_unique<BeverageBuildDirector>(*m_CoffeeEspressoBuilder);
  }

  test_support::DomainFactories m_Factories;
  std::unique_ptr<CoffeeEspressoBuilder> m_CoffeeEspressoBuilder;
  std::unique_ptr<BeverageBuildDirector> m_BeverageBuildDirector;
};
} // namespace coffee_shop::domain

#endif // COFFEE_ESPRESSO_BUILDER_TESTFIXTURES_HPP
