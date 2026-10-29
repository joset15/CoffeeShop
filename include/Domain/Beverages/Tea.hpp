#ifndef TEA_HPP
#define TEA_HPP

#include "Domain/Beverages/IBeverage.hpp"

#include <string>
#include <string_view>

namespace coffee_shop::domain
{
/// @brief The name of this beverage in descriptions.
inline constexpr std::string_view TeaName = "Tea";

class Tea : public IBeverage
{
public:
  /// @brief Creates a plain tea.
  Tea() = default;

  /// @brief Describes the beverage.
  /// @return The name of the beverage.
  [[nodiscard]] std::string getDescription() const override
  {
    return std::string(TeaName);
  }
};
} // namespace coffee_shop::domain

#endif // TEA_HPP
