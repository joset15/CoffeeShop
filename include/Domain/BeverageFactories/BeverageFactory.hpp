#ifndef BEVERAGE_FACTORY_HPP
#define BEVERAGE_FACTORY_HPP

#include "../Beverages/BeverageVariety.hpp"
#include "IBeverageFactory.hpp"
#include <memory>

// TODO Complete doxygen comments.

class BeverageFactory final : public IBeverageFactory
{
public:
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
  std::unique_ptr<IBeverage>
  createBeverage(BeverageVariety beverageVariety) override;

private:
  /// @brief
  BeverageFactory() = default;

  /// @brief
  ~BeverageFactory() override = default;

  BeverageFactory(const BeverageFactory &) = delete;
  BeverageFactory &operator=(const BeverageFactory &) = delete;

  BeverageFactory(BeverageFactory &&) = delete;
  BeverageFactory &operator=(BeverageFactory &&) = delete;
};

#endif // BEVERAGE_FACTORY_HPP
