#ifndef DOMAIN_FACTORIES_TESTHELPERS_HPP
#define DOMAIN_FACTORIES_TESTHELPERS_HPP

#include "Domain/BeverageFactories/BeverageBuilderSimpleFactory.hpp"
#include "Domain/BeverageFactories/BeverageFactory.hpp"
#include "Domain/BeverageFactories/IngredientFactory.hpp"

namespace coffee_shop::test_support
{
/// @brief The real domain factories, wired together the same way main() does.
///
/// Not copyable or movable: m_BuilderFactory points to the other two members.
struct DomainFactories
{
  DomainFactories() = default;
  DomainFactories(const DomainFactories &) = delete;
  DomainFactories &operator=(const DomainFactories &) = delete;
  DomainFactories(DomainFactories &&) = delete;
  DomainFactories &operator=(DomainFactories &&) = delete;
  ~DomainFactories() = default;

  domain::BeverageFactory m_BeverageFactory;
  domain::IngredientFactory m_IngredientFactory;
  domain::BeverageBuilderSimpleFactory m_BuilderFactory{m_BeverageFactory,
                                                        m_IngredientFactory};
};
} // namespace coffee_shop::test_support

#endif // DOMAIN_FACTORIES_TESTHELPERS_HPP
