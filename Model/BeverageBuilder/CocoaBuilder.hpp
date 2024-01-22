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
  std::shared_ptr<IBeverage> getBeverage() override{};

  /// @brief
  void reset() override
  {
    m_Beverage = std::make_shared<Cocoa>();
    m_HasMilk = false;
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
  void addLemon() override{};

  /// @brief Adds water to the beverage.
  void addWater() override{};

protected:
  /// @brief
  bool m_HasMilk = false;
};

#endif // COCOA_BUILDER_HPP