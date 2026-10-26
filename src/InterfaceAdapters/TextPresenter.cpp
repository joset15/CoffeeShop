#include "InterfaceAdapters/TextPresenter.hpp"
#include <ostream>
#include <string>
#include <string_view>
#include <vector>

namespace coffee_shop::interface_adapters
{
TextPresenter::TextPresenter(std::ostream &output) : m_Output(&output) {}

void TextPresenter::orderAdded(std::string_view description)
{
  *m_Output << "Info: Order added: " << description << ".\n";
}

void TextPresenter::orderRejected()
{
  *m_Output << "Error: Order could not be added.\n";
}

void TextPresenter::ordersListed(const std::vector<std::string> &descriptions)
{
  if (descriptions.empty())
  {
    *m_Output << "No orders yet.\n";
    return;
  }
  for (const auto &description : descriptions)
  {
    *m_Output << description << '\n';
  }
}
} // namespace coffee_shop::interface_adapters
