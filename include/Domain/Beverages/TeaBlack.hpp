#ifndef TEA_BLACK_HPP
#define TEA_BLACK_HPP

#include "Domain/Beverages/Tea.hpp"
#include <string>
#include <string_view>

namespace coffee_shop::domain
{
/// @brief The name of this beverage in descriptions.
inline constexpr std::string_view TeaBlackName = "TeaBlack";

class TeaBlack : public Tea
{
public:
  /// @brief Creates a black tea.
  TeaBlack() = default;

  /// @brief Describes the beverage.
  /// @return The name of the beverage.
  [[nodiscard]] std::string getDescription() const override
  {
    return std::string(TeaBlackName);
  }
};
} // namespace coffee_shop::domain

#endif // TEA_BLACK_HPP
