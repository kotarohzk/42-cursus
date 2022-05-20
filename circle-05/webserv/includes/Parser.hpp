// Copyright @bigpel66

// Header for the parser of configuration file
#ifndef CIRCLE_05_WEBSERV_INCLUDES_PARSER_HPP_
#define CIRCLE_05_WEBSERV_INCLUDES_PARSER_HPP_

// Standard Library Inclusion
#include <string>
#include <fcntl.h>
#include <unistd.h>

// Class Headers Inclusion
#include "./Utilizer.h"

class Parser {
 private:
  int _fd;
  int _worker_count;
  int _newline_count;
  std::string _config;
  ServerInfos _server_infos;

  Parser(void);
  Parser(const Parser& p);
  Parser& operator=(const Parser& p);

  bool is_empty_line(const std::string& line) const;
  bool is_comment(char ch) const;
  bool is_newline(char ch) const;
  std::string& trim_whitespace(std::string& line);
  std::string get_key(const std::string& line);
  std::string get_val(const std::string& line);
  std::string get_current_parsing_line(void) const;

  void is_directory_then_open(void);
  void is_openable_then_open(void);
  void close_config(void) const;
  void skip_comment(void) const;
  void increase_newline_count(void);
  void set_worker_count(const std::string& val);
  void case_newline(std::string& line);

  void parse_config(void);
  void parse_top_directive(const std::string& line);
  void parse_server_directive(void);

 public:
  explicit Parser(const std::string& config);
  ~Parser(void);

  std::size_t get_server_size(void) const;
  std::size_t get_worker_size(void) const;
  t_server_info get_server_info_at(std::size_t index) const;
};

#endif  // CIRCLE_05_WEBSERV_INCLUDES_PARSER_HPP_
