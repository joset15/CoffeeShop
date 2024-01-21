#ifndef INGREDIENT_DECORATOR_HPP
#define INGREDIENT_DECORATOR_HPP

#include "../IBeverage.hpp"

#include <memory>
#include <string>

/*
enum class Ingredient
{
  Sugar,
  Milk,
  Cream,
  Honey,
  Lemon,
  SoyMilk,
  Water,
  LastIngredient
};*/

class IngredientDecorator : public IBeverage
{
public:
  /// \brief
  IngredientDecorator(std::shared_ptr<IBeverage> beverage)
      : m_Beverage(beverage)
  {
  }

  IngredientDecorator(Ingredient ingredient) { m_Ingredient = ingredient; }

  bool addToBeverage(std::shared_ptr<IBeverage> beverage)
  {
    if (beverage->addIngredient(this))
    {
      m_Beverage = beverage;
      return true;
    }
    else
    {
      return false;
    }
  }

  /// @brief
  virtual ~IngredientDecorator() {}

  /// @return The description.
  virtual std::string getDescription() const = 0;

protected:
  /// @brief The decorator owns the decorated object.
  std::shared_ptr<IBeverage> m_Beverage;
};

#endif // INGREDIENT_DECORATOR_HPP
