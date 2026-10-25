#ifndef SCREEN_PRESENTER_HPP
#define SCREEN_PRESENTER_HPP

#include "Application/UseCases/IUseCaseOutputPort.hpp"
#include "Domain/Beverages/IBeverage.hpp"

#include <iostream>
#include <list>
#include <memory>

/// @brief Shows messages and orders on the screen.
class ScreenPresenter : public IUseCaseOutputPort
{
public:
  /// @brief Shows a message on its own line.
  /// @param message The text to show.
  void print(const std::string &message) override
  {
    std::cout << message << std::endl;
  };

  /// @brief Shows the orders, one per line.
  /// @param orderList The orders to show.
  void print(const std::list<std::unique_ptr<IBeverage>> &orderList) // override
  {
    for (const auto &beverage : orderList)
    {
      std::cout << beverage->getDescription() << std::endl;
    }
  }
};

#endif // SCREEN_PRESENTER_HPP