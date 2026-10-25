#ifndef TEA_GREEN_HPP
#define TEA_GREEN_HPP

#include "IBeverage.hpp"

#include <string>
#include <string_view>

/// @brief The name of this beverage in descriptions.
inline constexpr std::string_view TeaGreenName = "TeaGreen";

class TeaGreen : public IBeverage
{
public:
  /// \brief
  TeaGreen() = default;

  /// \brief
  // bool addExtraIngredient(Ingredient extraIngredient) override;

  [[nodiscard]] std::string getDescription() const override
  {
    return std::string(TeaGreenName);
  }
};

#endif // TEA_GREEN_HPP
