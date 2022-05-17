// Copyright @bigpel66

// Header for the exceptions to throw and stack unwind
#ifndef CIRCLE_05_WEBSERV_INCLUDES_EXCEPTION_HPP_
#define CIRCLE_05_WEBSERV_INCLUDES_EXCEPTION_HPP_

// Standard Library Inclusion
#include <exception>
#include <string>

// PthreadException is the base Exception class for Pthread
class PthreadException : public std::exception {
 private:
  std::string _error_message;
  int _error_number;

  // Prevent to call directly
  PthreadException(void);
  PthreadException(const PthreadException& t);
  PthreadException& operator=(const PthreadException& t);

 public:
  PthreadException(const std::string& error_message, const int error_number);
  virtual ~PthreadException(void);

  int get_error_number() const;
  const std::string& get_error_message() const;
  virtual const char* what(void) const throw();
};

// MutexException is the Exception regarding Mutex class
class MutexExcepetion : public PthreadException {
 public:
  explicit MutexExcepetion(const std::string& message);
  MutexExcepetion(const std::string& message, const int number);
};

// MutexException is the Exception regarding Thread class
class ThreadException : public PthreadException {
 public:
  explicit ThreadException(const std::string& message);
  ThreadException(const std::string& message, const int number);
};

#endif  // CIRCLE_05_WEBSERV_INCLUDES_EXCEPTION_HPP_