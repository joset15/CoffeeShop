#ifndef BEVERAGE_BUILDER_FACTORY_TESTDOUBLES_HPP
#define BEVERAGE_BUILDER_FACTORY_TESTDOUBLES_HPP

#include "Domain/BeverageBuilder/IBeverageBuilder.hpp"
#include "Domain/BeverageFactories/IBeverageBuilderFactory.hpp"
#include "Domain/Beverages/BeverageVariety.hpp"

#include <memory>

namespace coffee_shop::application
{
///
/// \brief A builder factory that knows no beverage variety: it always returns
/// nullptr, as the real one does for an invalid BeverageVariety value.
///
class FakeBuilderFactoryWithNoVarieties : public domain::IBeverageBuilderFactory
{
public:
  std::unique_ptr<domain::IBeverageBuilder> createBeverageBuilder(
      [[maybe_unused]] domain::BeverageVariety beverageVariety) override
  {
    return nullptr;
  }
};
} // namespace coffee_shop::application

#endif // BEVERAGE_BUILDER_FACTORY_TESTDOUBLES_HPP
