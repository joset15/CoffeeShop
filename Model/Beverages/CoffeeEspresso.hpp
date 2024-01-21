#ifndef COFFEE_EXPRESSO_HPP
#define COFFEE_EXPRESSO_HPP

#include "../IBeverage.hpp"

#include <iostream>
#include <string>

class CoffeeEspresso : public IBeverage
{
public:
  CoffeeEspresso() = default;

  std::string getDescription() const override { return "CoffeeEspresso"; }
};

#endif // COFFEE_EXPRESSO_HPP
