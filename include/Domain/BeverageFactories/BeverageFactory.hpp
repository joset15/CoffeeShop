#ifndef BEVERAGE_FACTORY_HPP
#define BEVERAGE_FACTORY_HPP

#include "Domain/BeverageFactories/IBeverageFactory.hpp"
#include "Domain/Beverages/BeverageVariety.hpp"

#include <memory>

namespace coffee_shop::domain
{
/// @brief Creates the base beverages.
class BeverageFactory final : public IBeverageFactory
{
public:
  /// @brief Creates the base beverage of a variety, without ingredients.
  /// @param beverageVariety The variety to create.
  /// @return The beverage (nullptr only for an invalid BeverageVariety value).
  std::unique_ptr<IBeverage>
  createBeverage(BeverageVariety beverageVariety) override;
};
} // namespace coffee_shop::domain

#endif // BEVERAGE_FACTORY_HPP
