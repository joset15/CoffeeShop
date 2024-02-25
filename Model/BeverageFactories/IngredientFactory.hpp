#ifndef INGREDIENT_FACTORY_HPP
#define INGREDIENT_FACTORY_HPP

#include "IIngredientFactory.hpp"
#include <memory>

// TODO Complete doxygen comments.

class IngredientFactory : public IIngredientFactory
{
public:
  /// @brief
  IngredientFactory() = default;

  /// @brief
  virtual ~IngredientFactory() = default;

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
};

#endif // INGREDIENT_FACTORY_HPP
