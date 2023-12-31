#ifndef COCOA_HPP
#define COCOA_HPP

#include "BeverageVariety.hpp"
#include "IBeverage.hpp"
#include <list>

class Cocoa : public IBeverage
{
public:
  /// \brief
  Cocoa(BeverageVariety beverageVariety);

  /// \brief
  bool addExtraIngredient(Ingredient extraIngredient) override;

  std::string description() const override
  {
    return "Cocoa descrition not implemented";
  }
};

#endif // COCOA_HPP
