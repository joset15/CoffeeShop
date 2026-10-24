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
  static IIngredientFactory *getInstance() { return nullptr; }

  /// @brief
  /// @param ingredient
  /// @param beverage
  /// @return
  virtual std::shared_ptr<IBeverage>
  createIngredient(Ingredient ingredient,
                   std::shared_ptr<IBeverage> beverage) = 0;
};

#endif // IINGREDIENT_FACTORY_HPP
