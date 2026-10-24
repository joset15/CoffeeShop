#ifndef COFFEE_TESTFIXTURES_HPP
#define COFFEE_TESTFIXTURES_HPP

// #include "InputCommand_TestDoubles.h"
//#include "../../../../Model/Beverages/Coffee.hpp"
#include "Domain/Beverages/Coffee.hpp"
#include <gtest/gtest.h>
#include <memory>

namespace CoffeeShop
{
///
/// \brief A fixture for testing a Coffee.
///
class GivenACoffee : public ::testing::Test
{
protected:
  void SetUp() override { m_Coffee = std::make_unique<Coffee>(); }

  std::unique_ptr<Coffee> m_Coffee;
};
} // namespace CoffeeShop

#endif // COFFEE_TESTFIXTURES_HPP
