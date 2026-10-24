#ifndef COFFEE_ESPRESSO_BUILDER_TESTFIXTURES_HPP
#define COFFEE_ESPRESSO_BUILDER_TESTFIXTURES_HPP

// #include "InputCommand_TestDoubles.h"
#include "Domain/BeverageBuilder/BeverageBuildDirector.hpp"
#include "Domain/BeverageBuilder/CoffeeEspressoBuilder.hpp"
//#include "Model/Beverages/Coffee.hpp"

#include "Domain/BeverageFactories/BeverageFactory.hpp"
#include "Domain/BeverageFactories/IngredientFactory.hpp"

#include <gtest/gtest.h>
#include <memory>

namespace CoffeeShop
{
///
/// \brief A fixture for testing a CoffeeEspressoBuilder.
///
class GivenACoffeeEspressoBuilder : public ::testing::Test
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

} // namespace CoffeeShop

#endif // COFFEE_ESPRESSO_BUILDER_TESTFIXTURES_HPP
