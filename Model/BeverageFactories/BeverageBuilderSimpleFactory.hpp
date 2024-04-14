#ifndef BEVERAGE_BUILDER_FACTORY_HPP
#define BEVERAGE_BUILDER_FACTORY_HPP

#include "../Beverages/BeverageVariety.hpp"
#include "IBeverageBuilderFactory.hpp"
#include <memory>

// TODO Complete doxygen comments.

class BeverageBuilderFactory final : public IBeverageBuilderFactory
{
public:
  /// @brief
  /// @return
  static BeverageBuilderFactory *getInstance()
  {
    static BeverageBuilderFactory m_BeverageBuilderFactoryInstance;
    return &m_BeverageBuilderFactoryInstance;
  }

  /// @brief
  /// @param beverageVariety
  /// @return
  std::shared_ptr<IBeverageBuilder>
  createBeverageBuilder(BeverageVariety beverageVariety) override;

private:
  /// @brief Protected constructor
  BeverageBuilderFactory() = default;
  /// @brief
  ~BeverageBuilderFactory() = default;

  BeverageBuilderFactory(const BeverageBuilderFactory &) = delete;
  BeverageBuilderFactory &operator=(const BeverageBuilderFactory &) = delete;

  BeverageBuilderFactory(BeverageBuilderFactory &&) = delete;
  BeverageBuilderFactory &operator=(BeverageBuilderFactory &&) = delete;
};

#endif // BEVERAGE_BUILDER_FACTORY_HPP
