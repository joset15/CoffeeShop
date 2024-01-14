#ifndef COFFEE_EXPRESSO_HPP
#define COFFEE_EXPRESSO_HPP

//#include "BeverageVariety.hpp"
#include "../IBeverage.hpp"
#include <string>

//#include <unordered_set>

class CoffeeEspresso : public IBeverage
{
public:
  CoffeeEspresso(){};

  // bool addExtraIngredient(IngredientDecorator extraIngredient) override;

  std::string getDescription() const override { return "CoffeeEspresso"; }
};

#endif // COFFEE_EXPRESSO_HPP
