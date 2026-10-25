#ifndef TEA_GREEN_HPP
#define TEA_GREEN_HPP

#include "Tea.hpp"

#include <string>
#include <string_view>

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

#endif // TEA_GREEN_HPP
