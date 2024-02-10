#ifndef COCOA_BUILDER_HPP
#define COCOA_BUILDER_HPP
#pragma once

#include "../Beverages/Cocoa.hpp"
#include "IBeverageBuilder.hpp"

#include <assert.h>

class CocoaBuilder : public IBeverageBuilder
{
public:
  CocoaBuilder() { reset(); }

  /// @brief Gets the beverage.
  /// @return A pointer to the beverage.
  std::shared_ptr<IBeverage> getBeverage() override { return m_Beverage; }

  /// @brief
  void reset() override
  {
    m_Beverage = std::make_shared<Cocoa>();
    m_HasMilk = false;
  }

  /// @brief Adds sugar to the beverage.
  bool addSugar() override
  {
    m_Beverage = std::make_shared<Sugar>(m_Beverage);
    return true;
  };

  /// @brief Adds milk to the beverage.
  /// @param typeOfMilk The type of milk we are adding.
  bool addMilk(Ingredient typeOfMilk) override;

  /// @brief Adds honey to the beverage.
  bool addHoney() override
  {
    m_Beverage = std::make_shared<Honey>(m_Beverage);
    return true;
  };

  /// @brief Adds lemon to the beverage.
  bool addLemon() override { return false; }

  /// @brief Adds water to the beverage.
  bool addWater() override { return false; }

protected:
  /// @brief
  bool m_HasMilk = false;
};

#endif // COCOA_BUILDER_HPP