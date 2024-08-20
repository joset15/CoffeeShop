#ifndef RESPONSE_MESSAGE_HPP
#define RESPONSE_MESSAGE_HPP

#pragma once

#include <string>

class ResponseMessage
{
public:
  bool getSuccess() const { return Success; };
  std::string getMessage() const { return Message; };

protected:
  ResponseMessage(bool success, const std::string &message = "")
  {
    setSuccess(success);
    setMessage(message);
  }

private:
  void setSuccess(bool value) { Success = value; };
  void setMessage(const std::string &value) { Message = value; };

  bool Success = false;
  std::string Message;
};

#endif // RESPONSE_MESSAGE_HPP