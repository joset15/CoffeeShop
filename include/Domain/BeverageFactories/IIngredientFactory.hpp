#ifndef IINGREDIENT_FACTORY_HPP
#define IINGREDIENT_FACTORY_HPP

#include "Domain/Ingredients/Ingredients.hpp"
#include <memory>

// TODO Complete doxygen comments.

/// @brief The IIngredientFactory class
class IIngredientFactory
{
public:
  /// @brief
  virtual ~IIngredientFactory() = default;

  /// @brief
  /// @param ingredient
  /// @param beverage
  /// @return
  virtual std::unique_ptr<IBeverage>
  createIngredient(Ingredient ingredient,
                   std::unique_ptr<IBeverage> beverage) = 0;
};

#endif // IINGREDIENT_FACTORY_HPP
