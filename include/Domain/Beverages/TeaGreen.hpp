#ifndef TEA_GREEN_HPP
#define TEA_GREEN_HPP

#include "Domain/Beverages/Tea.hpp"

#include <string>
#include <string_view>

namespace coffee_shop::domain
{
/// @brief The name of this beverage in descriptions.
inline constexpr std::string_view TeaGreenName = "TeaGreen";

class TeaGreen : public Tea
{
public:
  /// \brief
  TeaGreen() = default;

  [[nodiscard]] std::string getDescription() const override
  {
    return std::string(TeaGreenName);
  }
};
} // namespace coffee_shop::domain

#endif // TEA_GREEN_HPP
