#ifndef SUGAR_TESTFIXTURES_HPP
#define SUGAR_TESTFIXTURES_HPP

// #include "InputCommand_TestDoubles.h"
#include "Model/Beverages/Coffee.hpp"

#include <gtest/gtest.h>
#include <memory>

namespace CoffeeShop
{
///
/// \brief A fixture for testing the ingredient Sugar.
///
class GivenSomeSugar : public ::testing::Test
{
protected:
  virtual void SetUp() { m_Coffee = std::make_shared<Coffee>(); }

  virtual void TearDown() {}

  std::shared_ptr<Coffee> m_Coffee;
};
} // namespace CoffeeShop

#endif // SUGAR_TESTFIXTURES_HPP
