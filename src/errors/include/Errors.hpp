/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-tekspice-hippolyte.david
** File description:
** errors
*/

#ifndef ERRORS_HPP_
#define ERRORS_HPP_

#include <exception>
#include <string>

namespace nts {
class ParsingError : public std::exception {
  public:
    ParsingError(const char* type);
    ~ParsingError() override = default;
    const char* what() const noexcept override;

  private:
    const char* type;
};

class ComputeError : public std::exception {
  public:
    ComputeError(const char* type);
    ~ComputeError() override = default;
    const char* what() const noexcept override;

  private:
    const char* type;
};

class MappingError : public std::exception {
  public:
    MappingError(const char* type);
    ~MappingError() override = default;
    const char* what() const noexcept override;

  private:
    const char* type;
};
}

#endif /* !ERRORS_HPP_ */
