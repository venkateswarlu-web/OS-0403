#include <stdio.h>
#include <windows.h>

DWORD WINAPI PipeReader(LPVOID lpParam) {
    HANDLE hPipe = CreateFile(
        "\\\\.\\pipe\\MyPipe", GENERIC_READ, 0, NULL,
        OPEN_EXISTING, 0, NULL
    );

    if (hPipe == INVALID_HANDLE_VALUE) {
        printf("Child failed to open pipe.\n");
        return 1;
    }

    char buffer[100];
    DWORD bytesRead;
    ReadFile(hPipe, buffer, sizeof(buffer), &bytesRead, NULL);
    printf("Child received: %s\n", buffer);

    CloseHandle(hPipe);
    return 0;
}

int main() {
    HANDLE hPipe;
    DWORD threadId;

    // 1. Create named pipe
    hPipe = CreateNamedPipe(
        "\\\\.\\pipe\\MyPipe", PIPE_ACCESS_OUTBOUND,
        PIPE_TYPE_MESSAGE | PIPE_WAIT, 1, 0, 0, 0, NULL
    );
    if (hPipe == INVALID_HANDLE_VALUE) {
        printf("Failed to create pipe.\n");
        return 1;
    }

    // 2. Start "child" thread
    HANDLE hThread = CreateThread(NULL, 0, PipeReader, NULL, 0, &threadId);

    // 3. Wait for child to connect
    printf("Parent waiting for child to connect...\n");
    ConnectNamedPipe(hPipe, NULL);

    // 4. Parent sends message
    char message[] = "Hello from parent!";
    DWORD bytesWritten;
    WriteFile(hPipe, message, sizeof(message), &bytesWritten, NULL);
    printf("Parent sent: %s\n", message);

    // 5. Wait for child thread to finish
    WaitForSingleObject(hThread, INFINITE);

    CloseHandle(hPipe);
    CloseHandle(hThread);
    return 0;
}

