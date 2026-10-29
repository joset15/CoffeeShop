#ifndef TEA_TESTFIXTURES_HPP
#define TEA_TESTFIXTURES_HPP

#include "Domain/Beverages/Tea.hpp"

#include <gtest/gtest.h>

namespace coffee_shop::domain
{
///
/// \brief A fixture for testing a plain Tea.
///
class GivenATea : public ::testing::Test
{
protected:
  Tea m_Tea;
};
} // namespace coffee_shop::domain

#endif // TEA_TESTFIXTURES_HPP
