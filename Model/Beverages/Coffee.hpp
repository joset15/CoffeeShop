#ifndef COFFEE_HPP
#define COFFEE_HPP

#include "IBeverage.hpp"

static const std::string CoffeName = "Coffee";

class Coffee : public IBeverage
{
public:
  Coffee();

  std::string getDescription() const override { return CoffeName; }
};

#endif // COFFEE_HPP
