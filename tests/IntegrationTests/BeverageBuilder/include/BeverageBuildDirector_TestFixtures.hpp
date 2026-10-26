#ifndef BEVERAGE_BUILD_DIRECTOR_INTEGRATION_TESTFIXTURES_HPP
#define BEVERAGE_BUILD_DIRECTOR_INTEGRATION_TESTFIXTURES_HPP

#include "Domain/BeverageBuilder/BeverageBuildDirector.hpp"
#include "Domain/BeverageFactories/BeverageBuilderSimpleFactory.hpp"

#include <gtest/gtest.h>
#include <list>
#include <memory>

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
             const std::list<Ingredient> &ingredients)
  {
    m_Builder =
        BeverageBuilderSimpleFactory::getInstance()->createBeverageBuilder(
            beverageVariety);
    m_Director.setBuilder(m_Builder);
    return m_Director.buildBeverage(ingredients);
  }

  BeverageBuildDirector m_Director;
  std::shared_ptr<IBeverageBuilder> m_Builder;
};
} // namespace coffee_shop::domain

#endif // BEVERAGE_BUILD_DIRECTOR_INTEGRATION_TESTFIXTURES_HPP
