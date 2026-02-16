#include "error.h"
#include <windows.h>
#include <iostream>
#include <string>

using namespace std;

bool printWindowsErrorMessage(const std::string& codeStr) {
  try {
    int code = stoi(codeStr);
    if (code < 0) {
      cout << "No such error exists\n";
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
      cout << "No such error exists\n";
      return false;
    }

    cout << "Message " << code << ": " << buffer;

    LocalFree(buffer);
    return true;
  }
  catch (...) {
    cout << "Invalid error code\n";
    return false;
  }
}
