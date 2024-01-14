#ifndef COFFEE_LATTE_HPP
#define COFFEE_LATTE_HPP

// #include "BeverageVariety.hpp"
#include "../IBeverage.hpp"
#include <string>

//#include <unordered_set>

class CoffeeLatte : public IBeverage
{
public:
  // Coffee(BeverageVariety beverageVariety);
  CoffeeLatte(){};

  // bool addExtraIngredient(IngredientDecorator extraIngredient) override;

  std::string getDescription() const override { return "CoffeeLatte"; }
};

#endif // COFFEE_LATTE_HPP
