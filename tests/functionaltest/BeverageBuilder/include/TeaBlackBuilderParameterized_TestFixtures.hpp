#ifndef TEA_BLACK_BUILDER_TESTFIXTURES_HPP
#define TEA_BLACK_BUILDER_TESTFIXTURES_HPP

#include "Model/BeverageBuilder/BeverageBuildDirector.hpp"
#include "Model/BeverageBuilder/TeaBlackBuilder.hpp"

#include "Model/BeverageFactories/BeverageFactory.hpp"
#include "Model/BeverageFactories/IngredientFactory.hpp"

#include <gtest/gtest.h>
#include <memory>
#include <tuple>

namespace CoffeeShop
{
/// @brief A fixture for testing a CoffeeEspressoBuilder.
class GivenSomeIngredientsForTeaBlackBuilder
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
    m_TeaBlackBuilder = std::make_shared<TeaBlackBuilder>(
        BeverageFactory::getInstance(), IngredientFactory::getInstance());
    m_BeverageBuildDirector->setBuilder(m_TeaBlackBuilder);
  }

  virtual void TearDown() {}

  std::unique_ptr<BeverageBuildDirector> m_BeverageBuildDirector;
  std::shared_ptr<TeaBlackBuilder> m_TeaBlackBuilder;
};

} // namespace CoffeeShop

#endif // TEA_BLACK_BUILDER_TESTFIXTURES_HPP