#ifndef COFFEE_DECAF_HPP
#define COFFEE_DECAF_HPP

//#include "BeverageVariety.hpp"
#include "../IBeverage.hpp"
#include <string>

class CoffeeDecaf : public IBeverage
{
public:
  CoffeeDecaf(){};

  // bool addExtraIngredient(IngredientDecorator extraIngredient) override;

  std::string getDescription() const override { return "CoffeeDecaf"; }
};

#endif // COFFEE_DECAF_HPP
