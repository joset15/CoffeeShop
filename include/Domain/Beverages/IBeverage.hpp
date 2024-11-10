#ifndef IBEVERAGE_HPP
#define IBEVERAGE_HPP

#include <string>

// TODO Complete doxygen comments.

/// @brief The IBeverage class
class IBeverage
{
public:
  // TODO Remove BeverageType
  /// @brief The BeverageType enum
  enum class BeverageType
  {
    Coffee,
    Tea,
    Cocoa
  };

  /// \brief ~IBeverage
  virtual ~IBeverage() = default;

  /// \brief
  virtual std::string getDescription() const = 0;
};

#endif // IBEVERAGE_HPP
