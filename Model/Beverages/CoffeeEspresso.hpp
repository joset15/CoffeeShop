#ifndef COFFEE_ESPRESSO_HPP
#define COFFEE_ESPRESSO_HPP

//#include "../IBeverage.hpp"
#include "../Coffee.hpp"

//#include <iostream>
#include <string>

// class CoffeeEspresso : public IBeverage
class CoffeeEspresso : public Coffee
{
public:
  CoffeeEspresso() = default;

  std::string getDescription() const override { return "CoffeeEspresso"; }
};

#endif // COFFEE_EXPRESSO_HPP
