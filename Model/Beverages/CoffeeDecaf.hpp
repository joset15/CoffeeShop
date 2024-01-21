#ifndef COFFEE_DECAF_HPP
#define COFFEE_DECAF_HPP

#include "../IBeverage.hpp"
#include <string>

class CoffeeDecaf : public IBeverage
{
public:
  CoffeeDecaf(){};

  std::string getDescription() const override { return "CoffeeDecaf"; }
};

#endif // COFFEE_DECAF_HPP
