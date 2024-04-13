#ifndef IREQUEST_HANDLER_HPP
#define IREQUEST_HANDLER_HPP

#pragma once

#include <concepts>

// namespace CleanArchitecture::Core::Contracts
{
  /// <summary>
  /// Defines a handler for a request
  /// </summary>
  /// <typeparam name="TRequest">The type of request being handled</typeparam>
  /// <typeparam name="TResponse">The type of response from the
  /// handler</typeparam>
  template <typename TRequest, typename TResponse>
  requires std::derived_from<TRequest, IRequest<TResponse>>
  // C# TO C++ CONVERTER TASK: C++ does not allow specifying covariance or
  // contravariance in a generic type list: ORIGINAL LINE: public interface
  // IRequestHandler<in TRequest, out TResponse> where TRequest :
  // IRequest<TResponse>
  class IRequestHandler
  {
    /// <summary>
    /// Handles a request
    /// </summary>
    /// <param name="message">The request message</param>
    /// <returns>Response from the request</returns>
  public:
    virtual TResponse Handle(TRequest message) = 0;
  };

  /// <summary>
  /// Defines a handler for a request without a return value
  /// </summary>
  /// <typeparam name="TRequest">The type of request being handled</typeparam>
  template <typename TRequest>
  requires std::derived_from<TRequest, IRequest>
  // C# TO C++ CONVERTER TASK: C++ does not allow specifying covariance or
  // contravariance in a generic type list: ORIGINAL LINE: public interface
  // IRequestHandler<in TRequest> where TRequest : IRequest
  class IRequestHandler
  {
    /// <summary>
    /// Handles a request
    /// </summary>
    /// <param name="message">The request message</param>
  public:
    virtual void Handle(TRequest message) = 0;
  };
  //}

#endif // IREQUEST_HANDLER_HPP