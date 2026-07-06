#include <string.h>
#include <stdlib.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) {
        return "";
    }
    
    int len = strlen(strs[0]);
    char* prefix = (char*)malloc((len + 1) * sizeof(char));
    strcpy(prefix, strs[0]);
    
    for (int i = 1; i < strsSize; i++) {
        int j = 0;
        while (prefix[j] != '\0' && strs[i][j] != '\0' && prefix[j] == strs[i][j]) {
            j++;
        }
        prefix[j] = '\0';
        if (j == 0) {
            return "";
        }
    }
    
    return prefix;
}