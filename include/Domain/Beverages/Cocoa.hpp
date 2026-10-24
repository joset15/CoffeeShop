#ifndef COCOA_HPP
#define COCOA_HPP

#include "IBeverage.hpp"
#include <string>

static const std::string CocoaName = "Cocoa";

class Cocoa : public IBeverage
{
public:
  Cocoa() = default;

  [[nodiscard]] std::string getDescription() const override
  {
    return CocoaName;
  }
};

#endif // COCOA_HPP
