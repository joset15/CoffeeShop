#ifndef COFFEE_HPP
#define COFFEE_HPP

#include "BeverageVariety.hpp"
#include "IBeverage.hpp"

#include <unordered_set>

class Coffee : public IBeverage
{
public:
  Coffee();

  std::string getDescription() const override { return "Coffee"; }
};

#endif // BEVERAGE_HPP
