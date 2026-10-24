#ifndef BEVERAGE_BUILD_DIRECTOR_TESTFIXTURES_HPP
#define BEVERAGE_BUILD_DIRECTOR_TESTFIXTURES_HPP

#include "Domain/BeverageBuilder/BeverageBuildDirector.hpp"

#include <gtest/gtest.h>

namespace CoffeeShop
{
///
/// \brief A fixture for a director whose builder was never set.
///
class GivenADirectorWithoutBuilder : public ::testing::Test
{
protected:
  BeverageBuildDirector m_Director;
};
} // namespace CoffeeShop

#endif // BEVERAGE_BUILD_DIRECTOR_TESTFIXTURES_HPP
