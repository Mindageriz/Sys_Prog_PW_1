#include <iostream>
#include <string>
#include "prime.h"

using namespace std;

static void printUsage() {
  cout <<
    "Usage:\n"
    "  sysutil.exe --prime <number>\n";
}

int main(int argc, char* argv[]) {

  if (argc < 2) {
    cout << "Error: no arguments provided\n";
    printUsage();
    return 1;
  }

  string command = argv[1];

  if (command == "--prime") {
    if (argc < 3) {
      cout << "Error: missing <number>\n";
      printUsage();
      return 1;
    }
    parseAndCheckPrime(argv[2]);
    return 0;
  }

  cout << "Error: unknown option '" << command << "'\n";
  printUsage();
  return 1;
}
