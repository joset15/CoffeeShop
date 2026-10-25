#ifndef WATER_HPP
#define WATER_HPP
#pragma once

#include "IngredientDecorator.hpp"

#include <string>
#include <string_view>

/// @brief The name of this ingredient in descriptions.
inline constexpr std::string_view WaterName = "Water";

class Water : public IngredientDecorator
{
public:
  /// @brief Takes ownership of the beverage to decorate.
  using IngredientDecorator::IngredientDecorator;

  /// @brief Gets the description of the ingredient.
  /// @return The description.
  [[nodiscard]] std::string getDescription() const override
  {
    return describeWith(WaterName);
  }
};

#endif // WATER_HPP
