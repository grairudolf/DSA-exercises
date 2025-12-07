#include <stdio.h>

int can_finish(int numCourses, int prerequisites[][2], int prereqSize) {
    int indegree[1000] = {0};
    int adj[1000][1000];
    int adjCount[1000] = {0};

    for (int i = 0; i < numCourses; i++) {
        adjCount[i] = 0;
    }

    for (int i = 0; i < prereqSize; i++) {
        int course = prerequisites[i][0];
        int pre = prerequisites[i][1];
        adj[pre][adjCount[pre]++] = course;
        indegree[course]++;
    }

    int queue[1000];
    int front = 0, rear = 0;
    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0) queue[rear++] = i;
    }

    int visited = 0;
    while (front < rear) {
        int u = queue[front++];
        visited++;
        for (int i = 0; i < adjCount[u]; i++) {
            int v = adj[u][i];
            if (--indegree[v] == 0) queue[rear++] = v;
        }
    }

    return visited == numCourses;
}

int main() {
    int numCourses, m;
    printf("Enter number of courses: ");
    scanf("%d", &numCourses);
    if (numCourses <= 0 || numCourses > 1000) return 0;

    printf("Enter number of prerequisite pairs: ");
    scanf("%d", &m);
    if (m < 0 || m > 1000) return 0;

    int prereq[1000][2];
    printf("Enter each pair as: course prerequisite\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &prereq[i][0], &prereq[i][1]);
    }

    int ok = can_finish(numCourses, prereq, m);
    if (ok) printf("Possible to finish all courses.\n");
    else printf("Not possible to finish all courses (cycle detected).\n");
    return 0;
}
