#ifndef COCOA_HPP
#define COCOA_HPP

#include "BeverageVariety.hpp"
#include "IBeverage.hpp"

#include <list>

class Cocoa : public IBeverage
{
public:
  /// \brief
  //Cocoa(BeverageVariety beverageVariety);
  Cocoa();

  /// \brief
  //bool addExtraIngredient(Ingredient extraIngredient) override;

  std::string getDescription() const override
  {
    return "Cocoa description not implemented";
  }
};

#endif // COCOA_HPP
