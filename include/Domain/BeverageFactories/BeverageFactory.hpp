#ifndef BEVERAGE_FACTORY_HPP
#define BEVERAGE_FACTORY_HPP

#include "../Beverages/BeverageVariety.hpp"
#include "IBeverageFactory.hpp"
#include <memory>

/// @brief Creates the base beverages (singleton).
class BeverageFactory final : public IBeverageFactory
{
public:
  /// @brief Gets the only instance (singleton).
  /// @return The instance; it lives until the program ends.
  static BeverageFactory *getInstance()
  {
    static BeverageFactory m_BeverageFactoryInstance;
    return &m_BeverageFactoryInstance;
  }

  /// @brief Creates the base beverage of a variety, without ingredients.
  /// @param beverageVariety The variety to create.
  /// @return The beverage (nullptr only for an invalid BeverageVariety value).
  std::unique_ptr<IBeverage>
  createBeverage(BeverageVariety beverageVariety) override;

  BeverageFactory(const BeverageFactory &) = delete;
  BeverageFactory &operator=(const BeverageFactory &) = delete;

  BeverageFactory(BeverageFactory &&) = delete;
  BeverageFactory &operator=(BeverageFactory &&) = delete;

private:
  /// @brief Private constructor: use getInstance().
  BeverageFactory() = default;

  /// @brief Private: the singleton is never deleted from outside.
  ~BeverageFactory() override = default;
};

#endif // BEVERAGE_FACTORY_HPP
