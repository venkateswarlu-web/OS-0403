#include <stdio.h>
#include <windows.h>

int main() {
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    // Create a new process
    if (!CreateProcess(
            "C:\\Windows\\System32\\notepad.exe", // Path to executable
            NULL,   // Command line arguments
            NULL,   // Process handle not inheritable
            NULL,   // Thread handle not inheritable
            FALSE,  // Set handle inheritance to FALSE
            0,      // No creation flags
            NULL,   // Use parent's environment block
            NULL,   // Use parent's starting directory
            &si,    // Pointer to STARTUPINFO structure
            &pi))   // Pointer to PROCESS_INFORMATION structure
    {
        printf("CreateProcess failed (%d).\n", GetLastError());
        return 1;
    }

    printf("Parent Process ID: %lu\n", GetCurrentProcessId());
    printf("Child Process ID: %lu\n", pi.dwProcessId);

    // Wait until child process exits
    WaitForSingleObject(pi.hProcess, INFINITE);

    // Close process and thread handles
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}
