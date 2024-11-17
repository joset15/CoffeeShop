#ifndef IUSE_CASE_INPUT_PORT_HPP
#define IUSE_CASE_INPUT_PORT_HPP

#pragma once

class IUseCaseInputPort
{
public:
  virtual ~IUseCaseInputPort() = default;

  virtual std::string read() = 0;
};

#endif // IUSE_CASE_INPUT_PORT_HPP