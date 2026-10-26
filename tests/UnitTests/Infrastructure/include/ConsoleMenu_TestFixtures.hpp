#ifndef CONSOLE_MENU_TESTFIXTURES_HPP
#define CONSOLE_MENU_TESTFIXTURES_HPP

#include "Infrastructure/UI/ConsoleMenu.hpp"

#include <gtest/gtest.h>
#include <sstream>
#include <string>

namespace coffee_shop::infrastructure::ui
{
///
/// \brief A fixture for a console menu that reads from a string.
///
class GivenAConsoleMenu : public ::testing::Test
{
protected:
  /// @brief Creates a menu that reads the given text as the user's input.
  ConsoleMenu menuWithInput(const std::string &text)
  {
    m_Input.str(text);
    m_Input.clear();
    return {m_Input, m_Output};
  }

  std::istringstream m_Input;
  std::ostringstream m_Output;
};
} // namespace coffee_shop::infrastructure::ui

#endif // CONSOLE_MENU_TESTFIXTURES_HPP
