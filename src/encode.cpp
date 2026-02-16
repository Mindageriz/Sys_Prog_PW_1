#include "encode.h"
#include <windows.h>
#include <wincrypt.h>

#pragma comment(lib, "Crypt32.lib")

bool encodeBase64(const std::string& input, std::string& output) { 
  if (input.empty()) {
    output.clear();     
    return true;       
  }

  DWORD requiredSize = 0;
  if (!CryptBinaryToStringA(
      reinterpret_cast<const BYTE*>(input.data()),
      static_cast<DWORD>(input.size()),
      CRYPT_STRING_BASE64 | CRYPT_STRING_NOCRLF,
      nullptr,
      &requiredSize)) {
    return false;
  }

  output.resize(requiredSize);
  if (!CryptBinaryToStringA(
      reinterpret_cast<const BYTE*>(input.data()),
      static_cast<DWORD>(input.size()),
      CRYPT_STRING_BASE64 | CRYPT_STRING_NOCRLF,
      &output[0],
      &requiredSize)) {
    return false;
  }

  if (!output.empty() && output.back() == '\0') {
    output.pop_back();
  }
  
  return true;
}
