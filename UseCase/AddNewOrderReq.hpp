#ifndef ADD_NEW_ORDER_REQ_HPP
#define ADD_NEW_ORDER_REQ_HPP

#pragma once

#include "IRequest.hpp"

#include "../Model/Beverages/BeverageVariety.hpp"
#include "../Model/Beverages/IBeverage.hpp"
#include "../Model/Ingredient/Ingredients.hpp"

#include "IOrderOutput.hpp"
#include "IOrderRepository.hpp"

#include <list>

struct AddNewOrderReq : IRequest
{
public:
  AddNewOrderReq() = delete;
  ~AddNewOrderReq(){};

  AddNewOrderReq(IBeverage::BeverageType beverageType,
                 BeverageVariety beverageVariety,
                 const std::list<Ingredient> &ingredients, IOrderOutput &output,
                 IOrderRepository &orderRepository)
      : m_BeverageType(beverageType), m_BeverageVariety(beverageVariety),
        m_Ingredients(ingredients), m_Output(output),
        m_OrderRepository(orderRepository){};

  IBeverage::BeverageType getBeverageType() const { return m_BeverageType; }
  BeverageVariety getBeverageVariety() const { return m_BeverageVariety; }
  const std::list<Ingredient> &getIngredients() const { return m_Ingredients; }

  // const std::string &name;
  IOrderOutput &getOutput() const { return m_Output; }
  IOrderRepository &getOrderRepository() const { return m_OrderRepository; };

private:
  IBeverage::BeverageType m_BeverageType;
  BeverageVariety m_BeverageVariety;
  const std::list<Ingredient> &m_Ingredients;

  // const std::string &name;
  IOrderOutput &m_Output;
  IOrderRepository &m_OrderRepository;
};

#endif // ADD_NEW_ORDER_REQ_HPP