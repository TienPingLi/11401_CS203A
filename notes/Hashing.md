# **Hashing（雜湊）筆記**

---

## **1. 基本概念 (Hashing Basics)**

* **Hashing（雜湊）：**
  利用 *雜湊函數 (hash function)* 將 **Key → Index**，把資料放到陣列的 bucket 中。

* **目的：**
  不需從頭搜尋資料，可直接定位 → **平均 O(1) 查找 / 插入 / 刪除**

* **組成：**

  * Hash Function（雜湊函數）
  * Hash Table（雜湊表，通常是一個 array）
  * Collision Handling（碰撞處理）

---

## **2. 雜湊表結構 (Hash Table Structure)**

Hash Table = **Array（固定大小 m） + Collision Handling 機制**

* 每個位置稱為 **bucket**
* Key 經 hash function 後會落到某個 bucket：

  ```
  index = h(key) mod m
  ```
* 若多個 key 落到同一個 bucket → 產生 Collision（碰撞）

---

## **3. 雜湊函數 (Hash Function)**

### **特性**

* **Deterministic：** 相同 key 會得到相同 index
* **Uniform：** key 分散平均，避免撞在同一區
* **Efficient：** 計算簡單、快速

### **常見方法**

## **1. Division Method（除法取餘數法）**

---

### **定義**

```
h(k) = k mod m
```

將 key k 對 table 大小 m 取餘數（mod），餘數就是 bucket 的 index。

---

### **為什麼有效？**

* mod 會讓所有 key「平均」落在 0 ~ m-1 的範圍
* 計算速度極快（硬體原生支援）

---

### **選擇 m（table size）的注意事項**

選 m 非常重要！

**✔ 建議：m 使用質數 (prime number)**
例如：101, 503, 1009, 10007 …

原因：

* 若 m 是合成數，某些 key pattern 會造成大量碰撞
  （例如 key 全部是偶數、或都是 10 的倍數）
* 質數能打破規律，減少 clustering

---

### **缺點**

* 若 key 有某種規律（e.g., 都是 1000 的倍數） → 會造成碰撞
* 對某些資料模式（如字串）不好用

---

### **適用場合**

* key 本身是整數
* key 分布均勻
* table 大小需要容易控制

---

---

## **2. Multiplication Method（乘法雜湊法）**

---

### **定義**

```
h(k) = floor( m * (k * A mod 1) )
```

其中：

| 名稱          | 意義                                 |
| ----------- | ---------------------------------- |
| k           | key                                |
| m           | table size                         |
| A           | 0 < A < 1 的常數（通常取 0.6180339887...） |
| (k*A mod 1) | 取出 k*A 的小數部分                       |

---

### **為什麼有效？**

核心概念：
**乘以一個無理數（例如 φ = 0.618...）會讓 bit 混合得非常均勻。**

A = (√5 - 1) / 2 ≈ 0.618，被稱為「黃金比例 hashing 常數」。

效果：

* Key 的 bit pattern 被打亂 → 分散更均勻
* 對 key pattern 沒那麼敏感
* 不需要 m 是質數（與 Division Method 不同）

---

### **步驟解析（最完整解釋版）**

假設：

```
k = 12345
A = 0.618
m = 1000
```

1. 計算 k * A

   ```
   12345 × 0.618 = 7632.21
   ```

2. 取小數部分：

   ```
   0.21
   ```

3. 乘以 table size：

   ```
   0.21 × 1000 = 210
   ```

4. 取 floor：

   ```
   index = 210
   ```

---

### **使用 Multiplication Method 的好處**

✔ 不需要 m 是質數
✔ 對 key 的模式不敏感（比 Division Method 稳定）
✔ hash 結果更平均分布
✔ 適合大量連續 key

---

### **缺點**

* 比 mod 稍微慢一些（需要浮點運算）
* 若 A 選不好 → 分布不均勻

---

### **典型用法**

* 書本最推薦
* 記憶體位置運算、各語言的內建 hash function 底層常採用

---

---

## **3. Folding Method（摺疊法）**

---

### **定義**

把 key 拆成固定大小的區段，再相加。

例如 key = 123456
切成：12、34、56

```
h(key) = 12 + 34 + 56 = 102
```

---

### **適用情況**

* key 很大（例如 10 位數、12 位數）
* key 含有多段資訊的編碼（例如學號、身分證字號）

---

### **優點**

* 適合大型 key
* 不需高階數學操作
* key 各段都會參與 hash → 資訊利用率高

---

### **缺點**

* 分布通常不如 Multiply method 平均
* 若 key 結構固定（如前兩碼固定）→ 造成 clustering
* 需小心切法，否則會造成偏差

---

### **改良方法**

* 可採用「摺曲」

例如 key = 12345678
切成：

