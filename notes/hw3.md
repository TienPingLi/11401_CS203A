# 💻 作業三：鏈結串列選擇排序 (Linked List Selection Sort)
---

## A1. [cite_start]鏈結串列表示法繪圖 (5 pts) [cite: 53]

### a. [cite_start]單個節點的視覺表示 (2 pts) [cite: 54]
[cite_start]一個節點包含一個**值字段 (value field)** 和一個指向下一個節點的**指針字段 (pointer field)**。 [cite: 12]

$$[\text{值} \mid \bullet] \rightarrow \text{下一節點}$$

### b. [cite_start]包含給定整數的鏈結串列結構 (3 pts) [cite: 55]
[cite_start]頭指針 (`head`) 指向第一個節點，最後一個節點的 `next` 指針為 `NULL`。 [cite: 35]

$$\text{head} \rightarrow [60 \mid \bullet] \rightarrow [24 \mid \bullet] \rightarrow [15 \mid \bullet] \rightarrow [42 \mid \bullet] \rightarrow [20 \mid \bullet] \rightarrow [11 \mid \bullet] \rightarrow [90 \mid \bullet] \rightarrow [8 \mid \text{NULL}]$$

---

## A2. [cite_start]用整數填充 (32 pts) [cite: 57]

| Node \# | Value (值) | Next Pointer (下一指針) |
| :---: | :---: | :---: |
| **1** | **60** | $\rightarrow$ Node [ **2** ] |
| **2** | **24** | $\rightarrow$ Node [ **3** ] |
| **3** | **15** | $\rightarrow$ Node [ **4** ] |
| **4** | **42** | $\rightarrow$ Node [ **5** ] |
| **5** | **20** | $\rightarrow$ Node [ **6** ] |
| **6** | **11** | $\rightarrow$ Node [ **7** ] |
| **7** | **90** | $\rightarrow$ Node [ **8** ] |
| **8** | **8** | [cite_start]$\rightarrow$ Node [ **NULL** ] | [cite: 60, 63]

---

## A3. [cite_start]選擇排序 - 步驟追蹤 (45 pts) [cite: 65]

[cite_start]**初始列表:** $\text{head} \rightarrow [60|\bullet]\rightarrow[24|\bullet]\rightarrow[15|\bullet]\rightarrow[42|\bullet]\rightarrow[20|\bullet]\rightarrow[11|\bullet]\rightarrow[90|\bullet]\rightarrow[8|\text{NULL}]$ [cite: 9]

[cite_start]**注意：** 根據作業要求，只交換節點的**值** (`i->val, min_node->val`)，不修改 `next` 指針。 [cite: 31, 27]

### [cite_start]Step 1 (示例) [cite: 67, 68]
* **$i$ (當前節點值):** $60$
* **找到最小值:** $8$
* **呼叫交換函數:** **Yes**; swap $(60, 8)$。
* [cite_start]**結果列表:** $\text{head} \rightarrow [8|\bullet]\rightarrow[24|\bullet]\rightarrow[15|\bullet]\rightarrow[42|\bullet]\rightarrow[20|\bullet]\rightarrow[11|\bullet]\rightarrow[90|\bullet]\rightarrow[60|\text{NULL}]$ [cite: 70]

### [cite_start]Step 2 [cite: 71]
* **$i$ (當前節點值):** $24$ (Node 2)
* **在未排序後綴中找到最小值:** $11$
* [cite_start]**呼叫交換函數:** **Yes**; swap $(24, 11)$。 [cite: 72, 73, 74, 75]
* [cite_start]**結果列表:** $\text{head} \rightarrow [8|\bullet]\rightarrow[$ **11** $|\bullet]\rightarrow[15|\bullet]\rightarrow[42|\bullet]\rightarrow[20|\bullet]\rightarrow[$ **24** $|\bullet]\rightarrow[90|\bullet]\rightarrow[60|\text{NULL}]$ [cite: 76, 77, 78, 79, 80, 81, 82, 83, 84]

