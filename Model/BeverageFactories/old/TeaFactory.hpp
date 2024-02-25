#ifndef TEA_FACTORY_HPP
#define TEA_FACTORY_HPP

#include "IBeverageFactory.hpp"
#include <memory>

// TODO Complete doxygen comments.

class TeaFactory : IBeverageFactory
{
public:
  /// @brief
  TeaFactory() = default;

  /// @brief
  virtual ~TeaFactory() = default;

  /// @brief
  /// @return
  static CoffeeFactory *getInstance()
  {
    static TeaFactory m_TeaFactoryInstance;
    return &m_TeaFactoryInstance;
  }

  /// @brief
  /// @param beverageVariety
  /// @return
  std::shared_ptr<IBeverage>
  createBeverage(BeverageVariety beverageVariety) override;
};

#endif // TEA_FACTORY_HPP
