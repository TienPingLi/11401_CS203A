
# **Hashing（雜湊）筆記**

---

## **1. 基本概念（Hashing Basics）**

### **Hashing（雜湊）是什麼？**

Hashing 是利用 **雜湊函數 (hash function)** 將 **Key → Index**，並將資料存到陣列的 bucket 中。

### **目的**

* 不需線性搜尋
* 可直接定位到可能位置
* **平均時間複雜度：O(1)**（查找、插入、刪除）

### **Hash Table 組成**

* **Hash Function（雜湊函數）**
* **Hash Table（通常是 array）**
* **Collision Handling（碰撞處理機制）**

---

## **2. 雜湊表結構（Hash Table Structure）**

Hash Table = **Array（大小固定 m） + Collision Handling**

* 每個 array 位置稱為 **bucket**
* 資料存入方式：

  ```
  index = h(key) mod m
  ```
* 若多個 key 落在同一 index → **Collision（碰撞）**

---

## **3. 雜湊函數（Hash Function）**

### **好雜湊函數特性**

* **Deterministic**：相同 key → 相同 result
* **Uniform**：分布平均
* **Efficient**：計算快速

---

## **3.1 Division Method（除法取餘數法）**

### **定義**

```c
h(k) = k mod m
```

### **優點**

* 最簡單、最快
* 常用在整數 key

### **為什麼有效？**

* 取餘數能把 key 分布到範圍 0 ~ m-1
* 計算幾乎沒有成本

### **m（table size）選擇重點**

✔ **建議使用質數 (prime number)**
例如：101、503、1009、10007

理由：

* 避免 key pattern（如全偶數）造成大量碰撞
* 避免 clustering

### **缺點**

* key 有規律會造成偏差
* 不適合字串

---

## **3.2 Multiplication Method（乘法雜湊法）**

### **定義**

```c
h(k) = floor( m * (k * A mod 1) )
```

A 建議使用 0.618...（黃金比例 φ）

| 名稱        | 意義         |
| --------- | ---------- |
| k         | key        |
| m         | table size |
| A         | 介於 0~1 的常數 |
| k*A mod 1 | 取小數部分      |

---

### **為什麼有效？**

* A 為無理數（如 φ），能有效 **打散 key 的 bit pattern**
* 對 key 的模式不敏感（比 division 好）
* 不需要 m 是質數

---

### **示範**

```
k = 12345
A = 0.618
m = 1000
```

1. `k*A = 7632.21`
2. 小數部分 `0.21`
3. `0.21 * 1000 = 210`
4. index = **210**

---

### **優點**

✔ 分布平均
✔ 不需要質數 table size
✔ 對 key pattern 免疫

### **缺點**

* 需浮點數（稍慢）
* A 選不好會變差

---

## **3.3 Folding Method（摺疊法）**

### **定義**

把 key 切段 → 相加

例：key = 123456 → 切成 12, 34, 56

```
h(key) = 12 + 34 + 56 = 102
```

### **適用**

* key 很大（身分證字號、電話、學號）
* key 編碼有分段資訊

### **優點**

* 不需複雜運算
* key 每段都有參與

### **缺點**

* 分布不如 multiplication method 好
* key 前段固定時 → clustering

### **改良：折返法**

```
1234
5678（反轉 → 8765）
→ 1234 + 8765
```

---

## **3.4 String Hashing（字串雜湊）**

字串不能直接 mod → 必須轉成整數。

### **Polynomial Rolling Hash**

```c
h(s) = (s[0]*p^0 + s[1]*p^1 + ... + s[n-1]*p^(n-1)) mod m
```

### **常見 p 值**

* 31（小寫英文字母多）
* 37（質數）
* 有些語言用 131, 13331

### **為什麼好？**

* 字元順序會影響值（避免碰撞）
* 分布好、碰撞機率低

### **範例 “cat”**

```
c = 99
a = 97
t = 116

h = 99*31^0 + 97*31^1 + 116*31^2
  = 114662 mod m
```

---

## **3.5 各種 Hash Function 比較**

| 方法             | 優點      | 缺點          | 適用     |
| -------------- | ------- | ----------- | ------ |
| Division       | 快、簡單    | key 有規律時表現差 | 整數 key |
| Multiplication | 分布佳、穩定  | 浮點運算        | 通用、推薦  |
| Folding        | 適合大 key | 分布不平均       | 身分證、電話 |
| String Hashing | 分散良好    | 容易 overflow | 字串     |

---

## **4. 碰撞處理（Collision Handling）**

當兩個 key 得到相同 index → **Collision**

處理方式兩大類：

---

## **4.1 Chaining（分離鏈結）**

* 每個 bucket 存一條 linked list
* 多個 key 放同一 bucket

### **優點**

* 實作簡單
* Load factor 可 >1
* 平均 O(1)

### **缺點**

* list 過長時會退化

---

## **4.2 Open Addressing（開放定址）**

已被占用 → 找下一個位置

---

### (a) Linear Probing（線性探測）

```
index = h(k) + i
```

* 逐格往後找
* **缺點：Primary Clustering**

---

### (b) Quadratic Probing（平方探測）

```
index = h(k) + c1*i + c2*i^2
```

* 減少主叢集
* 仍有 secondary clustering

---

### (c) Double Hashing（雙雜湊法）— 最推薦

```
index = h1(k) + i * h2(k)
```

* 幾乎消除 clustering
* 需兩個 hash function

---

## **5. 負載因子（Load Factor）**

```
α = n / m
```

n = 元素數
m = bucket 數

### **影響**

* α 越高 → collision 越多
* α > 0.75 建議 **rehash**

---

## **6. 靜態 vs 動態雜湊**

### 靜態（Static Hashing）

* table 大小固定
* 實作容易
* 高 load factor 時變慢

### 動態（Dynamic Hashing）

* table 可自動擴充
* Extendible hashing / Linear hashing
* 效能更穩定

---

## **7. ADT：Hash Table 操作**

* `Insert(k, v)`
* `Search(k)`
* `Delete(k)`
* 平均：**O(1)**
* 最差：**O(n)**（發生大量碰撞時）

---

## **8. 優點 & 缺點**

### 優點

* 查找/插入/刪除 = O(1)
* 適合大量 lookup（DNS、DB index）

### 缺點

* 無排序性
* 碰撞一定會發生
* 高 load factor 時 open addressing 效能下降

---

## **9. 常見應用**

* DNS Caching（URL → IP）
* Compiler symbol table
* Database indexing
* Cache / memory management


