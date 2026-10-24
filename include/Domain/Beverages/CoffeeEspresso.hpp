#ifndef COFFEE_ESPRESSO_HPP
#define COFFEE_ESPRESSO_HPP

#include "Coffee.hpp"
#include <string>

static const std::string CoffeEspressoName = "CoffeeEspresso";

class CoffeeEspresso : public Coffee
{
public:
  CoffeeEspresso() = default;

  [[nodiscard]] std::string getDescription() const override
  {
    return CoffeEspressoName;
  }
};

#endif // COFFEE_EXPRESSO_HPP
