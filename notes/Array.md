
---

# 資料結構：陣列（Arrays）

> 本文件分為兩個部分：
> **前半為「考試速查版」**，適合期中期末快速複習
> **後半為「課堂用超詳細版本」**，適合上課、報告與長期筆記整理

---

## 📌 快速導覽（Table of Contents）

* [一、考試速查版（Exam Cheat Sheet）](#一考試速查版exam-cheat-sheet)
* [二、課堂用超詳細版本（Lecture Notes）](#二課堂用超詳細版本lecture-notes)

---

# 一、考試速查版（Exam Cheat Sheet）

> 👉 **給考前 10～15 分鐘快速掃描用**

---

## 1️⃣ 陣列基本概念

* **定義**：連續記憶體的相同型態資料集合
* **存取方式**：索引（Index）
* **存取時間**：`O(1)`
* **大小**：通常固定

---

## 2️⃣ 靜態陣列 vs 動態陣列

| 類型   | 特性                        |
| ---- | ------------------------- |
| 靜態陣列 | 編譯期大小固定                   |
| 動態陣列 | 執行期配置（`malloc / realloc`） |

* `realloc` 可能導致 **位址改變**

---

## 3️⃣ 多維陣列重點

* 2D：`array[row][col]`
* 3D：`array[plane][row][col]`
* **索引順序不可顛倒**

---

## 4️⃣ ADT：Array

* 元素形式：`<index, value>`
* 基本操作：

  * `Create`
  * `Retrieve`
  * `Store`

---

## 5️⃣ 排序演算法（升序）

| 排序法       | 核心概念      |
| --------- | --------- |
| Bubble    | 相鄰比較，大的往後 |
| Selection | 找最小，放最前   |
| Insertion | 插入已排序區    |

---

## 6️⃣ 搜尋演算法

| 方法            | 條件  | 複雜度        |
| ------------- | --- | ---------- |
| Linear Search | 未排序 | `O(n)`     |
| Binary Search | 已排序 | `O(log n)` |

---

## 7️⃣ STL 容器比較

| 項目   | `std::array` | `std::vector` |
| ---- | ------------ | ------------- |
| 大小   | 固定           | 可變            |
| 記憶體  | Stack        | Heap          |
| 插入彈性 | 低            | 高             |

---

## 8️⃣ 時間複雜度總整理

| 操作     | 複雜度                 |
| ------ | ------------------- |
| Access | `O(1)`              |
| Update | `O(1)`              |
| Insert | `O(n)`              |
| Delete | `O(n)`              |
| Search | `O(n)` / `O(log n)` |

---

## 9️⃣ 優缺點一句話

* ✅ 快速隨機存取
* ❌ 插入刪除成本高

---

👉 **考試看到 array，先想到：**

> 「連續記憶體、O(1) 存取、插刪 O(n)」

---

# 二、課堂用超詳細版本（Lecture Notes）

> 👉 **給上課、作業、報告、長期筆記用**

---

## 1. 陣列的基礎定義（Array Fundamentals）

### 基本概念

* 陣列（Array）是一種將資料儲存在 **連續記憶體位置（Contiguous Memory）** 的資料結構
* 每個元素透過 **索引（Index）** 存取
* 索引通常從 `0` 開始

### 主要特性

* 固定大小（Static）
* 支援 **常數時間 O(1)** 存取
* 所有元素型態一致，利於位移與計算

---

## 2. 靜態陣列的維度與操作（Static Arrays）

### 一維陣列（1D Array）

```c
int array[5] = {10, 20, 30, 40, 50};
```

* 記憶體配置為連續 5 個 `int`
* `array[2]` → 30

---

### 二維陣列（2D Array）

```c
int array2d[3][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12}
};
```

* 3 列（rows）× 4 行（columns）
* 存取方式：

```c
array2d[1][2]; // 7
```

---

### 三維陣列（3D Array）

```c
int array3d[2][3][4];
```

* 可視為多個 2D 平面
* 常用於影像、體積資料（CT、MRI）

---

## 3. 動態陣列（Dynamic Arrays）

### C 語言配置流程

```c
int* arr = (int*)malloc(n * sizeof(int));
arr = (int*)realloc(arr, 2 * n * sizeof(int));
free(arr);
```

### 重點觀念

* `malloc` / `realloc` 都在 **Heap**
* `realloc` 可能：

  * 原地擴充
  * 搬移整段資料（位址改變）

---

## 4. ADT：Array（抽象資料型態）

* 陣列 ≠ 實作
* ADT 描述「**能做什麼**」，不描述「**怎麼做**」

### 操作定義

* `Create(j, list)`
* `Retrieve(A, i)`
* `Store(A, i, x)`

---

## 5. 排序演算法（Sorting）

### Bubble Sort

* 多次掃描
* 每輪把最大值推到最後

### Selection Sort

* 每輪找最小值
* 交換到前端

### Insertion Sort

* 類似打牌插牌
* 適合小資料量

---

## 6. 搜尋演算法（Searching）

### Linear Search

* 不需排序
* 每個都看

### Binary Search

* 必須排序
* 每次砍一半

---

## 7. STL：`std::array` vs `std::vector`

* `std::array`：編譯期大小，效能最佳
* `std::vector`：動態大小，實務最常用

---

## 8. 複雜度分析（Complexity Analysis）

| 操作     | 說明    |
| ------ | ----- |
| Insert | 需整體位移 |
| Delete | 同上    |
| Access | 直接算位址 |

---

## 9. 實務應用與限制

### 應用

* 表格資料
* 快取（Cache）
* 規則清單（如 Nginx `ngx_array_t`）

### 限制

* 不適合頻繁插入刪除
* 容量調整成本高

---

## ✨ 結語

陣列是所有資料結構的基礎，
**後續的 vector、stack、queue、matrix 都建立在 array 之上。**

---

