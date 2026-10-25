#ifndef IUSE_CASE_OUTPUT_PORT_HPP
#define IUSE_CASE_OUTPUT_PORT_HPP

class IUseCaseOutputPort
{
public:
  virtual ~IUseCaseOutputPort() = default;

  virtual void print(const std::string &message) = 0;
};

#endif // IUSE_CASE_OUTPUT_PORT_HPP