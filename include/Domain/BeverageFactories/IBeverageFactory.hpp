#ifndef IBEVERAGE_FACTORY_HPP
#define IBEVERAGE_FACTORY_HPP

#include "Domain/Beverages/BeverageVariety.hpp"
#include "Domain/Beverages/IBeverage.hpp"

#include <memory>

namespace coffee_shop::domain
{
/// @brief Creates base beverages (Abstract Factory).
class IBeverageFactory
{
public:
  /// @brief Allows deleting an implementation through this interface.
  virtual ~IBeverageFactory() = default;

  /// @brief Creates the base beverage of a variety, without ingredients.
  /// @param beverageVariety The variety to create.
  /// @return The beverage (nullptr only for an invalid BeverageVariety value).
  virtual std::unique_ptr<IBeverage>
  createBeverage(BeverageVariety beverageVariety) = 0;
};
} // namespace coffee_shop::domain

#endif // IBEVERAGE_FACTORY_HPP
