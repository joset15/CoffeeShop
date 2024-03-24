#ifndef ADD_NEW_ORDER_UC_HPP
#define ADD_NEW_ORDER_UC_HPP

#include "UseCase.hpp"

#include "../Model/Beverages/BeverageVariety.hpp"
#include "../Model/Beverages/IBeverage.hpp"
#include "../Model/Ingredient/Ingredients.hpp"

#include "IOrderOutput.hpp"
#include "IOrderRepository.hpp"

class AddNewOrderUC : public UseCase
{
public:
  AddNewOrderUC(const std::string &name, IOrderOutput &output, IOrderRepository &orderRepository)
      : UseCase(name), m_Output(output), m_OrderRepository(orderRepository){};

  bool addNewOrder(IBeverage::BeverageType beverageType,
                   BeverageVariety beverageVariety,
                   const std::list<Ingredient> &ingredients);

private:
  IOrderOutput &m_Output;

  IOrderRepository &m_OrderRepository;
};

#endif // ADD_NEW_ORDER_UC_HPP
