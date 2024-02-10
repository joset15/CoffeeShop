#ifndef TEA_BUILDER_HPP
#define TEA_BUILDER_HPP
#pragma once

#include "../Beverages/Tea.hpp"
#include "IBeverageBuilder.hpp"

#include <assert.h>

class TeaBuilder : public IBeverageBuilder
{
public:
  TeaBuilder() { resetImpl(); }

  /// @brief Gets the beverage.
  /// @return A pointer to the beverage.
  std::shared_ptr<IBeverage> getBeverage() override { return m_Beverage; }

  /// @brief
  void reset() override { resetImpl(); }

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
  bool addLemon() override;

  /// @brief Adds water to the beverage.
  bool addWater() override { return false; }

  /// @brief
  /// @param hasMilk
  void setHasMilk(bool hasMilk) { m_HasMilk = hasMilk; }

  /// @brief
  /// @param hasLemon
  void setHasLemon(bool hasLemon) { m_HasLemon = hasLemon; }

private:
  void resetImpl();

  /// @brief
  bool m_HasMilk = false;

  /// @brief
  bool m_HasLemon = false;
};

#endif // TEA_BUILDER_HPP