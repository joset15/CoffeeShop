#ifndef MILK_HPP
#define MILK_HPP
#pragma once

#include "IngredientDecorator.hpp"

#include <string>
#include <string_view>

/// @brief The name of this ingredient in descriptions.
inline constexpr std::string_view MilkName = "Milk";

class Milk : public IngredientDecorator
{
public:
  /// @brief Takes ownership of the beverage to decorate.
  using IngredientDecorator::IngredientDecorator;

  /// @brief Gets the description of the ingredient.
  /// @return The description.
  [[nodiscard]] std::string getDescription() const override
  {
    return describeWith(MilkName);
  }
};

#endif // MILK_HPP
