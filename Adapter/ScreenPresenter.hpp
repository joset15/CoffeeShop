#ifndef SCREEN_PRESENTER_HPP
#define SCREEN_PRESENTER_HPP

#pragma once

#include "Model/Beverages/IBeverage.hpp"
#include "UseCase/IUseCaseOutputPort.hpp"

#include <iostream>
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
  void print(const std::list<std::shared_ptr<IBeverage>> &orderList) // override
  {
    for (auto &&beverage : orderList)
    {
      std::cout << beverage->getDescription() << std::endl;
    }
  }
};

#endif // SCREEN_PRESENTER_HPP