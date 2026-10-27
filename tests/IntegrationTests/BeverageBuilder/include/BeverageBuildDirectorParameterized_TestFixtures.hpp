#ifndef BEVERAGE_BUILD_DIRECTOR_PARAMETERIZED_TESTFIXTURES_HPP
#define BEVERAGE_BUILD_DIRECTOR_PARAMETERIZED_TESTFIXTURES_HPP

#include "Domain/BeverageBuilder/BeverageBuildDirector.hpp"
#include "Domain/BeverageBuilder/IBeverageBuilder.hpp"
#include "Domain/Beverages/BeverageVariety.hpp"
#include "Domain/Ingredients/Ingredient.hpp"

#include "DomainFactories_TestHelpers.hpp"

#include <gtest/gtest.h>

#include <memory>
#include <ostream>
#include <string>
#include <string_view>
#include <vector>

namespace coffee_shop::domain
{
/// @brief A row of the rules table for an order the director must fulfil.
struct AcceptedOrder
{
  std::string_view m_Name; ///< Test case name, e.g. "EspressoWithCream".
  BeverageVariety m_Variety;
  std::vector<Ingredient> m_Ingredients;
  std::string m_Description; ///< Expected description of the beverage.
};

/// @brief A row of the rules table for an order the director must reject.
struct RejectedOrder
{
  std::string_view m_Name; ///< Test case name, e.g. "CocoaWithLemon".
  BeverageVariety m_Variety;
  std::vector<Ingredient> m_Ingredients;
};

/// @brief Lets GoogleTest print a row by its name instead of its raw bytes.
inline std::ostream &operator<<(std::ostream &output,
                                const AcceptedOrder &order)
{
  return output << order.m_Name;
}

/// @brief Lets GoogleTest print a row by its name instead of its raw bytes.
inline std::ostream &operator<<(std::ostream &output,
                                const RejectedOrder &order)
{
  return output << order.m_Name;
}

/// @brief Names each test case after its row of the rules table.
struct OrderName
{
  template <typename Order>
  std::string operator()(const ::testing::TestParamInfo<Order> &info) const
  {
    return std::string(info.param.m_Name);
  }
};

///
/// \brief A fixture that builds an order with the real builders, the same
/// way the "add new order" use case does.
///
template <typename Order>
class GivenAnOrder : public ::testing::TestWithParam<Order>
{
protected:
  /// @brief Builds the order of the current row.
  /// @return False if the director rejects it.
  bool build()
  {
    const Order &order = this->GetParam();
    m_Builder =
        m_Factories.m_BuilderFactory.createBeverageBuilder(order.m_Variety);
    BeverageBuildDirector director(*m_Builder);
    return director.buildBeverage(order.m_Ingredients);
  }

  test_support::DomainFactories m_Factories;
  std::unique_ptr<IBeverageBuilder> m_Builder;
};

/// \brief An order that follows the rules in AGENTS.md.
class GivenAnAcceptedOrder : public GivenAnOrder<AcceptedOrder>
{
};

/// \brief An order that breaks a rule in AGENTS.md.
class GivenARejectedOrder : public GivenAnOrder<RejectedOrder>
{
};
} // namespace coffee_shop::domain

#endif // BEVERAGE_BUILD_DIRECTOR_PARAMETERIZED_TESTFIXTURES_HPP
