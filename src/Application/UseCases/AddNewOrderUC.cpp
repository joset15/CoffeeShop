#include "Application/UseCases/AddNewOrderUC.hpp"

#include "Application/UseCases/NewOrderReq.hpp"

#include "Domain/BeverageBuilder/BeverageBuilder.hpp"
#include "Domain/BeverageFactories/BeverageBuilderSimpleFactory.hpp"
#include "Domain/BeverageFactories/BeverageFactory.hpp"
#include "Domain/BeverageFactories/IngredientFactory.hpp"

#include <memory>

bool AddNewOrderUC::execute()
{
  return addNewOrder( // TODO: m_NewOrderReq.getBeverageType(),
      m_NewOrderReq.getBeverageVariety(), m_NewOrderReq.getIngredients());
};

bool AddNewOrderUC::addNewOrder( // TODO: IBeverage::BeverageType beverageType,
    BeverageVariety beverageVariety,
    const std::list<Ingredient> &ingredients)
{
  auto director = std::make_unique<BeverageBuildDirector>();

  std::shared_ptr<IBeverageBuilder> beverageBuilder =
      BeverageBuilderSimpleFactory::getInstance()->createBeverageBuilder(
          beverageVariety);
  if (!beverageBuilder)
  {
    return false; // No builder for this variety yet.
  }

  director->setBuilder(beverageBuilder);

  if (!director->buildBeverage(beverageVariety, ingredients))
  {
    return false;
  }

  return m_OrderRepository->save(beverageBuilder->takeBeverage());
};