```
1234
5678（反轉）
→ 1234 + 8765
```

讓分布更均勻。

---

---

## **4. String Hashing（字串雜湊）**

---

### **問題**

字串（例如 "apple"）不能直接 mod → 需轉成整數

---

### **常用方法：Polynomial Rolling Hash**

```
h(s) = (s[0] * p^0 + s[1] * p^1 + ... + s[n-1] * p^(n-1)) mod m
```

### **p 的選擇**

* 常用：31 或 37（質數）
* 這些是英文小寫字母數量附近的好選擇

### **為什麼有效？**

* 每個字元乘以不同次方 → 順序不同會改變 hash
* 可以避免 "ab" 與 "ba" 等字串產生相同 hash
* 碰撞機率低

---

### **例子**

字串 `"cat"`
ASCII：

```
c = 99
a = 97
t = 116
```

採用 p=31：

```
h("cat") = 99*31^0 + 97*31^1 + 116*31^2
         = 99 + 3007 + 111,556
         = 114,662 mod m
```

---

### **優點**

* 分布均勻
* 適用於所有字串類型
* 是許多語言（Java、C++）內建字串 hash 的核心演算法

---

### **缺點**

* 需處理大數（可能溢位）
* 計算比整數 hash 慢

---

---

# **5. 各種 Hash Function 的比較表**

| 方法             | 優點      | 缺點            | 適用情境      |
| -------------- | ------- | ------------- | --------- |
| Division       | 快、簡單    | 對 key 模式敏感    | key 為整數   |
| Multiplication | 分布均勻、穩定 | 浮點運算          | 通用、最推薦    |
| Folding        | 適合大 key | 分布不均勻         | 身分證、電話、學號 |
| String Hashing | 分散佳、碰撞低 | 難以避免 overflow | 字串        |

---  

### **Table Size 選擇**

* **m 建議使用質數 (prime number)**
* 可減少 pattern，避免 clustering

---

## **4. 碰撞處理 (Collision Handling)**

當兩個 key 產生相同 hash index → **Collision**

常見處理方式：

---

## **(1) Chaining（分離鏈結法）**

* bucket 裡存放 **linked list**
* 多個 key 共享同一個 bucket
* 不需要尋找其他空位

### 特點

* 插入容易
* Load Factor 可 > 1
* 均攤成本 O(1)
* 缺點：指標額外空間，list 太長會退化

---

## **(2) Open Addressing（開放定址）**

若 bucket 被占用 → 按照規則「探測」下一個位置

### (a) Linear Probing（線性探測）

```
index(i) = (h(k) + i) mod m
```

* 依序往後找
* 缺點：**Primary Clustering（主叢集）**

### (b) Quadratic Probing（平方探測）

```
index(i) = h(k) + c1*i + c2*i^2
```

* 跳躍性找空位
* 降低主叢集，但仍有 Secondary Clustering

### (c) Double Hashing（雙雜湊法）

```
index(i) = h1(k) + i * h2(k)
```

* 第二個 hash 當作步進值（step size）
* 幾乎消除 clustering → **最推薦**

---

## **5. 負載因子 (Load Factor)**

```
α = n / m
n = 存入的資料數量
m = bucket 數量
```

* α 越大 → 碰撞越多 → 效能下降
* 一般雜湊表：若 α > 0.75 → 建議 **rehash（擴充表的大小）**

---

## **6. 靜態與動態雜湊 (Static vs Dynamic Hashing)**

### **靜態雜湊 (Static Hashing)**

* table 大小固定
* 實作簡單
* 但資料量變多後效能下降

### **動態雜湊 (Dynamic Hashing)**

* table 可自動擴充
* 常見方式：Extendible Hashing
* 保持良好效能，但實作較複雜

---

## **7. Hash Table ADT（抽象資料型別）**

### 基本操作

* `Insert(key, value)`
* `Search(key)`
* `Delete(key)`
* **平均時間：O(1)**
* 最差（碰撞嚴重）：退化為 O(n)

---

## **8. 優點與缺點 (Pros & Cons)**

### **優點**

* 查詢、插入、刪除平均 O(1)
* 適合大量查詢的應用（DNS、資料庫 index）

### **缺點**

* 子項目無順序性（不像 Tree）
* Collisions 不可避免
* Open addressing 在高 load factor 時變慢

---

## **9. 常見應用 (Applications)**

* **DNS Caching**（URL → IP）
* **Symbol Table**（Compiler）
* **Database Indexing**
* **快取（cache）與記憶體管理**

---

## **10. 重點總結（快速複習版）**

* Hash Table = Array + Hash Function
* 平均 O(1)
* m 用質數
* 探測法：Linear / Quadratic / Double
* Clustering：Primary / Secondary
* Load Factor > 0.75 → rehash
* Chaining vs Open Addressing


