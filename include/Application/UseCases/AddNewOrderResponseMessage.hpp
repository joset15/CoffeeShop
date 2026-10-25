#ifndef ADD_NEW_ORDER_RESPONSE_MESSAGE_HPP
#define ADD_NEW_ORDER_RESPONSE_MESSAGE_HPP

#include "ResponseMessage.hpp"

#include <string>
#include <vector>

class AddNewOrderResponseMessage : public ResponseMessage
{
public:
  AddNewOrderResponseMessage(bool success, const std::string &message = "")
      : ResponseMessage(success, message)
  {
  }

  AddNewOrderResponseMessage() : ResponseMessage(false, "") {}

  void setErrors(const std::vector<std::string> &errors) { m_Errors = errors; }
  [[nodiscard]] std::vector<std::string> getErrors() const { return m_Errors; }

private:
  std::vector<std::string> m_Errors;
};

#endif // ADD_NEW_ORDER_RESPONSE_MESSAGE_HPP