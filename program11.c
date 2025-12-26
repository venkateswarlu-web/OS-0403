#include <stdio.h>
#include <windows.h>

// Thread function 1
DWORD WINAPI ThreadFunc1(LPVOID lpParam) {
    for(int i = 1; i <= 5; i++) {
        printf("Thread 1: %d\n", i);
        Sleep(500); // Pause for 500ms
    }
    return 0;
}

// Thread function 2
DWORD WINAPI ThreadFunc2(LPVOID lpParam) {
    for(int i = 1; i <= 5; i++) {
        printf("Thread 2: %d\n", i);
        Sleep(700); // Pause for 700ms
    }
    return 0;
}

int main() {
    HANDLE hThread1, hThread2;
    DWORD threadId1, threadId2;

    // Create two threads
    hThread1 = CreateThread(NULL, 0, ThreadFunc1, NULL, 0, &threadId1);
    hThread2 = CreateThread(NULL, 0, ThreadFunc2, NULL, 0, &threadId2);

    // Wait for both threads to finish
    WaitForSingleObject(hThread1, INFINITE);
    WaitForSingleObject(hThread2, INFINITE);

    // Close thread handles
    CloseHandle(hThread1);
    CloseHandle(hThread2);

    printf("Main thread finished.\n");
    return 0;
}
