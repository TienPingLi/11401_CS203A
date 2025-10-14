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
# 💻 數據結構作業筆記：陣列與鏈結串列特性深度分析

**主題:** 兩種核心數據結構：陣列與鏈結串列的對比分析 (Assignment III - A4 討論區塊)
**分析重點:** 記憶體分佈、元素存取效率、操作成本、以及實現選擇排序的優劣。

---

## 區塊一：核心特性對比表格

以下是陣列 (Array) 與鏈結串列 (Linked List) 在結構、記憶體和操作成本上的根本差異：

| 特性方面 (Aspect) | 陣列 (Array) | 鏈結串列 (Linked List) | 差異與影響 (The Core Difference) |
| :--- | :--- | :--- | :--- |
| **記憶體分佈** | **連續記憶體** (Contiguous Memory) | **非連續記憶體** (Non-contiguous Memory) | 陣列利用記憶體連續性，實現高效的隨機存取。 |
| **元素存取** | **隨機存取 (Random Access)** | **循序存取 (Sequential Access)** | 陣列：$\mathbf{O(1)}$ 存取任意元素。 鏈結串列：$\mathbf{O(n)}$ 存取第 $k$ 個元素。 |
| **插入/刪除** | $\mathbf{O(n)}$ (需移動後續元素) | **$\mathbf{O(1)}$** (只需修改指針) | 鏈結串列在處理頻繁變動的動態數據時更具優勢。 |
| **空間開銷** | **低** (僅儲存數據元素) | **高** (每個節點需額外儲存指針) | 鏈結串列用更高的空間開銷換取操作的靈活性。 |
| **結構彈性** | **固定大小** | **動態大小** | 鏈結串列可輕鬆擴展，無需預先分配空間。 |
| **可視化** | 較容易 (固定、連續) | 較困難 (分散、依靠指針) | 陣列在概念上更容易理解和繪製。 |

---

## 區塊二：結構特性詳解

### 🚀 陣列特性 (Array Characteristics)

| 優勢 (Pros) | 劣勢 (Cons) |
| :--- | :--- |
| **存取高效:** 支援 $\mathbf{O(1)}$ 隨機存取，適用於需要頻繁讀取或查找的場景。 | **操作低效:** 在中間位置插入或刪除元素需要移動大量數據，成本為 $\mathbf{O(n)}$。 |
| **空間高效:** 記憶體開銷低，沒有儲存指針的額外負擔。 | **大小固定:** 初始化後大小通常固定，難以動態調整容量。 |
| **遍歷快速:** 元素連續儲存，具有良好的記憶體局部性，遍歷效率高。 | **靈活性差:** 難以適應數據量頻繁變化的需求。 |

### ⛓️ 鏈結串列特性 (Linked List Characteristics)

| 優勢 (Pros) | 劣勢 (Cons) |
| :--- | :--- |
| **操作高效:** 在已知節點的情況下，插入和刪除只需修改指針，成本為 $\mathbf{O(1)}$。 | **存取低效:** 只能進行循序存取，查找第 $k$ 個元素需要 $\mathbf{O(k)}$ 時間。 |
| **結構靈活:** 大小可動態調整，適合數據量不確定或頻繁變動的應用。 | **空間浪費:** 每個節點必須儲存指針，增加了整體記憶體開銷 (Overhead)。 |
| **記憶體分散:** 節點可分散於記憶體各處，充分利用非連續的可用空間。 | **遍歷複雜:** 遍歷必須依賴指針導航，不能利用記憶體局部性，常數時間性能較差。 |

---

## 區塊三：選擇排序的實現選擇

**選擇排序**的效率瓶頸在於其內層循環的**尋找最小值**操作。

1.  **陣列實現 Selection Sort：**
    * 每次尋找最小值（遍歷 $\mathbf{O(n)}$）時，陣列都能利用 $\mathbf{O(1)}$ 的隨機存取快速跳轉到下一個元素進行比較。
    * **總時間複雜度：** $\mathbf{O(n^2)}$。

2.  **鏈結串列實現 Selection Sort：**
    * 雖然遍歷未排序部分也是 $\mathbf{O(n)}$，但由於鏈結串列缺乏隨機存取能力，每個元素的存取都需要 $\mathbf{O(1)}$ 的指針追蹤，實務上，由於指針操作和缺乏局部性，效率常數時間會比陣列高。
    * **總時間複雜度：** $\mathbf{O(n^2)}$。

#### 結論：
對於核心操作是**查找**（尋找最小值）而非**插入/刪除**的選擇排序算法，**陣列**是更優的選擇。它提供了更高效的元素存取速度 ($\mathbf{O(1)}$)，能夠更有效地執行內層循環的比較操作。
