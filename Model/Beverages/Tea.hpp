#ifndef TEA_HPP
#define TEA_HPP

//#include "BeverageVariety.hpp"
#include "IBeverage.hpp"

class Tea : public IBeverage
{
public:
  /// \brief
  // Tea(BeverageVariety beverageVariety);
  Tea(){};

  /// \brief
  // bool addExtraIngredient(Ingredient extraIngredient) override;

  std::string getDescription() const override
  {
    return "Tea description not implemented";
  }
};

#endif // TEA_HPP
