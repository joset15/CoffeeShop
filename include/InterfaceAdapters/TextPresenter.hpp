#ifndef TEXT_PRESENTER_HPP
#define TEXT_PRESENTER_HPP

#include "Application/UseCases/IAddNewOrderOutputPort.hpp"
#include "Application/UseCases/ICancelOrdersOutputPort.hpp"
#include "Application/UseCases/IListOrdersOutputPort.hpp"

#include <cstddef>
#include <ostream>
#include <string>
#include <string_view>
#include <vector>

namespace coffee_shop::interface_adapters
{
/// @brief Writes the results of the use cases as text lines to a stream
/// (the console, a file, or a string in the tests).
class TextPresenter : public application::IAddNewOrderOutputPort,
                      public application::IListOrdersOutputPort,
                      public application::ICancelOrdersOutputPort
{
public:
  /// @brief Creates a presenter that writes to the given stream.
  /// @param output Where the text is written.
  explicit TextPresenter(std::ostream &output);

  /// @brief Writes "Info: Order added: <description>."
  /// @param description The description of the ordered beverage.
  void orderAdded(std::string_view description) override;

  /// @brief Writes "Error: Order could not be added."
  void orderRejected() override;

  /// @brief Writes one order per line, or "No orders yet." if there are none.
  /// @param descriptions The descriptions of the orders.
  void ordersListed(const std::vector<std::string> &descriptions) override;

  /// @brief Writes "Info: Orders cancelled: <count>."
  /// @param count How many orders were cancelled.
  void ordersCancelled(std::size_t count) override;

private:
  /// @brief Where the text is written (not owned, never null).
  std::ostream *m_Output;
};
} // namespace coffee_shop::interface_adapters

#endif // TEXT_PRESENTER_HPP
