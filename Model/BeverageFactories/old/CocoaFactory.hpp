#ifndef COCOA_FACTORY_HPP
#define COCOA_FACTORY_HPP

#include "IBeverageFactory.hpp"
#include <memory>

// TODO Complete doxygen comments.

class CocoaFactory : IBeverageFactory
{
public:
  /// @brief
  CocoaFactory() = default;

  /// @brief
  virtual ~CocoaFactory() = default;

  /// @brief
  /// @return
  static CocoaFactory *getInstance()
  {
    static CocoaFactory m_CocoaFactoryInstance;
    return &m_CocoaFactoryInstance;
  }

  /// @brief
  /// @param beverageVariety
  /// @return
  std::shared_ptr<IBeverage> createBeverage(BeverageVariety beverageVariety);
};

#endif // COCOA_FACTORY_HPP
