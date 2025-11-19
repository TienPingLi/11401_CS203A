/*
   ========================================
   hash_fn.c — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/11: Initial implementation
    - 2025/11/17: Refactored to use hash_fn.h

   Developer: Yu-Feng Huang <yfhuang@saturn.yzu.edu.tw>
 */

#include "hash_fn.h"
#include <stdio.h>

/**
 * @brief 計算整數鍵值的雜湊索引
 * @param key 整數鍵
 * @param m 雜湊表大小
 * @return 雜湊後的索引值
 */
int myHashInt(int key, int m) {
    long long int h;
    h = (long long)key * 99999839  // 大質數
        + 1234567;                 // 任意常數
    if (h < 0) h = -h;             // 確保非負
    key = (int)h;                  // C 風格轉型
    return key % m;                // 取模得到索引
}

/**
 * @brief 計算字串鍵值的雜湊索引
 * @param str 字串鍵
 * @param m 雜湊表大小
 * @return 雜湊後的索引值
 */
int myHashString(const char* str, int m) {
    unsigned long hash = 0;
    int i = 0;
    // 將每個字元累加，乘以質數 31
    while (str[i] != '\0') {
        hash = hash * 31 + (unsigned long)str[i];
        i++;
    }
    // 乘大質數 + 加偏移常數
    hash = hash * 99999839 + 1234567;
    // 確保非負
    if ((long long)hash < 0) {
        hash = (unsigned long)(-1 * (long long)hash);
    }
    return (int)(hash % m);  // 取模得到索引
}
