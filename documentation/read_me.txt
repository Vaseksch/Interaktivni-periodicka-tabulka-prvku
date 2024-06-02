If you want to enable ANSI escape codes in cmd.exe, you must insert the following command into CMD:

reg add HKCU\Console /v VirtualTerminalLevel /t REG_DWORD /d 1

If you want to enable ANSI escape codes in cmd.exe, you must insert the following command into CMD:

reg add HKCU\Console /v VirtualTerminalLevel /t REG_DWORD /d 0