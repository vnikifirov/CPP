#pragma once

// Prototype of the function.
#include <iostream>
// For work with string.
#include <cstring>
// Obj string.
#include <string>

#include "MessageService.h"

MessageService::MessageService()
{
}

MessageService::~MessageService()
{
}

void MessageService::Get() {
  // Dereferencing pointer and get value in string.
  std::cout << "Enter your message : ";
	std::getline(std::cin, _userInput);
}

void MessageService::Display() {
  std::cout << "Hello: " << _userInput << std::endl;
}