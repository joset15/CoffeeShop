#include "Application/UseCases/AddNewOrderUC.hpp"

#include "Application/UseCases/NewOrderReq.hpp"

#include "Domain/BeverageBuilder/BeverageBuilder.hpp"
#include "Domain/BeverageFactories/BeverageBuilderSimpleFactory.hpp"
#include "Domain/BeverageFactories/BeverageFactory.hpp"
#include "Domain/BeverageFactories/IngredientFactory.hpp"

#include <memory>
#include <string>
#include <utility>

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

bool AddNewOrderUC::addNewOrder(BeverageVariety beverageVariety,
                                const std::list<Ingredient> &ingredients)
{
  auto director = std::make_unique<BeverageBuildDirector>();

  std::shared_ptr<IBeverageBuilder> beverageBuilder =
      BeverageBuilderSimpleFactory::getInstance()->createBeverageBuilder(
          beverageVariety);
  if (!beverageBuilder)
  {
    return false; // Not a valid BeverageVariety value.
  }

  director->setBuilder(beverageBuilder);

  if (!director->buildBeverage(ingredients))
  {
    return false;
  }

  std::unique_ptr<IBeverage> beverage = beverageBuilder->takeBeverage();
  const std::string description = beverage->getDescription();
  if (!m_OrderRepository->save(std::move(beverage)))
  {
    return false;
  }

  m_OutputPort->orderAdded(description);
  return true;
}
