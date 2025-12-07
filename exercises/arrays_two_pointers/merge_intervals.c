#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Interval;

int cmp_intervals(const void *a, const void *b) {
    const Interval *ia = (const Interval *)a;
    const Interval *ib = (const Interval *)b;
    if (ia->start < ib->start) return -1;
    if (ia->start > ib->start) return 1;
    return 0;
}

int merge_intervals(Interval *intervals, int n, Interval *out) {
    if (n == 0) return 0;

    qsort(intervals, n, sizeof(Interval), cmp_intervals);

    int out_count = 0;
    out[out_count] = intervals[0];

    for (int i = 1; i < n; i++) {
        Interval *last = &out[out_count];
        if (intervals[i].start <= last->end) {
            if (intervals[i].end > last->end) {
                last->end = intervals[i].end;
            }
        } else {
            out_count++;
            out[out_count] = intervals[i];
        }
    }

    return out_count + 1;
}

int main() {
    int n;
    printf("Enter number of intervals: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Number of intervals must be positive.\n");
        return 0;
    }

    if (n > 1000) n = 1000;

    Interval intervals[1000];
    printf("Enter intervals as: start end\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &intervals[i].start, &intervals[i].end);
        if (intervals[i].start > intervals[i].end) {
            int tmp = intervals[i].start;
            intervals[i].start = intervals[i].end;
            intervals[i].end = tmp;
        }
    }

    Interval merged[1000];
    int merged_count = merge_intervals(intervals, n, merged);

    printf("Merged intervals:\n");
    for (int i = 0; i < merged_count; i++) {
        printf("[%d, %d]\n", merged[i].start, merged[i].end);
    }

    return 0;
}
