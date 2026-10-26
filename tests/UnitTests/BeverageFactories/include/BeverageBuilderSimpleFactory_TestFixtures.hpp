#ifndef BEVERAGE_BUILDER_SIMPLE_FACTORY_TESTFIXTURES_HPP
#define BEVERAGE_BUILDER_SIMPLE_FACTORY_TESTFIXTURES_HPP

#include "Domain/BeverageFactories/BeverageBuilderSimpleFactory.hpp"

#include <gtest/gtest.h>
#include <string_view>
#include <tuple>

namespace coffee_shop::domain
{
///
/// \brief A fixture for each beverage variety and the name of its beverage.
///
class GivenABeverageVariety : public ::testing::TestWithParam<
                                  std::tuple<BeverageVariety, std::string_view>>
{
};
} // namespace coffee_shop::domain

#endif // BEVERAGE_BUILDER_SIMPLE_FACTORY_TESTFIXTURES_HPP
