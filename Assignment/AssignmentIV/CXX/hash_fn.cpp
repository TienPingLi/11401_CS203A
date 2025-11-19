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
    long long int h;
	h = key * 99999839// a large prime number
		+ 1234567; // an arbitrary c
    if (h < 0)h = -h;// ensure non-negative
	key = static_cast<int>(h);
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

    // 將每個字元累加，乘以質數，形成散列值
    for (char ch : str) {
		hash = hash * 31 + static_cast<unsigned long>(ch); // a common choice is 31
    }
	hash = hash * 99999839 + 1234567; // a large prime number and an arbitrary c
	if (hash < 0) hash = (-1)*hash; // ensure non-negative
    return static_cast<int>(hash % m);  // basic division method
}