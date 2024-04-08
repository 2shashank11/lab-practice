#include <limits.h>
#include <stdio.h>
#include <string.h>
 
#define NO_OF_CHARS 256
 
int max(int a, int b) { return (a > b) ? a : b; }
 

void badCharHeuristic(char* substr, int m, int badchar[NO_OF_CHARS]){
    for (int i = 0; i < NO_OF_CHARS; i++){
        badchar[i] = -1;
    }
 
    for (int i = 0; i < m; i++)
        badchar[(int)substr[i]] = i;
}
 
void search(char* str, char* substr){
    int m = strlen(substr);
    int n = strlen(str);
 
    int badchar[NO_OF_CHARS];

    badCharHeuristic(substr, m, badchar);
 
    int s = 0; // s is shift of the pattern with
               // respect to text
    while (s <= (n - m)) {
        int j = m - 1;

        while (j >= 0 && substr[j] == str[s + j]){
            j--;
        }
 
        if (j < 0) {
            printf("pattern occurs at shift = %d", s);

            s += (s + m < n) ? m - badchar[str[s + m]] : 1;
        }
 
        else
            s += max(1, j - badchar[str[s + j]]);
    }
}

int main()
{
    char str[] = "ABAAABCD";
    char substr[] = "ABC";
    search(str, substr);
    return 0;
}