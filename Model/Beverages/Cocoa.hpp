#ifndef COCOA_HPP
#define COCOA_HPP

//#include "BeverageVariety.hpp"
#include "IBeverage.hpp"

//#include <list>

class Cocoa : public IBeverage
{
public:
  /// \brief
  Cocoa(){};

  std::string getDescription() const override { return "Cocoa"; }
};

#endif // COCOA_HPP
