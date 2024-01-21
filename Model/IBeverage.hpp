#ifndef IBEVERAGE_HPP
#define IBEVERAGE_HPP

//#include "BeverageVariety.hpp"
//#include "Ingredient/IngredientDecorator.hpp"

#include <unordered_set>

// TODO Complete doxygen comments.

enum class Ingredient
{
  Sugar,
  Milk,
  Cream,
  Honey,
  Lemon,
  SoyMilk,
  Water,
  LastIngredient
};

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
  // IBeverage() = delete;

  /// \brief IBeverage
  /// \param beverageVariety
  // IBeverage(BeverageVariety beverageVariety)
  //    : m_BeverageVariety(beverageVariety){};
  // IBeverage();

  /// \brief ~IBeverage
  virtual ~IBeverage(){};

  ///
  /// \brief AddExtraIngredient
  /// \param extraIngredient
  /// \return
  ///
  // virtual bool addExtraIngredient(IngredientDecorator extraIngredient) = 0;

  /// \brief
  virtual std::string getDescription() const = 0;

  ///
  /// \brief AddIngredients
  /// \return
  ///
  // virtual bool addIngredient(std::shared_ptr<IBeverage> ingredient)
  virtual bool addIngredient(IBeverage *ingredient) { return false; }

  // virtual bool prepare(std::shared_ptr<IBeverage> beverage) { return false; }

  Ingredient m_Ingredient = Ingredient::LastIngredient;

protected:
  /// \brief
  // BeverageVariety m_BeverageVariety;

  /// \brief
  // std::unordered_set<Ingredient> m_ExtraIngredientSet{};
};

#endif // IBEVERAGE_HPP
