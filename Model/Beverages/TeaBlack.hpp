#ifndef TEA_BLACK_HPP
#define TEA_BLACK_HPP

#include "Tea.hpp"
#include <string>

static const std::string TeaBlackName = "TeaBlack";

class TeaBlack : public Tea
{
public:
  /// @brief
  TeaBlack() = default;

  /// @brief
  /// @return
  std::string getDescription() const override { return TeaBlackName; }
};

#endif // TEA_BLACK_HPP