### [cite_start]Step 3 [cite: 86]
* **$i$ (當前節點值):** $15$ (Node 3)
* **在未排序後綴中找到最小值:** $15$
* [cite_start]**呼叫交換函數:** **No**; swap $(15, 15)$。 [cite: 87, 88]
* [cite_start]**結果列表:** $\text{head} \rightarrow [8|\bullet]\rightarrow[11|\bullet]\rightarrow[$ **15** $|\bullet]\rightarrow[42|\bullet]\rightarrow[20|\bullet]\rightarrow[24|\bullet]\rightarrow[90|\bullet]\rightarrow[60|\text{NULL}]$ [cite: 89, 90, 91, 92, 93, 94, 95, 96, 97]

### [cite_start]Step 4 [cite: 98]
* **$i$ (當前節點值):** $42$ (Node 4)
* **在未排序後綴中找到最小值:** $20$
* [cite_start]**呼叫交換函數:** **Yes**; swap $(42, 20)$。 [cite: 99, 100, 101, 102, 103]
* [cite_start]**結果列表:** $\text{head} \rightarrow [8|\bullet]\rightarrow[11|\bullet]\rightarrow[15|\bullet]\rightarrow[$ **20** $|\bullet]\rightarrow[$ **42** $|\bullet]\rightarrow[24|\bullet]\rightarrow[90|\bullet]\rightarrow[60|\text{NULL}]$ [cite: 104, 105, 106, 107, 108, 109, 110, 111, 112]

---

## A4. [cite_start]討論：陣列 (Array) vs. 鏈結串列 (Linked List) (68 pts) [cite: 115]

### [cite_start]時間複雜度比較 (14 pts) [cite: 123]

| Aspect / Operation (方面/操作) | Array (陣列) | Linked List (鏈結串列) | [cite_start]Explanation (解釋) [cite: 124] |
| :--- | :---: | :---: | :--- |
| Access Element (存取元素) | (1) $\mathbf{O(1)}$ | (2) $\mathbf{O(n)}$ | [cite_start]陣列允許直接索引；鏈結串列需要遍歷。 [cite: 124] |
| Find Minimum (尋找最小值) | (3) $\mathbf{O(n)}$ | (4) $\mathbf{O(n)}$ | [cite_start]兩者都必須掃描所有剩餘的元素/節點。 [cite: 124] |
| Swap Operation (交換操作) | (5) $\mathbf{O(1)}$ | (6) $\mathbf{O(1)}$ | [cite_start]在陣列中，通過索引交換；在鏈結串列中，交換節點的值。 [cite: 124] |
| Traversal Between Elements (元素間的遍歷) | (7) $\mathbf{O(1)}$ | (8) $\mathbf{O(1)}$ | [cite_start]鏈結串列遍歷需要指針導航。 [cite: 124] |
| Overall Time Complexity (Selection Sort) (總體時間複雜度) | (9) $\mathbf{O(n^2)}$ | (10) $\mathbf{O(n^2)}$ | [cite_start]兩者都涉及巢狀遍歷以尋找最小值；鏈結串列增加了遍歷開銷。 [cite: 124] |
| Space Complexity (空間複雜度) | (11) $\mathbf{O(1)}$ | (12) $\mathbf{O(1)}$ | [cite_start]如果交換值而非節點，則兩種排序都是原地（in-place）的。 [cite: 124] |
| Implementation Overhead (實現開銷) | (13) **Low** (低) | (14) **Moderate** (中等) | [cite_start]鏈結串列需要指針操作和仔細的空值檢查。 [cite: 124] |

### [cite_start]特性比較 (54 pts) [cite: 131, 133]

