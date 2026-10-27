#ifndef ORDER_REPOSITORY_TESTDOUBLES_HPP
#define ORDER_REPOSITORY_TESTDOUBLES_HPP

#include "Domain/Beverages/IBeverage.hpp"

#include "Application/UseCases/IOrderRepository.hpp"

#include <memory>
#include <string>
#include <utility>
#include <vector>

namespace coffee_shop::test_support
{
///
/// \brief An in-memory repository that keeps the saved orders for inspection.
/// It accepts every order unless rejectOrders() is called.
///
class FakeOrderRepository : public application::IOrderRepository
{
public:
  bool save(std::unique_ptr<domain::IBeverage> beverage) override
  {
    if (!m_AcceptsOrders)
    {
      return false;
    }
    m_SavedOrders.push_back(std::move(beverage));
    return true;
  }

  /// @brief Makes every later save() fail, like a repository that can't store.
  void rejectOrders() { m_AcceptsOrders = false; }

  [[nodiscard]] std::vector<std::string> describeOrders() const override
  {
    std::vector<std::string> descriptions;
    descriptions.reserve(m_SavedOrders.size());
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
  bool m_AcceptsOrders = true;
};
} // namespace coffee_shop::test_support

#endif // ORDER_REPOSITORY_TESTDOUBLES_HPP
