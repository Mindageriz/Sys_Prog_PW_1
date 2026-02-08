#include "prime.h"
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool isPrime(long long n) {
  if (n <= 1) return false;
  for (long long i = 2; i <= (n/2); i++) {
    if (n % i == 0) return false;
  }
  
  return true;
}

bool parseAndCheckPrime(const char* input) {
  string s = input;
  for (char c : s) {
    if (!isdigit(c)) {
      cout << "Error: input is not a valid number\n";
      return false;
    }
  }

  long long value = stoll(s);
  if (isPrime(value)) {
    cout << "TRUE\n";
  } else {
    cout << "FALSE\n";
  }

  return true;
}
