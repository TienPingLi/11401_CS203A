/*
   ========================================
   hash_fn.cpp — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/11: Initial implementation
    - 2025/11/17: Refactored to use hash_fn.hpp

   Developer: Yu-Feng Huang <yfhuang@saturn.yzu.edu.tw>
 */
#include "hash_fn.hpp"

/**
 * @brief 計算整數鍵值的雜湊索引
 * @param key 整數鍵
 * @param m 雜湊表大小
 * @return 雜湊後的索引值
 */
int myHashInt(int key, int m) {
    // TODO: replace with your own design
    return key % m;  // basic division method
}

/**
 * @brief 計算字串鍵值的雜湊索引
 * @param str 字串鍵
 * @param m 雜湊表大小
 * @return 雜湊後的索引值
 */
int myHashString(const std::string& str, int m) {
    unsigned long hash = 0;
    // TODO: replace with your own design
    return static_cast<int>(hash % m);  // basic division method
}