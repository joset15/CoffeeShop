#ifndef TEA_HPP
#define TEA_HPP

#include "IBeverage.hpp"

class Tea : public IBeverage
{
public:
  /// @brief
  Tea() = default;

  /// @brief
  /// @return
  [[nodiscard]] std::string getDescription() const override { return "Tea"; }
};

#endif // TEA_HPP
