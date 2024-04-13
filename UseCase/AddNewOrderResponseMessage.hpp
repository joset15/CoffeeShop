#ifndef ADD_NEW_ORDER_RESPONSE_MESSAGE_HPP
#define ADD_NEW_ORDER_RESPONSE_MESSAGE_HPP
#pragma once

#include "ResponseMessage.hpp"

#include <string>
#include <vector>

class CourseRegistrationResponseMessage : public ResponseMessage
{
private:
  std::vector<std::wstring> Errors;

public:
  std::vector<std::wstring> getErrors() const;

private:
  void setErrors(const std::vector<std::wstring> &value);

public:
  CourseRegistrationResponseMessage(bool success,
                                    std::vector<std::wstring> &errors,
                                    const std::wstring &message = L"");
};

// .cpp file code:

#include "snippet.h"

std::vector<std::wstring> CourseRegistrationResponseMessage::getErrors() const
{
  return Errors;
}

void CourseRegistrationResponseMessage::setErrors(
    const std::vector<std::wstring> &value)
{
  Errors = value;
}

CourseRegistrationResponseMessage::CourseRegistrationResponseMessage(
    bool success, std::vector<std::wstring> &errors,
    const std::wstring &message)
    : ResponseMessage(success, message)
{
  setErrors(errors);
}

#endif // ADD_NEW_ORDER_RESPONSE_MESSAGE_HPP