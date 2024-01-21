#ifndef COFFEE_EXPRESSO_HPP
#define COFFEE_EXPRESSO_HPP

//#include "BeverageVariety.hpp"
#include "../IBeverage.hpp"

#include <iostream>
#include <string>

//#include <unordered_set>

class CoffeeEspresso : public IBeverage
{
public:
  CoffeeEspresso(){};

  // bool addExtraIngredient(IngredientDecorator extraIngredient) override;

  std::string getDescription() const override { return "CoffeeEspresso"; }

  ///
  /// \brief AddIngredients
  /// \return
  ///
  // virtual bool addIngredient(std::shared_ptr<IBeverage> ingredient)
  virtual bool addIngredient(IBeverage *ingredient)
  {
    if (ingredient->m_Ingredient == Ingredient::Sugar)
    {
      // std::cout << ingredient->getDescription() << std::endl;
      return true;
    }
    else
    {
      return false;
    }
  }
};

#endif // COFFEE_EXPRESSO_HPP
