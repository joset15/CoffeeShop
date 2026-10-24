#ifndef SCREEN_PRESENTER_HPP
#define SCREEN_PRESENTER_HPP

#pragma once

#include "Application/UseCases/IUseCaseOutputPort.hpp"
#include "Domain/Beverages/IBeverage.hpp"

#include <iostream>
#include <list>
#include <memory>

class ScreenPresenter : public IUseCaseOutputPort
{
public:
  void print(const std::string &message) override
  {
    std::cout << message << std::endl;
  };

  /// @brief
  /// @param orderList
  void print(const std::list<std::unique_ptr<IBeverage>> &orderList) // override
  {
    for (const auto &beverage : orderList)
    {
      std::cout << beverage->getDescription() << std::endl;
    }
  }
};

#endif // SCREEN_PRESENTER_HPP