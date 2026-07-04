#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int lengthOfLongestSubstring(char* s) {
    int n = strlen(s);
    int maxLength = 0;
    
    // ASCII ক্যারেক্টারগুলোর সর্বশেষ ইনডেক্স ট্র্যাক রাখার জন্য অ্যারে
    // শুরুতে সব উপাদান -1 দিয়ে পূর্ণ করা হয়
    int lastSeen[256];
    for (int i = 0; i < 256; i++) {
        lastSeen[i] = -1;
    }
    
    int left = 0;
    for (int right = 0; right < n; right++) {
        char currentChar = s[right];
        
        // যদি ক্যারেক্টারটি বর্তমান উইন্ডোর ভেতরে আগে দেখা গিয়ে থাকে, 
        // তবে left পয়েন্টারকে তার পরের ইনডেক্সে সরিয়ে নেওয়া হবে
        if (lastSeen[(unsigned char)currentChar] >= left) {
            left = lastSeen[(unsigned char)currentChar] + 1;
        }
        
        // ক্যারেক্টারটির বর্তমান অবস্থান আপডেট করা
        lastSeen[(unsigned char)currentChar] = right;
        
        // উইন্ডোর সর্বোচ্চ দৈর্ঘ্য আপডেট করা
        maxLength = MAX(maxLength, right - left + 1);
    }
    
    return maxLength;
}