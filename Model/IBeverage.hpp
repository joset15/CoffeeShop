#ifndef IBEVERAGE_HPP
#define IBEVERAGE_HPP

#include <string>

// TODO Complete doxygen comments.

///
/// \brief The IBeverage class
///
class IBeverage
{
public:
  /// \brief The BeverageType enum
  enum class BeverageType
  {
    Coffee,
    Tea,
    Cocoa
  };

  /// \brief ~IBeverage
  virtual ~IBeverage(){};

  /// \brief
  virtual std::string getDescription() const = 0;

  ///
  /// \brief AddIngredients
  /// \return
  ///
  // virtual bool addIngredient(std::shared_ptr<IBeverage> ingredient)
  virtual bool addIngredient(IBeverage *ingredient) { return false; }
};

#endif // IBEVERAGE_HPP
