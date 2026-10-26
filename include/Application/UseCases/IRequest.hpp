#ifndef IREQUEST_HPP
#define IREQUEST_HPP

namespace coffee_shop::application
{
/// @brief Base type of the data sent to a use case.
struct IRequest
{
public:
  /// @brief Destructor for an IRequest.
  virtual ~IRequest() = default;
};
} // namespace coffee_shop::application

#endif // IREQUEST_HPP