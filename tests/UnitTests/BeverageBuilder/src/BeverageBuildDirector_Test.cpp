#include "../include/BeverageBuildDirector_TestFixtures.hpp"

namespace coffee_shop::domain
{
TEST_F(GivenADirectorWithoutBuilder, WhenBuildingThenReturnsFalse)
{
  // AAA: Arrange, Act, Assert
  // Act
  const bool built = m_Director.buildBeverage({Ingredient::Sugar});

  // Assert
  ASSERT_FALSE(built);
}
} // namespace coffee_shop::domain
