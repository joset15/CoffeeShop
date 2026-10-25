#ifndef IBEVERAGE_HPP
#define IBEVERAGE_HPP

#include <string>

// TODO Complete doxygen comments.

/// @brief The IBeverage class
class IBeverage
{
public:
  /// \brief ~IBeverage
  virtual ~IBeverage() = default;

  /// \brief
  [[nodiscard]] virtual std::string getDescription() const = 0;
};

#endif // IBEVERAGE_HPP
