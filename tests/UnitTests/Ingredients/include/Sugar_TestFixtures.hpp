#ifndef SUGAR_TESTFIXTURES_HPP
#define SUGAR_TESTFIXTURES_HPP

#include "Domain/Beverages/Coffee.hpp"

#include <gtest/gtest.h>

#include <memory>

namespace coffee_shop::domain
{
///
/// \brief A fixture for testing the ingredient Sugar.
///
class GivenSomeSugar : public ::testing::Test
{
protected:
  void SetUp() override { m_Coffee = std::make_unique<Coffee>(); }

  std::unique_ptr<Coffee> m_Coffee;
};
} // namespace coffee_shop::domain

#endif // SUGAR_TESTFIXTURES_HPP
