#ifndef IBEVERAGE_HPP
#define IBEVERAGE_HPP

#include "BeverageVariety.hpp"
#include "Ingredient.hpp"

#include <unordered_set>

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

  /// \brief IBeverage
  IBeverage() = delete;

  /// \brief IBeverage
  /// \param beverageVariety
  IBeverage(BeverageVariety beverageVariety)
      : m_BeverageVariety(beverageVariety){};

  /// \brief ~IBeverage
  virtual ~IBeverage(){};

  ///
  /// \brief AddExtraIngredient
  /// \param extraIngredient
  /// \return
  ///
  virtual bool addExtraIngredient(Ingredient extraIngredient) = 0;

  /// \brief
  virtual std::string description() const = 0;

protected:
  /// \brief
  BeverageVariety m_BeverageVariety;

  /// \brief
  std::unordered_set<Ingredient> m_ExtraIngredientSet{};
};

#endif // IBEVERAGE_HPP
