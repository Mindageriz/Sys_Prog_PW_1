#include "error.h"
#include <windows.h>
#include <iostream>
#include <string>

bool printWindowsErrorMessage(const std::string& codeStr) {
  try {
    int code = std::stoi(codeStr);

    if (code < 0) {
      std::cout << "No such error exists\n";
      return false;
    }

    LPSTR buffer = nullptr;

    DWORD result = FormatMessageA(
      FORMAT_MESSAGE_ALLOCATE_BUFFER |
      FORMAT_MESSAGE_FROM_SYSTEM |
      FORMAT_MESSAGE_IGNORE_INSERTS,
      nullptr,
      static_cast<DWORD>(code),
      0,
      (LPSTR)&buffer,
      0,
      nullptr
    );

    if (result == 0) {
      std::cout << "No such error exists\n";
      return false;
    }

    std::cout << "Message " << code << ": " << buffer;

    LocalFree(buffer);
    return true;
  }
  catch (...) {
    std::cout << "Invalid error code\n";
    return false;
  }
}
