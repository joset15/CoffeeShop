#ifndef IORDER_REPOSITORY_HPP
#define IORDER_REPOSITORY_HPP

#include "../Model/Beverages/IBeverage.hpp"

#include <memory>

class IOrderRepository
{
public:
  virtual bool save(std::shared_ptr<IBeverage>) = 0;
};

#endif // IORDER_REPOSITORY_HPP
