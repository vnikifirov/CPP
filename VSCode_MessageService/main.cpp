// Services.
#include "Services/MessageService.h"

int main(int argc, char const *argv[])
{
  // Init
  MessageService hello_service;

  // Read Message
  hello_service.Get();

  // Show message
  hello_service.Display();

  system("pause");
  return 0;
}
