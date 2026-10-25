#ifndef IBEVERAGE_HPP
#define IBEVERAGE_HPP

#include <string>

/// @brief A beverage, possibly wrapped by ingredient decorators.
class IBeverage
{
public:
  /// @brief Allows deleting an implementation through this interface.
  virtual ~IBeverage() = default;

  /// @brief Describes the beverage and its ingredients.
  /// @return For example "CoffeeEspresso, Sugar, Milk".
  [[nodiscard]] virtual std::string getDescription() const = 0;
};

#endif // IBEVERAGE_HPP
