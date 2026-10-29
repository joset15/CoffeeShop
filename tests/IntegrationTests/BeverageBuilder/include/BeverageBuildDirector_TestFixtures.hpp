#ifndef BEVERAGE_BUILD_DIRECTOR_INTEGRATION_TESTFIXTURES_HPP
#define BEVERAGE_BUILD_DIRECTOR_INTEGRATION_TESTFIXTURES_HPP

#include "Domain/BeverageBuilder/BeverageBuildDirector.hpp"

#include "DomainFactories_TestHelpers.hpp"

#include <gtest/gtest.h>

#include <memory>
#include <vector>

namespace coffee_shop::domain
{
///
/// \brief A fixture for a director that uses the real builders.
///
class GivenADirector : public ::testing::Test
{
protected:
  /// @brief Builds a beverage the same way the "add new order" use case does.
  bool build(BeverageVariety beverageVariety,
             const std::vector<Ingredient> &ingredients)
  {
    m_Builder =
        m_Factories.m_BuilderFactory.createBeverageBuilder(beverageVariety);
    BeverageBuildDirector director(*m_Builder);
    return director.buildBeverage(ingredients);
  }

  test_support::DomainFactories m_Factories;
  std::unique_ptr<IBeverageBuilder> m_Builder;
};
} // namespace coffee_shop::domain

#endif // BEVERAGE_BUILD_DIRECTOR_INTEGRATION_TESTFIXTURES_HPP
