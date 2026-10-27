#ifndef ORDER_REPOSITORY_TESTFIXTURES_HPP
#define ORDER_REPOSITORY_TESTFIXTURES_HPP

#include "InterfaceAdapters/OrderRepository.hpp"

#include <gtest/gtest.h>

namespace coffee_shop::interface_adapters
{
///
/// \brief A fixture for an order repository that has no orders yet.
///
class GivenAnEmptyOrderRepository : public ::testing::Test
{
protected:
  OrderRepository m_OrderRepository;
};
} // namespace coffee_shop::interface_adapters

#endif // ORDER_REPOSITORY_TESTFIXTURES_HPP
