#ifndef COFFEE_LATTE_HPP
#define COFFEE_LATTE_HPP

#include "IBeverage.hpp"
#include <string>

class CoffeeLatte : public IBeverage
{
public:
  CoffeeLatte() = default;

  std::string getDescription() const override { return "CoffeeLatte"; }
};

#endif // COFFEE_LATTE_HPP
