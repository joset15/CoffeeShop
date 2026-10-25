#ifndef TEA_BLACK_HPP
#define TEA_BLACK_HPP

#include "Tea.hpp"
#include <string>
#include <string_view>

/// @brief The name of this beverage in descriptions.
inline constexpr std::string_view TeaBlackName = "TeaBlack";

class TeaBlack : public Tea
{
public:
  /// @brief
  TeaBlack() = default;

  /// @brief
  /// @return
  [[nodiscard]] std::string getDescription() const override
  {
    return std::string(TeaBlackName);
  }
};

#endif // TEA_BLACK_HPP
