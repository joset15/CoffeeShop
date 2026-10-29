#include "Application/UseCases/AddNewOrderUC.hpp"

#include "Domain/BeverageBuilder/BeverageBuildDirector.hpp"
#include "Domain/BeverageBuilder/IBeverageBuilder.hpp"
#include "Domain/Beverages/BeverageVariety.hpp"
#include "Domain/Beverages/IBeverage.hpp"
#include "Domain/Ingredients/Ingredient.hpp"

#include "Application/UseCases/NewOrderReq.hpp"

#include <memory>
#include <string>
#include <utility>
#include <vector>

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
  const std::unique_ptr<domain::IBeverageBuilder> beverageBuilder =
      m_BeverageBuilderFactory->createBeverageBuilder(beverageVariety);
  if (!beverageBuilder)
  {
    return false; // Not a valid BeverageVariety value.
  }

  domain::BeverageBuildDirector director(*beverageBuilder);
  if (!director.buildBeverage(ingredients))
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
