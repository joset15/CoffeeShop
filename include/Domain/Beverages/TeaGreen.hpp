#ifndef TEA_GREEN_HPP
#define TEA_GREEN_HPP

#include "IBeverage.hpp"

class TeaGreen : public IBeverage
{
public:
  /// \brief
  TeaGreen(){};

  /// \brief
  // bool addExtraIngredient(Ingredient extraIngredient) override;

  std::string getDescription() const override { return "TeaGreen"; }
};

#endif // TEA_GREEN_HPP
