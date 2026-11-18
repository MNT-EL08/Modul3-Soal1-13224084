#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int bfs_langkah_minimum(int n, int adj[MAX][MAX], int start, int target) {
    int queue[MAX];
    int front = 0, rear = 0;
    bool visited[MAX] = {false};
    int dist[MAX] = {0};

    visited[start] = true;
    dist[start] = 0;
    queue[rear++] = start;

    while (front < rear) {
        int curr = queue[front++];

        if (curr == target) {
            return dist[curr];
        }

        for (int next = 0; next < n; next++) {
            if (adj[curr][next] == 1 && !visited[next]) {
                visited[next] = true;
                dist[next] = dist[curr] + 1;
                queue[rear++] = next;
            }
        }
    }

    return -1; 
}

int main() {
    int n = 6;
    int adj[MAX][MAX] = {0};
    adj[0][1] = adj[1][0] = 1;
    adj[0][2] = adj[2][0] = 1;
    adj[1][3] = adj[3][1] = 1;
    adj[2][4] = adj[4][2] = 1;
    adj[3][5] = adj[5][3] = 1;
    adj[4][5] = adj[5][4] = 1;

    int start = 3, target = 5;
    int langkah = bfs_langkah_minimum(n, adj, start, target);

    if (langkah != 0) {
        printf("%d\n", start, target, langkah);
    } else {
        printf("Tidak ada jalur dari %d ke %d\n", start, target);
    }

    return 0;
}
