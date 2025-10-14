# 💻 數據結構作業筆記：鏈結串列選擇排序

**課程主題:** 資料結構：鏈結串列 (Linked List) 與選擇排序 (Selection Sort) 應用
**輸入數據:** $60, 24, 15, 42, 20, 11, 90, 8$

---

## 📌 區塊一：鏈結串列結構表示 (A1, A2)

### 1. 節點表示與記憶體特性
| 方面 | 描述 |
| :--- | :--- |
| **單個節點** | 包含值字段 (Value) 和下一指針字段 (Next Pointer)。<br> $[ \text{值} \mid \bullet ] \rightarrow \text{下一節點}$ |
| **記憶體分配** | 非連續 (Non-contiguous memory)。 |
| **開銷** | 高。每個節點需要額外的空間來儲存指針。 |

### 2. 初始鏈結串列表達式
$$\text{head} \rightarrow [60 \mid \bullet] \rightarrow [24 \mid \bullet] \rightarrow [15 \mid \bullet] \rightarrow [42 \mid \bullet] \rightarrow [20 \mid \bullet] \rightarrow [11 \mid \bullet] \rightarrow [90 \mid \bullet] \rightarrow [8 \mid \text{NULL}]$$

### 3. 節點內容細節

| Node \# | Value (值) | Next Pointer (下一指針) |
| :---: | :---: | :---: |
| **1** | **60** | $\rightarrow$ Node [ **2** ] |
| **2** | **24** | $\rightarrow$ Node [ **3** ] |
| **3** | **15** | $\rightarrow$ Node [ **4** ] |
| **4** | **42** | $\rightarrow$ Node [ **5** ] |
| **5** | **20** | $\rightarrow$ Node [ **6** ] |
| **6** | **11** | $\rightarrow$ Node [ **7** ] |
| **7** | **90** | $\rightarrow$ Node [ **8** ] |
| **8** | **8** | $\rightarrow$ Node [ **NULL** ] |

---

## 🚀 區塊二：選擇排序步驟追蹤 (A3)

**算法：** 針對 $60, 24, 15, 42, 20, 11, 90, 8$ 進行選擇排序，**只交換節點的值**。

| Step | Current Node $i$ (值) | Minimum Value (找到最小值) | Swap Action (交換行為) | Resulting List Head (列表開頭狀態) |
| :---: | :---: | :---: | :---: | :--- |
| **初始** | N/A | N/A | N/A | $[60|\bullet]\rightarrow[24|\bullet]\rightarrow[15|\bullet]\rightarrow[42|\bullet]\rightarrow\dots$ |
| **1** | 60 | 8 | **YES** (60 $\leftrightarrow$ 8) | $[8|\bullet]\rightarrow[24|\bullet]\rightarrow[15|\bullet]\rightarrow[42|\bullet]\rightarrow\dots$ |
| **2** | 24 | 11 | **YES** (24 $\leftrightarrow$ 11) | $[8|\bullet]\rightarrow[11|\bullet]\rightarrow[15|\bullet]\rightarrow[42|\bullet]\rightarrow\dots$ |
| **3** | 15 | 15 | **NO** (最小值已在位) | $[8|\bullet]\rightarrow[11|\bullet]\rightarrow[15|\bullet]\rightarrow[42|\bullet]\rightarrow\dots$ |
| **4** | 42 | 20 | **YES** (42 $\leftrightarrow$ 20) | $[8|\bullet]\rightarrow[11|\bullet]\rightarrow[15|\bullet]\rightarrow[20|\bullet]\rightarrow\dots$ |

---

## 📊 區塊三：性能分析與討論 (A4)

### 1. 時間與空間複雜度 (Time and Space Complexity)

| 方面 / 操作 | Array (陣列) | Linked List (鏈結串列) | 解釋 |
| :--- | :---: | :---: | :--- |
| **元素存取** | $\mathbf{O(1)}$ (隨機) | $\mathbf{O(n)}$ (循序) | 陣列透過索引，鏈結串列必須遍歷。 |
| **尋找最小值** | $\mathbf{O(n)}$ | $\mathbf{O(n)}$ | 兩者皆需掃描所有未排序元素。 |
| **總體時間複雜度** | $\mathbf{O(n^2)}$ | $\mathbf{O(n^2)}$ | 選擇排序的核心是 $\mathbf{O(n)}$ 尋找最小值，重複 $\mathbf{O(n)}$ 次。 |
| **空間複雜度** | $\mathbf{O(1)}$ | $\mathbf{O(1)}$ | 兩種都是原地 (in-place) 排序。 |

### 2. 結構與操作特性比較

| Aspect (方面) | Array (陣列) | Linked List (鏈結串列) |
| :--- | :--- | :--- |
| **存取方式** | 隨機存取 (Random Access) | 循序存取 (Sequential Access) |
| **彈性/大小** | 低 (固定大小) | 高 (動態大小，插入/刪除 $\mathbf{O(1)}$) |
| **可視化** | 較容易 (連續單元格) | 較困難 (非連續指針) |
| **遍歷成本** | 快速， $\mathbf{O(1)}$ 步進 | 循序， $\mathbf{O(1)}$ 步進，但到達 $k$-th 元素需 $\mathbf{O(k)}$ |

### 3. 結論

#### 選擇排序的交換次數
* **最多次數:** 對於 $n$ 個元素，最多執行 $n-1$ 次交換。
* **實際次數:** 根據數據分佈而定，例如本例前 4 步發生了 3 次交換。

#### 實現選擇排序的最佳選擇
* **選擇:** **陣列 (Array)**。
* **原因:** 雖然兩者的漸近時間複雜度都是 $\mathbf{O(n^2)}$，但陣列具有 $\mathbf{O(1)}$ 的隨機存取能力，這使得內部循環中元素的訪問、比較和最終交換操作在實際執行上更有效率。鏈結串列在存取任意元素時的 $\mathbf{O(n)}$ 成本會導致額外的開銷。

---
