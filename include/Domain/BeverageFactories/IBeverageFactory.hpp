#ifndef IBEVERAGE_FACTORY_HPP
#define IBEVERAGE_FACTORY_HPP

#include "../Beverages/BeverageVariety.hpp"
#include "../Beverages/IBeverage.hpp"
#include <memory>

// TODO Complete doxygen comments.

/// @brief The IBeverageFactory class
class IBeverageFactory
{
public:
  /// @brief
  virtual ~IBeverageFactory() = default;

  /// @brief
  /// @param beverageVariety
  /// @return
  virtual std::unique_ptr<IBeverage>
  createBeverage(BeverageVariety beverageVariety) = 0;
};

#endif // IBEVERAGE_FACTORY_HPP
