#include "sysinfo.h"
#include <windows.h>
#include <iostream>
#include <iomanip>

using namespace std;

void printSystemInfo() {
  SYSTEM_INFO si;
  GetNativeSystemInfo(&si);
  cout << "Number of Logical Processors: " << si.dwNumberOfProcessors << "\n";
  cout << "Page size: " << si.dwPageSize << " Bytes\n";
  cout << "Processor Mask: 0x" << hex << si.dwActiveProcessorMask << dec << "\n";
  cout << "Minimum process address: 0x" << hex << reinterpret_cast<uintptr_t>(si.lpMinimumApplicationAddress) << dec << "\n";
  cout << "Maximum process address: 0x" << hex << reinterpret_cast<uintptr_t>(si.lpMaximumApplicationAddress) << dec << "\n";
}
