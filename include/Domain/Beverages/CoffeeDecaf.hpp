#ifndef COFFEE_DECAF_HPP
#define COFFEE_DECAF_HPP

#include "../Beverages/IBeverage.hpp"
#include <string>

class CoffeeDecaf : public IBeverage
{
public:
  CoffeeDecaf() = default;

  [[nodiscard]] std::string getDescription() const override
  {
    return "CoffeeDecaf";
  }
};

#endif // COFFEE_DECAF_HPP
