#ifndef COFFEE_HPP
#define COFFEE_HPP

#include "BeverageVariety.hpp"
#include "IBeverage.hpp"

#include <unordered_set>

class Coffee : public IBeverage
{
public:
  Coffee(BeverageVariety beverageVariety);

  bool addExtraIngredient(Ingredient extraIngredient) override;

  std::string description() const override;
};

#endif // BEVERAGE_HPP
