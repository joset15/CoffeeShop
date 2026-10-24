#include "../include/BeverageBuildDirector_TestFixtures.hpp"

namespace CoffeeShop
{
TEST_F(GivenADirectorWithoutBuilder, WhenBuildingThenReturnsFalse)
{
  // AAA: Arrange, Act, Assert
  // Act
  bool espressoBuilt = m_Director.buildCoffeeEspresso({Ingredient::Sugar});
  bool teaBuilt = m_Director.buildTeaBlack({Ingredient::Sugar});

  // Assert
  ASSERT_FALSE(espressoBuilt);
  ASSERT_FALSE(teaBuilt);
}
} // namespace CoffeeShop
