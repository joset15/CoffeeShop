#ifndef NEW_ORDER_REQ_HPP
#define NEW_ORDER_REQ_HPP

#pragma once

#include "IRequest.hpp"

#include "Domain/Beverages/BeverageVariety.hpp"
#include "Domain/Beverages/IBeverage.hpp"
#include "Domain/Ingredients/Ingredients.hpp"

#include "IOrderOutput.hpp"
#include "IOrderRepository.hpp"

#include <list>

struct NewOrderReq : IRequest
{
public:
  NewOrderReq() = delete;
  ~NewOrderReq(){};

  NewOrderReq(IBeverage::BeverageType beverageType,
              BeverageVariety beverageVariety,
              const std::list<Ingredient> &ingredients /*,
              IOrderOutput &output*/)
      // IOrderRepository &orderRepository)
      : m_BeverageType(beverageType), m_BeverageVariety(beverageVariety),
        m_Ingredients(ingredients) /*, m_Output(output)*/{};
  // m_OrderRepository(orderRepository){};

  IBeverage::BeverageType getBeverageType() const { return m_BeverageType; }
  BeverageVariety getBeverageVariety() const { return m_BeverageVariety; }
  const std::list<Ingredient> &getIngredients() const { return m_Ingredients; }

  // const std::string &name;
  // IOrderOutput &getOutput() const { return m_Output; }
  // IOrderRepository &getOrderRepository() const { return m_OrderRepository; };

private:
  IBeverage::BeverageType m_BeverageType;
  BeverageVariety m_BeverageVariety;
  std::list<Ingredient> m_Ingredients;

  // const std::string &name;
  // IOrderOutput &m_Output;
  // IOrderRepository &m_OrderRepository;
};

#endif // NEW_ORDER_REQ_HPP