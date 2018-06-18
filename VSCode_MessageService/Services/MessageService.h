#pragma once

// Obj string.
#include <string>

class MessageService
{
  // Encapsulated data
  private:
    std::string _userInput;

  // Public data
  public:

  // Contructor
  MessageService();

  // Destructor
  ~MessageService();

  // Methods
  void Get();
  void Display();
};