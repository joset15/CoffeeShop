#include "../include/ConsoleMenu_TestFixtures.hpp"

#include "Domain/Beverages/BeverageVariety.hpp"
#include "Domain/Ingredients/Ingredient.hpp"

#include "Infrastructure/UI/ConsoleMenu.hpp"

#include <gtest/gtest.h>

#include <vector>

namespace coffee_shop::infrastructure::ui
{
TEST_F(GivenAConsoleMenu, WhenMainOptionIsEnteredThenItIsReturned)
{
  // AAA: Arrange, Act, Assert
  // Arrange
  ConsoleMenu menu = menuWithInput("2\n");

  // Act
  auto option = menu.askMainOption();

  // Assert
  ASSERT_EQ(option, ConsoleMenu::MainOption::ScreenListOrders);
}

TEST_F(GivenAConsoleMenu, WhenInputEndsThenNoMainOptionIsReturned)
{
  // AAA: Arrange, Act, Assert
  // Arrange
  ConsoleMenu menu = menuWithInput("");

  // Act
  auto option = menu.askMainOption();

  // Assert
  ASSERT_FALSE(option.has_value());
}

TEST_F(GivenAConsoleMenu, WhenBeverageNumberIsEnteredThenThatVarietyIsReturned)
{
  // AAA: Arrange, Act, Assert
  // Arrange
  ConsoleMenu menu = menuWithInput("6\n");

  // Act
  auto variety = menu.askBeverageVariety();

  // Assert
  ASSERT_EQ(variety, domain::BeverageVariety::Cocoa);
}

TEST_F(GivenAConsoleMenu, WhenInvalidBeverageIsEnteredThenItAsksAgain)
{
  // AAA: Arrange, Act, Assert
  // Arrange
  ConsoleMenu menu = menuWithInput("abc\n9\n4\n");

  // Act
  auto variety = menu.askBeverageVariety();

  // Assert
  ASSERT_EQ(variety, domain::BeverageVariety::TeaBlack);
  ASSERT_NE(m_Output.str().find("Please enter a number between 0 and 6."),
            std::string::npos);
}

TEST_F(GivenAConsoleMenu, WhenZeroIsEnteredThenBeverageChoiceIsCancelled)
{
  // AAA: Arrange, Act, Assert
  // Arrange
  ConsoleMenu menu = menuWithInput("0\n");

  // Act
  auto variety = menu.askBeverageVariety();

  // Assert
  ASSERT_FALSE(variety.has_value());
}

TEST_F(GivenAConsoleMenu, WhenIngredientNumbersAreEnteredThenThoseAreReturned)
{
  // AAA: Arrange, Act, Assert
  // Arrange
  ConsoleMenu menu = menuWithInput("1 2\n");

  // Act
  auto ingredients = menu.askIngredients();

  // Assert
  ASSERT_EQ(ingredients,
            (std::vector<domain::Ingredient>{domain::Ingredient::Sugar,
                                             domain::Ingredient::Milk}));
}

TEST_F(GivenAConsoleMenu, WhenEmptyLineIsEnteredThenNoIngredientsAreReturned)
{
  // AAA: Arrange, Act, Assert
  // Arrange
  ConsoleMenu menu = menuWithInput("\n");

  // Act
  auto ingredients = menu.askIngredients();

  // Assert
  ASSERT_TRUE(ingredients.empty());
}

TEST_F(GivenAConsoleMenu, WhenInvalidIngredientIsEnteredThenItAsksAgain)
{
  // AAA: Arrange, Act, Assert
  // Arrange
  ConsoleMenu menu = menuWithInput("1 x\n5\n");

  // Act
  auto ingredients = menu.askIngredients();

  // Assert
  ASSERT_EQ(ingredients,
            (std::vector<domain::Ingredient>{domain::Ingredient::Lemon}));
}
TEST_F(GivenAConsoleMenu, WhenInputEndsWithoutAValidAnswerThenNoIngredients)
{
  // AAA: Arrange, Act, Assert
  // Arrange
  ConsoleMenu menu = menuWithInput("9\n");

  // Act
  const std::vector<domain::Ingredient> ingredients = menu.askIngredients();

  // Assert
  ASSERT_TRUE(ingredients.empty());
  ASSERT_NE(m_Output.str().find("Please enter numbers"), std::string::npos);
}

TEST_F(GivenAConsoleMenu, WhenWaitingForEnterThenOnlyOneLineIsRead)
{
  // AAA: Arrange, Act, Assert
  // Arrange
  ConsoleMenu menu = menuWithInput("\n2\n");

  // Act
  menu.waitForEnter();
  const auto option = menu.askMainOption();

  // Assert
  ASSERT_NE(m_Output.str().find("Press Enter to continue"), std::string::npos);
  ASSERT_EQ(option, ConsoleMenu::MainOption::ScreenListOrders);
}
} // namespace coffee_shop::infrastructure::ui
