#ifndef OUTPUT_PORT_TESTDOUBLES_HPP
#define OUTPUT_PORT_TESTDOUBLES_HPP

#include "Application/UseCases/IAddNewOrderOutputPort.hpp"
#include "Application/UseCases/IListOrdersOutputPort.hpp"

#include <optional>
#include <string>
#include <string_view>
#include <vector>

namespace coffee_shop
{
///
/// \brief Records what the "add new order" use case reports.
///
class FakeAddNewOrderOutputPort : public IAddNewOrderOutputPort
{
public:
  void orderAdded(std::string_view description) override
  {
    m_AddedDescriptions.emplace_back(description);
  }

  void orderRejected() override { ++m_RejectedCount; }

  [[nodiscard]] const std::vector<std::string> &getAddedDescriptions() const
  {
    return m_AddedDescriptions;
  }

  [[nodiscard]] int getRejectedCount() const { return m_RejectedCount; }

private:
  std::vector<std::string> m_AddedDescriptions;
  int m_RejectedCount = 0;
};

///
/// \brief Records the last list sent by the "list orders" use case.
///
class FakeListOrdersOutputPort : public IListOrdersOutputPort
{
public:
  void ordersListed(const std::vector<std::string> &descriptions) override
  {
    m_ListedDescriptions = descriptions;
  }

  /// @return The last list, or nullopt if nothing was listed.
  [[nodiscard]] const std::optional<std::vector<std::string>> &
  getListedDescriptions() const
  {
    return m_ListedDescriptions;
  }

private:
  std::optional<std::vector<std::string>> m_ListedDescriptions;
};
} // namespace coffee_shop

#endif // OUTPUT_PORT_TESTDOUBLES_HPP
