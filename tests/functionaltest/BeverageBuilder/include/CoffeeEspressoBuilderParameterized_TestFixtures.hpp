#ifndef COFFEE_ESPRESSO_BUILDER_TESTFIXTURES_HPP
#define COFFEE_ESPRESSO_BUILDER_TESTFIXTURES_HPP

#include "Model/BeverageBuilder/BeverageBuildDirector.hpp"
#include "Model/BeverageBuilder/CoffeeEspressoBuilder.hpp"

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
  virtual void SetUp()
  {
    m_BeverageBuildDirector = std::make_unique<BeverageBuildDirector>();
    m_CoffeeEspressoBuilder = std::make_shared<CoffeeEspressoBuilder>();
    m_BeverageBuildDirector->setBuilder(m_CoffeeEspressoBuilder);
  }

  virtual void TearDown() {}

  std::unique_ptr<BeverageBuildDirector> m_BeverageBuildDirector;
  std::shared_ptr<CoffeeEspressoBuilder> m_CoffeeEspressoBuilder;
};

} // namespace CoffeeShop

#endif // COFFEE_ESPRESSO_BUILDER_TESTFIXTURES_HPP