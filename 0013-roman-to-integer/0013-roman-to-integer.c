#include <string.h>

int romanToInt(char* s) {
    int rMap[256] = {0};
    rMap['I'] = 1;
    rMap['V'] = 5;
    rMap['X'] = 10;
    rMap['L'] = 50;
    rMap['C'] = 100;
    rMap['D'] = 500;
    rMap['M'] = 1000;

    int total = 0;
    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        if (i < len - 1 && rMap[(unsigned char)s[i]] < rMap[(unsigned char)s[i + 1]]) {
            total -= rMap[(unsigned char)s[i]];
        } else {
            total += rMap[(unsigned char)s[i]];
        }
    }

    return total;
}