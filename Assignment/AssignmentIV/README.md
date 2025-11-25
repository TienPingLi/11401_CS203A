# 作業四：雜湊函式設計與觀察（C/C++ 版本）

本作業聚焦於使用 C/C++ 設計與觀察雜湊（hash）函式。
學生需實作 hash 函式、分析其行為、評估效率，並了解其在電腦科學中的應用。

**開發者:** 田秉立 (Ping-Li, Tien)   
**電子郵件:** billyten0208@gmail.com

---

## 1. 我的雜湊函式

### 1.1 整數鍵（Integer Keys）

**公式 / 偽程式碼:**

```cpp
long long int h;
h = key * 99999839 // 大質數
    + 1234567;     // 任意常數
if (h < 0) h = -h; // 確保非負
key = static_cast<int>(h);
return key % m;     // 取模作為索引
```

**設計理由:**

1. **乘以大質數**：打破 key 與表格大小 `m` 的整除規律，避免像 21、31、41 等鍵值落在同一槽位。
2. **加上偏移常數**：增加變化，使不同 key 的結果更不易碰撞。
3. **取絕對值**：確保索引非負，避免 modulo 出現負數錯誤。

---

### 1.2 非整數鍵（字串 String Keys）

**公式 / 偽程式碼:**

```cpp
unsigned long hash = 0;
// 將每個字元累加並乘以基數
for (char ch : str) {
    hash = hash * 31 + static_cast<unsigned long>(ch);
}
hash = hash * 99999839 + 1234567; // 大質數 + 常數
if (hash < 0) hash = -hash;       // 確保非負
return static_cast<int>(hash % m);
```

**設計理由:**

1. **字元累加與基數乘法**：即使字串只有一個字元不同，也會產生不同 hash 值，避免順序相似字串落在同一槽位。
2. **乘以大質數並加偏移常數**：打破與表格大小 `m` 的整除規律，提高散列結果變化，降低碰撞。
3. **取絕對值**：避免整數溢位或負數 modulo 導致索引錯誤。

---

## 2. 實驗設置

* **測試表格大小 (m):** 10, 11, 37
* **測試資料集:**

  * 整數: 21–30, 51–60
  * 字串: `"cat"`, `"dog"`, `"bat"`, `"cow"`, `"ant"`, `"owl"`, `"bee"`, `"hen"`, `"pig"`, `"fox"`
* **編譯器:** GCC 與 G++
* **標準:** C23 與 C++23

---

## 3. 結果

| 表格大小 (m) | 索引序列                | 觀察        |
| -------- | ------------------- | --------- |
| 10       | 6, 1, 2, 3, ...     | 模式幾乎每 10 重複 |
| 11       | 10, 0, 6, 1, ...    | 分布更均勻     |
| 37       | 2, 29, 16, 3, ...  | 分布接近均勻    |

**觀察結論:**
質數大小的表格分布更均勻；非質數表格容易出現重複模式，增加碰撞。

---

## 4. 編譯、建置與執行

### 4.1 使用 Makefile

```bash
# 同時建置 C 與 C++ 版本
make all

# 僅建置 C 版本
make c

# 僅建置 C++ 版本
make cxx
```

### 4.2 手動編譯（如需要）

* **C 版本:**

```bash
gcc -std=c23 -Wall -Wextra -Wpedantic -g -o C/hash_function C/main.c C/hash_fn.c
```

* **C++ 版本:**

```bash
g++ -std=c++23 -Wall -Wextra -Wpedantic -g -o CXX/hash_function_cpp CXX/main.cpp CXX/hash_fn.cpp
```

### 4.3 清除編譯檔

```bash
make clean
```

### 4.4 執行

```bash
./hash_function          # C 版本
./hash_function_cpp      # C++ 版本
```

---

## 5. 範例輸出

### 5.1 整數   
<img width="247" height="428" alt="image" src="https://github.com/user-attachments/assets/f5f83fc3-6e44-4885-9daf-a3bf77926aaf" />
<img width="252" height="426" alt="image" src="https://github.com/user-attachments/assets/a95e3619-cec1-4263-88ae-f7567825994e" />
<img width="255" height="428" alt="image" src="https://github.com/user-attachments/assets/5312e1ed-af30-4d68-8ec2-153e9a093337" />



### 5.2 字串

<img width="252" height="219" alt="image" src="https://github.com/user-attachments/assets/f7419ca9-29e5-4ef6-a919-77ed9ed96da2" />
<img width="252" height="212" alt="image" src="https://github.com/user-attachments/assets/b2f34d71-888b-4ff1-b650-c30766e6ab9e" />
<img width="252" height="223" alt="image" src="https://github.com/user-attachments/assets/5164653d-c492-434f-804f-2baa51b06c2e" />

## 6. 分析

* **質數 vs 非質數表格大小:**
  質數表格分布均勻、碰撞較少；非質數表格容易出現重複模式。

* **碰撞與模式:**
  非質數表格容易產生重複索引模式，增加碰撞風險。

* **減少碰撞的方法:**

1. 使用質數表格大小
2. 設計良好的 hash 函式（bit-mixing、質數乘法、偏移常數）
3. 必要時使用雙雜湊或鏈結法處理碰撞

---

## 7. 反思

1. 在設計程式的過程中有用了很多方法，例如bits位移等等方法，但效果都沒有直接用四則運算均勻。
2. 表格大小對分布均勻性影響很大，質數表現最佳。
3. 使用大質數乘法與偏移常數可產生最均勻的索引序列。
4. 結果觀察顯示，良好的 hash 函式搭配合適的表格大小，能有效提升 hash table 的性能。
