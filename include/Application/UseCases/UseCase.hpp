#ifndef USECASE_HPP
#define USECASE_HPP

//#include "IRequest.hpp"
#include <string>

class UseCase
{
  //    // Disallow copy constructor.
  //    UseCase(const UseCase &);
  //    // Disallow assignment operator.
  //    void operator=(const UseCase &);

public:
  /// @brief Destructor for an UseCase.
  virtual ~UseCase(){};

  /// @brief Get the name of the UseCase.
  /// @return UseCaseName
  const std::string &getName() const { return m_UseCaseName; }

  /// @brief Get the success execution status of the UseCase. This method should
  /// be overwritten in derived classes.Default implementation always indicates
  /// success.
  /// @return bool indicating the success (true) or not (false) of the UseCase
  /// execution.
  virtual const bool isSucceed() { return true; }

  /// @brief Get the execution state of the UseCase. This method should be
  /// overwritten in derived classes.Default implementation always indicates
  /// finished.
  /// @return bool indicating the ending (true) or not (false) of the UseCase
  /// execution.
  virtual const bool isFinished() { return true; }

  // TODO return ErrorCode
  // virtual bool execute(const IRequest &request) = 0;
  virtual bool execute() = 0;

protected:
  /// @brief Protected constructor for an UseCase given its UseCaseName.
  /// @param UseCaseName
  explicit UseCase(const std::string &UseCaseName) : m_UseCaseName(UseCaseName)
  {
  }

private:
  const std::string m_UseCaseName;
};

#endif // USECASE_HPP
