#ifndef INGREDIENT_FACTORY_HPP
#define INGREDIENT_FACTORY_HPP

#include "IIngredientFactory.hpp"
#include <memory>

// TODO Complete doxygen comments.

class IngredientFactory final : public IIngredientFactory
{
public:
  /// @brief
  /// @return
  static IngredientFactory *getInstance()
  {
    static IngredientFactory m_IngredientFactoryInstance;
    return &m_IngredientFactoryInstance;
  }

  /// @brief
  /// @param ingredient
  /// @param beverage
  /// @return
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

  /// @brief
  ~IngredientFactory() override = default;
};

#endif // INGREDIENT_FACTORY_HPP
