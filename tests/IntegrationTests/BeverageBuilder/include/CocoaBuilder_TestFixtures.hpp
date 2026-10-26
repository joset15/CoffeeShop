#ifndef COCOA_BUILDER_TESTFIXTURES_HPP
#define COCOA_BUILDER_TESTFIXTURES_HPP

#include "Domain/BeverageBuilder/CocoaBuilder.hpp"

#include "DomainFactories_TestHelpers.hpp"

#include <gtest/gtest.h>
#include <memory>

namespace coffee_shop::domain
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
        m_Factories.m_BeverageFactory, m_Factories.m_IngredientFactory);
  }

  test_support::DomainFactories m_Factories;
  std::unique_ptr<CocoaBuilder> m_CocoaBuilder;
};
} // namespace coffee_shop::domain

#endif // COCOA_BUILDER_TESTFIXTURES_HPP
