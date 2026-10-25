#ifndef INGREDIENT_FACTORY_HPP
#define INGREDIENT_FACTORY_HPP

#include "IIngredientFactory.hpp"
#include <memory>

/// @brief Creates the ingredient decorators (singleton).
class IngredientFactory final : public IIngredientFactory
{
public:
  /// @brief Gets the only instance (singleton).
  /// @return The instance; it lives until the program ends.
  static IngredientFactory *getInstance()
  {
    static IngredientFactory m_IngredientFactoryInstance;
    return &m_IngredientFactoryInstance;
  }

  /// @brief Wraps a beverage with the decorator of an ingredient.
  /// @param ingredient The ingredient to add.
  /// @param beverage The beverage to decorate; the decorator takes ownership.
  /// @return The decorated beverage (nullptr only for an invalid Ingredient
  /// value).
  std::unique_ptr<IBeverage>
  createIngredient(Ingredient ingredient,
                   std::unique_ptr<IBeverage> beverage) override;

  IngredientFactory(const IngredientFactory &) = delete;
  IngredientFactory &operator=(const IngredientFactory &) = delete;

  IngredientFactory(IngredientFactory &&) = delete;
  IngredientFactory &operator=(IngredientFactory &&) = delete;

private:
  /// @brief Private constructor: use getInstance().
  IngredientFactory() = default;

  /// @brief Private: the singleton is never deleted from outside.
  ~IngredientFactory() override = default;
};

#endif // INGREDIENT_FACTORY_HPP
