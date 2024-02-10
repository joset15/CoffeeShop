#ifndef TEA_BLACK_HPP
#define TEA_BLACK_HPP

#include "IBeverage.hpp"

class TeaBlack : public IBeverage
{
public:
  /// @brief
  TeaBlack() = default;

  /// @brief
  /// @return
  std::string getDescription() const override { return "TeaBlack"; }
};

#endif // TEA_BLACK_HPP
