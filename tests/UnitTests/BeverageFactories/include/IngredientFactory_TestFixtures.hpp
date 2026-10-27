#ifndef INGREDIENT_FACTORY_TESTFIXTURES_HPP
#define INGREDIENT_FACTORY_TESTFIXTURES_HPP

#include "Domain/BeverageFactories/IngredientFactory.hpp"
#include "Domain/Ingredients/Ingredient.hpp"

#include <gtest/gtest.h>

#include <string_view>
#include <tuple>

namespace coffee_shop::domain
{
///
/// \brief A fixture for each ingredient and the name it adds to a description.
///
class GivenAnIngredient
    : public ::testing::TestWithParam<std::tuple<Ingredient, std::string_view>>
{
protected:
  IngredientFactory m_IngredientFactory;
};
} // namespace coffee_shop::domain

#endif // INGREDIENT_FACTORY_TESTFIXTURES_HPP
