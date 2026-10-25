#ifndef BEVERAGE_BUILDER_SIMPLE_FACTORY_HPP
#define BEVERAGE_BUILDER_SIMPLE_FACTORY_HPP

#include "../Beverages/BeverageVariety.hpp"
#include "IBeverageBuilderFactory.hpp"
#include <memory>

// TODO Complete doxygen comments.

class BeverageBuilderSimpleFactory final : public IBeverageBuilderFactory
{
public:
  /// @brief
  /// @return
  static BeverageBuilderSimpleFactory *getInstance()
  {
    static BeverageBuilderSimpleFactory m_BeverageBuilderFactoryInstance;
    return &m_BeverageBuilderFactoryInstance;
  }

  /// @brief Creates the builder for a beverage variety.
  /// @param beverageVariety The variety to build.
  /// @return The builder (nullptr only for an invalid BeverageVariety value).
  std::shared_ptr<IBeverageBuilder>
  createBeverageBuilder(BeverageVariety beverageVariety) override;

  BeverageBuilderSimpleFactory(const BeverageBuilderSimpleFactory &) = delete;
  BeverageBuilderSimpleFactory &
  operator=(const BeverageBuilderSimpleFactory &) = delete;

  BeverageBuilderSimpleFactory(BeverageBuilderSimpleFactory &&) = delete;
  BeverageBuilderSimpleFactory &
  operator=(BeverageBuilderSimpleFactory &&) = delete;

private:
  /// @brief Private constructor: use getInstance().
  BeverageBuilderSimpleFactory() = default;
  /// @brief
  ~BeverageBuilderSimpleFactory() override = default;
};

#endif // BEVERAGE_BUILDER_SIMPLE_FACTORY_HPP
