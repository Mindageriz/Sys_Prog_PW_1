@echo off
setlocal

REM Always run from project root (where build.bat is)
cd /d "%~dp0"

REM Initialize MSVC environment
call "%ProgramFiles(x86)%\Microsoft Visual Studio\2022\BuildTools\VC\Auxiliary\Build\vcvars64.bat"
if errorlevel 1 exit /b 1

REM Ensure build directory exists
if not exist build mkdir build

REM Compile all .cpp files in src/ and include headers from include/
cl /nologo /std:c++20 /EHsc /W4 /Zi ^
   /I "include" ^
   /Fo:build\ ^
   /Fd:build\ ^
   /Fe:build\sysutil.exe ^
   src\*.cpp

endlocal
