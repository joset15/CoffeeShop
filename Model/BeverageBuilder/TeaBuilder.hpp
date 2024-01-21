#ifndef TEABUILDER_HPP
#define TEABUILDER_HPP
#pragma once

#include "../Tea.hpp"
#include "IBeverageBuilder.hpp"

#include <assert.h>

class TeaBuilder : public IBeverageBuilder
{
public:
  TeaBuilder() { reset(); }

  /// @brief Gets the beverage.
  /// @return A pointer to the beverage.
  std::shared_ptr<IBeverage> getBeverage() override{};

  /// @brief
  void reset() override
  {
    m_Beverage = std::make_shared<Tea>();
    m_HasMilk = false;
    m_HasLemon = false;
  }

  /// @brief Adds sugar to the beverage.
  void addSugar() override
  {
    m_Beverage = std::make_shared<Sugar>(m_Beverage);
  };

  /// @brief Adds milk to the beverage.
  /// @param typeOfMilk The type of milk we are adding.
  void addMilk(Ingredient typeOfMilk) override
  {
    if (m_HasLemon || m_HasMilk)
    {
      return;
    }

    switch (typeOfMilk)
    {
    case Ingredient::Milk:
      m_Beverage = std::make_shared<Milk>(m_Beverage);
      m_HasMilk = true;
      break;
    case Ingredient::Cream:
      m_Beverage = std::make_shared<Cream>(m_Beverage);
      m_HasMilk = true;
      break;
    case Ingredient::SoyMilk:
      m_Beverage = std::make_shared<SoyMilk>(m_Beverage);
      m_HasMilk = true;
      break;
    default:
      assert(false && "Invalid type of milk");
    }
  };

  /// @brief Adds honey to the beverage.
  void addHoney() override
  {
    m_Beverage = std::make_shared<Honey>(m_Beverage);
  };

  /// @brief Adds lemon to the beverage.
  void addLemon() override
  {
    if (m_HasMilk)
    {
      return;
    }

    m_Beverage = std::make_shared<Lemon>(m_Beverage);
    m_HasLemon = true;
  };

protected:
  /// @brief
  bool m_HasMilk = false;

  /// @brief
  bool m_HasLemon = false;
};

#endif // COFFEEBUILDER_HPP