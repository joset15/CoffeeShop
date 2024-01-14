#ifndef BEVERAGEFACTORY_HPP
#define BEVERAGEFACTORY_HPP

#include "BeverageVariety.hpp"
#include "IBeverage.hpp"
//#include "Ingredient/IngredientDecorator.hpp"

#include <memory>

// TODO Complete doxygen comments.

class BeverageFactory
{
public:
  BeverageFactory() = default;

  /// \brief
  static BeverageFactory *getInstance()
  {
    static BeverageFactory m_BeverageFactoryInstance;
    return &m_BeverageFactoryInstance;
  }

  /// \brief
  std::shared_ptr<IBeverage>
  createBeverage(IBeverage::BeverageType beverageType,
                 BeverageVariety beverageVariety);

  /// \brief
  std::shared_ptr<IBeverage> createBeverage(BeverageVariety beverageVariety);
};

#endif // BEVERAGEFACTORY_HPP
