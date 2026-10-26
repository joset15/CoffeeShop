#ifndef USECASE_HPP
#define USECASE_HPP

#include <string>
#include <utility>

namespace coffee_shop::application
{
/// @brief Base class of the application use cases.
class UseCase
{
public:
  /// @brief Destructor for an UseCase.
  virtual ~UseCase() = default;

  /// @brief Get the name of the UseCase.
  /// @return UseCaseName
  [[nodiscard]] const std::string &getName() const { return m_UseCaseName; }

  /// @brief Get the success execution status of the UseCase. This method should
  /// be overwritten in derived classes.Default implementation always indicates
  /// success.
  /// @return bool indicating the success (true) or not (false) of the UseCase
  /// execution.
  virtual bool isSucceed() { return true; }

  /// @brief Get the execution state of the UseCase. This method should be
  /// overwritten in derived classes.Default implementation always indicates
  /// finished.
  /// @return bool indicating the ending (true) or not (false) of the UseCase
  /// execution.
  virtual bool isFinished() { return true; }

  /// @brief Runs the use case.
  /// @return True if it succeeded.
  // TODO: Return an error code instead of a bool.
  virtual bool execute() = 0;

protected:
  /// @brief Protected constructor for an UseCase given its name.
  /// @param useCaseName The name of the use case.
  explicit UseCase(std::string useCaseName)
      : m_UseCaseName(std::move(useCaseName))
  {
  }

private:
  /// @brief Set once at construction (private, no setter).
  std::string m_UseCaseName;
};
} // namespace coffee_shop::application

#endif // USECASE_HPP
