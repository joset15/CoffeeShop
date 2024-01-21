#ifndef TEA_BUILDER_HPP
#define TEA_BUILDER_HPP
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
  std::shared_ptr<IBeverage> getBeverage() override { return m_Beverage; }

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
  void addMilk(Ingredient typeOfMilk) override;

  /// @brief Adds honey to the beverage.
  void addHoney() override
  {
    m_Beverage = std::make_shared<Honey>(m_Beverage);
  };

  /// @brief Adds lemon to the beverage.
  void addLemon() override;

  /// @brief Adds water to the beverage.
  void addWater() override{};

protected:
  /// @brief
  bool m_HasMilk = false;

  /// @brief
  bool m_HasLemon = false;
};

#endif // TEA_BUILDER_HPP