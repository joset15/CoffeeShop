#include "../include/ConsoleMenu_TestFixtures.hpp"

#include <list>

namespace coffee_shop
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
  ASSERT_EQ(variety, BeverageVariety::Cocoa);
}

TEST_F(GivenAConsoleMenu, WhenInvalidBeverageIsEnteredThenItAsksAgain)
{
  // AAA: Arrange, Act, Assert
  // Arrange
  ConsoleMenu menu = menuWithInput("abc\n9\n4\n");

  // Act
  auto variety = menu.askBeverageVariety();

  // Assert
  ASSERT_EQ(variety, BeverageVariety::TeaBlack);
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
            (std::list<Ingredient>{Ingredient::Sugar, Ingredient::Milk}));
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
  ASSERT_EQ(ingredients, (std::list<Ingredient>{Ingredient::Lemon}));
}
} // namespace coffee_shop
