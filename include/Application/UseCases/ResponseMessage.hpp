#ifndef RESPONSE_MESSAGE_HPP
#define RESPONSE_MESSAGE_HPP

#include <string>

class ResponseMessage
{
public:
  [[nodiscard]] bool getSuccess() const { return m_Success; };
  [[nodiscard]] std::string getMessage() const { return m_Message; };

protected:
  ResponseMessage(bool success, const std::string &message = "")
  {
    setSuccess(success);
    setMessage(message);
  }

private:
  void setSuccess(bool value) { m_Success = value; };
  void setMessage(const std::string &value) { m_Message = value; };

  bool m_Success = false;
  std::string m_Message;
};

#endif // RESPONSE_MESSAGE_HPP