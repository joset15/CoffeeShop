#ifndef IREQUEST_HPP
#define IREQUEST_HPP
#pragma once

struct IRequest
{
  //    // Disallow copy constructor.
  //    UseCase(const UseCase &);
  //    // Disallow assignment operator.
  //    void operator=(const UseCase &);

public:
  /// @brief Destructor for an IRequest.
  virtual ~IRequest() = default;
};

#endif // IREQUEST_HPP