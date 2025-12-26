#include <stdio.h>
#include <windows.h>

#define N 5
HANDLE chopsticks[N];

DWORD WINAPI Philosopher(LPVOID param) {
    int id = (int)(size_t)param, left = id, right = (id + 1) % N;
    for (int i = 0; i < 3; i++) {
        printf("Philosopher %d is thinking\n", id + 1); Sleep(300);
        WaitForSingleObject(chopsticks[left], INFINITE);
        WaitForSingleObject(chopsticks[right], INFINITE);
        printf("Philosopher %d is eating\n", id + 1); Sleep(300);
        ReleaseMutex(chopsticks[left]); ReleaseMutex(chopsticks[right]);
        printf("Philosopher %d finished eating\n", id + 1);
    }
    return 0;
}

int main() {
    HANDLE th[N]; DWORD tid[N];
    for (int i = 0; i < N; i++) chopsticks[i] = CreateMutex(NULL, 0, NULL);
    for (int i = 0; i < N; i++) th[i] = CreateThread(NULL, 0, Philosopher, (LPVOID)(size_t)i, 0, &tid[i]);
    WaitForMultipleObjects(N, th, TRUE, INFINITE);
    printf("All philosophers have finished.\n");
    return 0;
}

