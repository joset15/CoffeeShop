#ifndef COFFEE_ESPRESSO_BUILDER_PARAMETERIZED_TESTFIXTURES_HPP
#define COFFEE_ESPRESSO_BUILDER_PARAMETERIZED_TESTFIXTURES_HPP

#include "Domain/BeverageBuilder/BeverageBuildDirector.hpp"
#include "Domain/BeverageBuilder/CoffeeEspressoBuilder.hpp"

#include "Domain/BeverageFactories/BeverageFactory.hpp"
#include "Domain/BeverageFactories/IngredientFactory.hpp"

#include <gtest/gtest.h>
#include <memory>
#include <tuple>

namespace CoffeeShop
{
///
/// \brief A fixture for testing a CoffeeEspressoBuilder.
///
class GivenSomeIngredientsForCoffeeEspressoBuilder
    : public ::testing::TestWithParam<
          std::tuple<std::list<Ingredient>, bool, std::string>>
{
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
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

} // namespace CoffeeShop

#endif // COFFEE_ESPRESSO_BUILDER_PARAMETERIZED_TESTFIXTURES_HPP