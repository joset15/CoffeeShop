#ifndef COFFEE_ESPRESSO_BUILDER_PARAMETERIZED_TESTFIXTURES_HPP
#define COFFEE_ESPRESSO_BUILDER_PARAMETERIZED_TESTFIXTURES_HPP

#include "Domain/BeverageBuilder/BeverageBuildDirector.hpp"
#include "Domain/BeverageBuilder/CoffeeEspressoBuilder.hpp"

#include "Domain/BeverageFactories/BeverageFactory.hpp"
#include "Domain/BeverageFactories/IngredientFactory.hpp"

#include <gtest/gtest.h>
#include <memory>
#include <tuple>
#include <vector>

namespace coffee_shop::domain
{
///
/// \brief A fixture for testing a CoffeeEspressoBuilder.
///
class GivenSomeIngredientsForCoffeeEspressoBuilder
    : public ::testing::TestWithParam<
          std::tuple<std::vector<Ingredient>, bool, std::string>>
{
protected:
  void SetUp() override
  {
    m_BeverageBuildDirector = std::make_unique<BeverageBuildDirector>();
    m_CoffeeEspressoBuilder = std::make_shared<CoffeeEspressoBuilder>(
        BeverageFactory::getInstance(), IngredientFactory::getInstance());
    m_BeverageBuildDirector->setBuilder(m_CoffeeEspressoBuilder);
  }

  std::unique_ptr<BeverageBuildDirector> m_BeverageBuildDirector;
  std::shared_ptr<CoffeeEspressoBuilder> m_CoffeeEspressoBuilder;
};
} // namespace coffee_shop::domain

#endif // COFFEE_ESPRESSO_BUILDER_PARAMETERIZED_TESTFIXTURES_HPP