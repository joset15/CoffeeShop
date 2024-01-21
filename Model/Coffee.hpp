#ifndef COFFEE_HPP
#define COFFEE_HPP

#include "BeverageVariety.hpp"
#include "IBeverage.hpp"

#include <unordered_set>

class Coffee : public IBeverage
{
public:
  // Coffee(BeverageVariety beverageVariety);
  Coffee();

  // bool addExtraIngredient(IngredientDecorator extraIngredient) override;

  std::string getDescription() const override { return "Coffee"; }

  /// \brief AddIngredients
  /// \return
  // bool addIngredients() override;
  /*
  bool addIngredient(IngredientDecorator extraIngredient) override
  {
    return true;
  }*/
};

#endif // BEVERAGE_HPP
