#ifndef TEA_HPP
#define TEA_HPP

#include "BeverageVariety.hpp"
#include "IBeverage.hpp"

class Tea : public IBeverage
{
public:
  /// \brief
  Tea(BeverageVariety beverageVariety);

  /// \brief
  bool addExtraIngredient(Ingredient extraIngredient) override;

  std::string description() const override
  {
    return "Tea descrition not implemented";
  }
};

#endif // TEA_HPP
