#include <iostream>
#include <string>
#include "prime.h"
#include "encode.h"
#include "sysinfo.h"

using namespace std;

static void printUsage() {
  cout <<
    "Usage:\n"
    "  sysutil.exe --prime <number>\n"
    "  sysutil.exe --encode <text>";
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

  if (command == "--encode") {
    if (argc < 3) {
        cout << "Error: missing <text>\n";
        return 1;
    }

    string input;
    for (int i = 2; i < argc; i++) {
        input += argv[i];
        if (i < argc - 1) {
            input += " ";
        }
    }

    string encoded;

    if (!encodeBase64(input, encoded)) {
        cout << "Error: encoding failed\n";
        return 1;
    }

    cout << encoded << "\n";
    return 0;
  }

  if (command == "--sysinfo") {
    printSystemInfo();
    return 0;
}


  cout << "Error: unknown option '" << command << "'\n";
  printUsage();
  return 1;
}
