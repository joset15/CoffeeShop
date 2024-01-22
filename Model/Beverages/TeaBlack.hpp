#ifndef TEA_BLACK_HPP
#define TEA_BLACK_HPP

//#include "BeverageVariety.hpp"
#include "IBeverage.hpp"

class TeaBlack : public IBeverage
{
public:
  /// \brief
  // Tea(BeverageVariety beverageVariety);
  TeaBlack(){};

  /// \brief
  // bool addExtraIngredient(Ingredient extraIngredient) override;

  std::string getDescription() const override { return "TeaBlack"; }
};

#endif // TEA_BLACK_HPP
