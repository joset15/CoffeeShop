#ifndef TEXT_PRESENTER_TESTFIXTURES_HPP
#define TEXT_PRESENTER_TESTFIXTURES_HPP

#include "InterfaceAdapters/TextPresenter.hpp"

#include <gtest/gtest.h>
#include <sstream>

namespace coffee_shop
{
///
/// \brief A fixture for a presenter that writes to a string.
///
class GivenATextPresenter : public ::testing::Test
{
protected:
  std::ostringstream m_Output;
  TextPresenter m_Presenter{m_Output};
};
} // namespace coffee_shop

#endif // TEXT_PRESENTER_TESTFIXTURES_HPP
