#ifndef TEA_GREEN_HPP
#define TEA_GREEN_HPP

#include "IBeverage.hpp"

class TeaGreen : public IBeverage
{
public:
  /// \brief
  TeaGreen() = default;

  /// \brief
  // bool addExtraIngredient(Ingredient extraIngredient) override;

  [[nodiscard]] std::string getDescription() const override
  {
    return "TeaGreen";
  }
};

#endif // TEA_GREEN_HPP
