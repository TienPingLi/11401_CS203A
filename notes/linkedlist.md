

# 🔗鏈結串列（Linked Lists）

> 本章結構與 **Arrays 章節完全一致**：
> **前半為考試速查版，後半為課堂用超詳細版本**

---

## ⚡ 考試速查版（Quick Reference）

### 核心特性

* **非連續記憶體（Non-contiguous Memory）**
* **動態配置（Dynamic Allocation）**
* **僅支援循序存取（Sequential Access）**

---

### 常見類型

| 類型                   | 特徵            |
| -------------------- | ------------- |
| Singly Linked List   | 只有 `next`     |
| Doubly Linked List   | `prev + next` |
| Circular Linked List | 尾節點指向頭節點      |

---

### 時間複雜度重點

* **存取（Access）**：`O(n)`
* **搜尋（Search）**：`O(n)`
* **插入 / 刪除（已知位置）**：`O(1)`

---

### 優缺點一句話

* ✅ 插入、刪除效率高（不需位移）
* ❌ 不支援隨機存取
* ❌ 指標額外佔用記憶體

---

👉 **考試看到 linked list，先想到：**

> 「非連續、用指標、Access O(n)、Insert/Delete O(1)」

---

## 📘 課堂詳解與範例（Detailed Notes & Examples）

---

## 1. 基本概念與結構

### 為什麼需要 Linked List？

* 陣列插入 / 刪除需要大量元素位移 → `O(n)`
* Linked List 只需改指標 → `O(1)`

---

### 節點（Node）概念

每個節點包含：

* **資料（data）**
* **指向下一個節點的指標（pointer）**

```
[data | next] → [data | next] → [data | NULL]
```

---

## 2. 節點定義實作

### C 語言（struct）

```c
struct Node {
    int data;
    struct Node* next;
};
```

---

### C++（class）

```cpp
class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};
```

---

## 3. 核心操作流程（指標操作重點）

> Linked List **考試與實作的核心就在「指標怎麼接」**

---

### 插入操作

**在 target 節點後插入 newNode**

```c
newNode->next = target->next;
target->next = newNode;
```

#### 指標變化示意

```
target → A
↓
target → newNode → A
```

* 時間複雜度：`O(1)`
* 不需搬移任何資料

---

### 刪除操作

**刪除 target 節點（需知道前驅 prev）**

```c
prev->next = target->next;
free(target);
```

* 關鍵：**一定要先接好，再 free**
* 否則會造成 memory leak 或斷鏈

---

## 4. 常見 Linked List 類型補充

### Doubly Linked List

```text
NULL ← [prev | data | next] ↔ [prev | data | next] → NULL
```

* 優點：可雙向走訪
* 缺點：多一個指標 → 記憶體成本較高

---

### Circular Linked List

```text
[head] → ... → [tail]
   ↑               ↓
   ←───────────────
```

* 常見應用：Round-robin scheduling

---

## 5. 節點交換方式比較（考試愛考）

### 方法一：交換資料（Swap Value）

```c
int temp = a->data;
a->data = b->data;
b->data = temp;
```

#### 缺點

* 大型資料拷貝成本高
* 可能破壞排序穩定性

---

### 方法二：交換指標（Swap Pointer）

```c
prev_a->next = b;
Node* temp = b->next;
b->next = a->next;
a->next = temp;
```

#### 特性

* ✅ 不搬資料
* ❌ 指標邏輯較複雜
* ❗ 一定要處理 `prev`

---

## 6. Linked List 的 Selection Sort（課堂重點）

### 為什麼要用 dummy node？

* 避免「刪 head」的特殊情況
* 簡化程式邏輯

---

### 排序流程概念

1. 使用 `dummy` 作為排序後串列的起點
2. 在未排序區找最小節點 `minNode`
3. 將 `minNode` 從原串列分離
4. 接到已排序串列尾端 `sortedTail->next`

```text
Unsorted → 找 min → 分離 → 接到 Sorted
```

* 時間複雜度：`O(n²)`
* 空間複雜度：`O(1)`

---
## 7. Linked List and Array
# 陣列與鏈結串列的比較（Comparison: Array vs. Linked List）      

| **操作 (Operation)** | **動態陣列 (Array, Dynamic)** | **鏈結串列 (Linked List)** |
|------------------------|-------------------------------|-----------------------------|
| **依索引存取 (Access by index)** | O(1) | O(n)（必須逐一遍歷 / must traverse） |
| **搜尋 (Search)** | O(n) | O(n) |
| **在開頭插入 (Insert at front)** | O(n) | O(1) |
| **在中間插入 (Insert at middle)** | O(n) | O(n) |
| **在結尾插入 (Insert at end)** | O(1)（攤銷時間 / amortized） | O(n)\* 或 O(1)\*\* |
| **刪除 (Delete)** | O(n) | O(n) 或 O(1)\*\*\*** |

\* 若為單向鏈結串列（singly linked list），在結尾插入需遍歷整個串列 → O(n)  
\*\* 若為雙向鏈結串列（doubly linked list）且尾端指標已知 → O(1)  
\*\*\* 若已知節點指標（pointer to node），刪除可為 O(1)
---

## ✨ 本章總結

* Linked List 的本質是：**資料 + 指標**
* 所有操作核心：**指標連接順序**
* 是 Stack、Queue、Graph 的基礎結構

---
本筆記/專案的部分內容係輔助生成自人工智慧（AI）。筆記內容已由本人進行人工審核、修正與驗證，以確保其準確性與可靠性。儘管如此，使用者仍應自行評估資訊的正確性。

---
