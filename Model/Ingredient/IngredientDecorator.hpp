#ifndef INGREDIENT_DECORATOR_HPP
#define INGREDIENT_DECORATOR_HPP

#include "../Beverages/IBeverage.hpp"

#include <memory>
#include <string>

class IngredientDecorator : public IBeverage
{
public:
  /// \brief
  explicit IngredientDecorator(std::shared_ptr<IBeverage> beverage)
      : m_Beverage(beverage)
  {
  }

  /// @brief
  virtual ~IngredientDecorator() = default;

protected:
  /// @brief The decorator owns the decorated object.
  std::shared_ptr<IBeverage> m_Beverage;
};

#endif // INGREDIENT_DECORATOR_HPP
