#include<stdio.h>
#include<stdbool.h>
#include<limits.h>

#define MAX_USERS 100

bool visited[MAX_USERS];

void BFS(int graph[MAX_USERS][MAX_USERS], int numUsers, int start, int target) {
    int queue[MAX_USERS], distance[MAX_USERS], pred[MAX_USERS];
    bool visited[MAX_USERS] = {false};
    int front = 0, rear = 0;

    for (int i = 0; i < numUsers; i++) {
        distance[i] = INT_MAX;
        pred[i] = -1;
    }

    visited[start] = true;
    distance[start] = 0;
    queue[rear++] = start;

    while (front < rear) {
        int current = queue[front++];

        for (int i = 0; i < numUsers; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                visited[i] = true;
                distance[i] = distance[current] + 1;
                pred[i] = current;
                queue[rear++] = i;

                if (i == target) {
                    printf("Shortest path between users %c and %c: ", 'A' + start, 'A' + target);
                    int crawl = target;
                    while (crawl != -1) {
                        printf("%c ", 'A' + crawl);
                        crawl = pred[crawl];
                    }
                    printf("\nDistance: %d\n", distance[target]);
                    return;
                }
            }
        }
    }
    printf("No connection between users %c and %c\n", 'A' + start, 'A' + target);
}

void DFS_recursive(int graph[MAX_USERS][MAX_USERS], int user, int numUsers) {
    printf("%c ", 'A' + user);
    visited[user] = true;

    for (int i = 0; i < numUsers; i++) {
        if (graph[user][i] == 1 && !visited[i]) {
            DFS_recursive(graph, i, numUsers);
        }
    }
}

void findCommunities(int graph[MAX_USERS][MAX_USERS], int numUsers) {
    for (int i = 0; i < numUsers; i++) {
        visited[i] = false;
    }

    printf("Communities found:\n");
    for (int i = 0; i < numUsers; i++) {
        if (!visited[i]) {
            printf("Community: ");
            DFS_recursive(graph, i, numUsers);
            printf("\n");
        }
    }
}

int main() {
    int numUsers;
    printf("Enter the number of users: ");
    scanf("%d", &numUsers);

    int graph[MAX_USERS][MAX_USERS];
    printf("Enter the adjacency matrix of the social network (1 for connected, 0 for not connected):\n");
    for (int i = 0; i < numUsers; i++) {
        for (int j = 0; j < numUsers; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int choice;
    printf("Choose an operation:\n");
    printf("1. Find Shortest Path (BFS)\n");
    printf("2. Find Communities (DFS)\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        char user1, user2;
        printf("Enter the source user (A-Z): ");
        scanf(" %c", &user1);
        printf("Enter the target user (A-Z): ");
        scanf(" %c", &user2);

        BFS(graph, numUsers, user1 - 'A', user2 - 'A');
    } else if (choice == 2) {
        findCommunities(graph, numUsers);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}
