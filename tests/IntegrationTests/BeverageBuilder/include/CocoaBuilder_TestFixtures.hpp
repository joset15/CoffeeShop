#ifndef COCOA_BUILDER_TESTFIXTURES_HPP
#define COCOA_BUILDER_TESTFIXTURES_HPP

#include "Domain/BeverageBuilder/CocoaBuilder.hpp"

#include "Domain/BeverageFactories/BeverageFactory.hpp"
#include "Domain/BeverageFactories/IngredientFactory.hpp"

#include <gtest/gtest.h>
#include <memory>

namespace coffee_shop
{
///
/// \brief A fixture for testing a CocoaBuilder.
///
class GivenACocoaBuilder : public ::testing::Test
{
protected:
  void SetUp() override
  {
    m_CocoaBuilder = std::make_unique<CocoaBuilder>(
        BeverageFactory::getInstance(), IngredientFactory::getInstance());
  }

  std::unique_ptr<CocoaBuilder> m_CocoaBuilder;
};
} // namespace coffee_shop

#endif // COCOA_BUILDER_TESTFIXTURES_HPP
