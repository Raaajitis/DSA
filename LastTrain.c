#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005
#define MAXM 200005
#define INF 1000000000000000000LL

typedef long long ll;

typedef struct {
    int to;
    ll departure;
    ll arrival;
    int next;
} Edge;

Edge edges[MAXM];
int head[MAXN];
int edgeCount = 0;

void addEdge(int u, int v, ll departure, ll arrival) {

    edges[edgeCount].to = v;
    edges[edgeCount].departure = departure;
    edges[edgeCount].arrival = arrival;
    edges[edgeCount].next = head[u];

    head[u] = edgeCount++;
}

/* ---------------- Priority Queue ---------------- */

typedef struct {
    int node;
    ll time;
} HeapNode;

HeapNode heap[MAXM];
int heapSize = 0;

void swap(HeapNode *a, HeapNode *b) {

    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void push(int node, ll time) {

    int i = heapSize++;

    heap[i].node = node;
    heap[i].time = time;

    while (i > 0) {

        int parent = (i - 1) / 2;

        if (heap[parent].time <= heap[i].time)
            break;

        swap(&heap[parent], &heap[i]);

        i = parent;
    }
}

HeapNode pop() {

    HeapNode result = heap[0];

    heap[0] = heap[--heapSize];

    int i = 0;

    while (1) {

        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < heapSize &&
            heap[left].time < heap[smallest].time) {

            smallest = left;
        }

        if (right < heapSize &&
            heap[right].time < heap[smallest].time) {

            smallest = right;
        }

        if (smallest == i)
            break;

        swap(&heap[i], &heap[smallest]);

        i = smallest;
    }

    return result;
}

/* ---------------- Dijkstra ---------------- */

int main() {

    int n, m;

    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++)
        head[i] = -1;

    for (int i = 0; i < m; i++) {

        int u, v;
        ll departure, arrival;

        scanf("%d %d %lld %lld",
              &u, &v,
              &departure,
              &arrival);

        addEdge(u, v, departure, arrival);
    }

    ll *dist =
        malloc((n + 1) * sizeof(ll));

    for (int i = 1; i <= n; i++)
        dist[i] = INF;

    dist[1] = 0;

    push(1, 0);

    while (heapSize > 0) {

        HeapNode current = pop();

        int u = current.node;
        ll currentTime = current.time;

        /*
         * Ignore outdated heap entries.
         */
        if (currentTime != dist[u])
            continue;

        /*
         * We have reached the destination
         * at the earliest possible time.
         */
        if (u == n)
            break;

        for (int e = head[u];
             e != -1;
             e = edges[e].next) {

            ll departure =
                edges[e].departure;

            ll arrival =
                edges[e].arrival;

            int v =
                edges[e].to;

            /*
             * We can board only if we reach
             * the station before or exactly at
             * the departure time.
             */
            if (currentTime <= departure) {

                if (arrival < dist[v]) {

                    dist[v] = arrival;

                    push(v, arrival);
                }
            }
        }
    }

    if (dist[n] == INF)
        printf("-1\n");
    else
        printf("%lld\n", dist[n]);

    free(dist);

    return 0;
}