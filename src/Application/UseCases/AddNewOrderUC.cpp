#include "Application/UseCases/AddNewOrderUC.hpp"

#include "Application/UseCases/NewOrderReq.hpp"

#include "Domain/BeverageBuilder/BeverageBuilder.hpp"
#include "Domain/BeverageFactories/BeverageBuilderSimpleFactory.hpp"
#include "Domain/BeverageFactories/BeverageFactory.hpp"
#include "Domain/BeverageFactories/IngredientFactory.hpp"

#include <memory>
#include <string>
#include <utility>

namespace coffee_shop::application
{
bool AddNewOrderUC::execute()
{
  const bool added = addNewOrder(m_NewOrderReq.getBeverageVariety(),
                                 m_NewOrderReq.getIngredients());
  if (!added)
  {
    m_OutputPort->orderRejected();
  }
  return added;
}

bool AddNewOrderUC::addNewOrder(
    domain::BeverageVariety beverageVariety,
    const std::vector<domain::Ingredient> &ingredients)
{
  auto director = std::make_unique<domain::BeverageBuildDirector>();

  const std::shared_ptr<domain::IBeverageBuilder> beverageBuilder =
      domain::BeverageBuilderSimpleFactory::getInstance()
          ->createBeverageBuilder(beverageVariety);
  if (!beverageBuilder)
  {
    return false; // Not a valid BeverageVariety value.
  }

  director->setBuilder(beverageBuilder);

  if (!director->buildBeverage(ingredients))
  {
    return false;
  }

  std::unique_ptr<domain::IBeverage> beverage = beverageBuilder->takeBeverage();
  const std::string description = beverage->getDescription();
  if (!m_OrderRepository->save(std::move(beverage)))
  {
    return false;
  }

  m_OutputPort->orderAdded(description);
  return true;
}
} // namespace coffee_shop::application
