#ifndef IREQUEST_HPP
#define IREQUEST_HPP

/// @brief Base type of the data sent to a use case.
struct IRequest
{
public:
  /// @brief Destructor for an IRequest.
  virtual ~IRequest() = default;
};

#endif // IREQUEST_HPP