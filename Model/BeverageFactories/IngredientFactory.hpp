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
  /// @param beverageVariety
  /// @return
  std::shared_ptr<IBeverage>
  createIngredient(Ingredient ingredient,
                   std::shared_ptr<IBeverage> beverage) override;

private:
  /// @brief
  IngredientFactory() = default;

  /// @brief
  ~IngredientFactory() = default;

  IngredientFactory(const IngredientFactory &) = delete;
  IngredientFactory &operator=(const IngredientFactory &) = delete;

  IngredientFactory(IngredientFactory &&) = delete;
  IngredientFactory &operator=(IngredientFactory &&) = delete;
};

#endif // INGREDIENT_FACTORY_HPP
