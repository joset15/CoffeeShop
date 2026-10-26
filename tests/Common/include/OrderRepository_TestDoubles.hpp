#ifndef ORDER_REPOSITORY_TESTDOUBLES_HPP
#define ORDER_REPOSITORY_TESTDOUBLES_HPP

#include "Application/UseCases/IOrderRepository.hpp"
#include "Domain/Beverages/IBeverage.hpp"

#include <memory>
#include <string>
#include <utility>
#include <vector>

namespace coffee_shop::test_support
{
///
/// \brief An in-memory repository that keeps the saved orders for inspection.
///
class FakeOrderRepository : public application::IOrderRepository
{
public:
  bool save(std::unique_ptr<domain::IBeverage> beverage) override
  {
    m_SavedOrders.push_back(std::move(beverage));
    return true;
  }

  [[nodiscard]] std::vector<std::string> describeOrders() const override
  {
    std::vector<std::string> descriptions;
    for (const auto &order : m_SavedOrders)
    {
      descriptions.push_back(order->getDescription());
    }
    return descriptions;
  }

  [[nodiscard]] const std::vector<std::unique_ptr<domain::IBeverage>> &
  getSavedOrders() const
  {
    return m_SavedOrders;
  }

private:
  std::vector<std::unique_ptr<domain::IBeverage>> m_SavedOrders;
};
} // namespace coffee_shop::test_support

#endif // ORDER_REPOSITORY_TESTDOUBLES_HPP
