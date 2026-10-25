#ifndef COCOA_HPP
#define COCOA_HPP

#include "IBeverage.hpp"
#include <string>
#include <string_view>

/// @brief The name of this beverage in descriptions.
inline constexpr std::string_view CocoaName = "Cocoa";

class Cocoa : public IBeverage
{
public:
  Cocoa() = default;

  [[nodiscard]] std::string getDescription() const override
  {
    return std::string(CocoaName);
  }
};

#endif // COCOA_HPP