| Aspect (方面) | Array (陣列) | Linked List (鏈結串列) |
| :--- | :--- | :--- |
| **Storage (儲存)** | (1) [cite_start]Contiguous memory allocation (連續記憶體) [cite: 134] | (2) [cite_start]Non-contiguous memory allocation (非連續記憶體) [cite: 135] |
| **Access (存取)** | (3) [cite_start]Random Access, $\mathbf{O(1)}$ (隨機存取) [cite: 136] | (4) [cite_start]Sequential Access, $\mathbf{O(n)}$ (循序存取) [cite: 140] |
| **Extra Variables (額外變數)** | (5) [cite_start]Minimal (只需要索引) [cite: 141] | (6) [cite_start]Pointer storage (每個節點需要額外的指針儲存空間) [cite: 142] |
| **Traversal (遍歷)** | (7) [cite_start]Fast, simple index arithmetic (快速，基於索引) [cite: 143] | (8) [cite_start]Sequential, follows `next` pointers (循序，遵循指針) [cite: 144] |
| **Overhead (開銷)** | (9) [cite_start]Low memory overhead (低記憶體開銷) [cite: 145] | (10) [cite_start]Higher memory overhead due to pointers (由於指針而有更高的記憶體開銷) [cite: 149] |
| **Visualization (可視化)** | (11) [cite_start]Easier (固定大小的單元格) [cite: 150] | (12) [cite_start]Moderate (需要繪製節點和指針) [cite: 151] |
| **Swaps (交換)** | (13) [cite_start]Quick $\mathbf{O(1)}$ value exchange (快速值交換) [cite: 152] | (14) [cite_start]$\mathbf{O(1)}$ value exchange (已知節點) [cite: 153] |
| **Flexibility (靈活性)** | (15) [cite_start]Low (固定大小，插入/刪除昂貴 $\mathbf{O(n)}$) [cite: 154] | (16) [cite_start]High (動態大小，插入/刪除快 $\mathbf{O(1)}$) [cite: 158] |
| **Overall (總結)** | (17) [cite_start]**更適合 Selection Sort**，因為元素存取 $\mathbf{O(1)}$。 [cite: 159] | (18) [cite_start]**更適合動態操作**，因為插入/刪除 $\mathbf{O(1)}$。 [cite: 160] |

### [cite_start]指導問題討論 [cite: 116]

1.  [cite_start]**執行了多少次交換 (swaps/exchanges)？** [cite: 117]
    * 在選擇排序中，對於 $n$ 個元素，最多執行 $n-1$ 次交換。
    * 在前 4 步中，我們執行了 $3$ 次交換 (Step 1, Step 2, Step 4)。

2.  [cite_start]**陣列與鏈結串列的遍歷成本如何？** [cite: 119]
    * [cite_start]**陣列 (Array):** 由於支持隨機存取，遍歷元素間的成本是 $\mathbf{O(1)}$ [cite: 124, 143]，效率高。
    * [cite_start]**鏈結串列 (Linked List):** 遍歷是循序的，訪問第 $k$ 個元素需要從頭開始跟隨 $k$ 個指針 [cite: 13, 144][cite_start]，成本是 $\mathbf{O(k)}$，總體遍歷為 $\mathbf{O(n)}$ [cite: 13, 124, 144]。

3.  [cite_start]**您看到了哪些記憶體/開銷差異？** [cite: 120]
    * [cite_start]鏈結串列有更高的**記憶體開銷** [cite: 10, 149][cite_start]。每個節點必須儲存數據值，以及至少一個指向下一個節點的指針 [cite: 12][cite_start]，這佔用了額外的空間 [cite: 142]。
    * [cite_start]陣列只儲存數據元素，開銷較低 [cite: 145]。

4.  [cite_start]**哪種表示法更容易可視化？** [cite: 121]
    * [cite_start]**陣列 (Array)** 更容易可視化 [cite: 150][cite_start]。它們是連續的單元格，結構簡單。鏈結串列需要繪製指針來表示非連續的記憶體關係，相對複雜 [cite: 151]。

5.  [cite_start]**您會選擇哪種表示法來實現選擇排序？為什麼？** [cite: 122]
    * [cite_start]我會選擇**陣列 (Array)** [cite: 17, 159]。
    * [cite_start]**原因:** 選擇排序需要大量的遍歷（在 $\mathbf{O(n^2)}$ 的總時間複雜度中）來尋找最小值 [cite: 14, 17, 124][cite_start]。儘管兩種結構的總時間複雜度都是 $\mathbf{O(n^2)}$ [cite: 124][cite_start]，但陣列的 $\mathbf{O(1)}$ 隨機存取 [cite: 124, 136] [cite_start]在訪問和交換元素時更有效率 [cite: 152][cite_start]。鏈結串列 $\mathbf{O(1)}$ 的插入/刪除優勢在選擇排序中沒有被利用 [cite: 154, 158]。
