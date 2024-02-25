#ifndef BEVERAGE_FACTORY_HPP
#define BEVERAGE_FACTORY_HPP

#include "../Beverages/BeverageVariety.hpp"
#include "IBeverageFactory.hpp"
#include <memory>

// TODO Complete doxygen comments.

class BeverageFactory : public IBeverageFactory
{
public:
  /// @brief
  BeverageFactory() = default;

  /// @brief
  virtual ~BeverageFactory() = default;

  /// @brief
  /// @return
  static BeverageFactory *getInstance()
  {
    static BeverageFactory m_BeverageFactoryInstance;
    return &m_BeverageFactoryInstance;
  }

  /// @brief
  /// @param beverageVariety
  /// @return
  std::shared_ptr<IBeverage>
  createBeverage(BeverageVariety beverageVariety) override;
};

#endif // BEVERAGE_FACTORY_HPP
