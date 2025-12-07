#include <stdio.h>

int lengthOfLongestSubstring(const char *s) {
    int last_index[256];
    for (int i = 0; i < 256; i++) {
        last_index[i] = -1;
    }

    int start = 0;
    int max_len = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        unsigned char c = (unsigned char)s[i];

        if (last_index[c] >= start) {
            start = last_index[c] + 1;
        }

        last_index[c] = i;

        int window_len = i - start + 1;
        if (window_len > max_len) {
            max_len = window_len;
        }
    }

    return max_len;
}

int main() {
    char s[1000];
    printf("Enter a string: ");
    if (fgets(s, sizeof(s), stdin) == NULL) {
        return 0;
    }

    // Remove trailing newline if present
    int len = 0;
    while (s[len] != '\0') {
        if (s[len] == '\n') {
            s[len] = '\0';
            break;
        }
        len++;
    }

    int result = lengthOfLongestSubstring(s);
    printf("Length of longest substring without repeating characters: %d\n", result);

    return 0;
}
