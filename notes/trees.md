# 📘 Data Structures — Trees

## #1 Tree（樹）

樹是一種**非線性、階層式**的資料結構，由節點（node）與邊（edge）構成。

* **Root（根）**：最頂端的節點
* **Branch（分支）**：從根往下延伸的層級
* **Level（層級）**：節點所在的高度
* **Hierarchy（階層）**：上下結構，父節點與子節點

### 📌 生活中的樹

* 家族樹（Family Tree）
* 檔案系統（File System Hierarchy）

---

## #2 Linked List → Tree（線性 → 階層）

| 結構                 | 指標          | 描述              |
| ------------------ | ----------- | --------------- |
| Singly Linked List | next        | 只能接一個後繼         |
| Doubly Linked List | prev, next  | 前後各一個           |
| Binary Tree Node   | left, right | **可分支**，從線性變成階層 |

**多個指標 → 分支 → 形成樹狀**

---

## #3 Tree Terminology（術語）

* **Root**：最頂端節點
* **Parent / Child**：父子關係
* **Leaf**：無子節點
* **Sibling**：同一父節點的子
* **Edge**：節點與節點間連線
* **Depth**：從 root 到節點的距離
* **Height**：從節點到最深葉子的最長距離
* **Degree / Fan-out**：每個節點最多有幾個子節點

---

## #4 Tree Types（樹的種類）

### 🎯 **核心/基本種類**

| 類型                       | 描述            | 用途                |
| ------------------------ | ------------- | ----------------- |
| Full Binary Tree         | 每節點 0 或 2 子節點 | ML decision trees |
| Complete Binary Tree     | 除最底層外皆滿       | heap              |
| Binary Search Tree (BST) | 左 < 根 < 右     | 搜尋、排序             |
| Balanced Tree            | 高度平衡          | 快速搜尋              |
| General Tree             | 任意多子節點        | 組織架構、XML          |
| N-ary Tree               | 最多 N 子節點      | 遊戲決策（例如棋盤 AI）     |
| Trie                     | 字元前綴樹         | 字典、自動補字           |

### 🎯 **進階樹**

| 類型  | 用途 |
|------|------|
| B-Tree / B+Tree | 資料庫、檔案系統 |
| Segment Tree | 區間查詢 |
| Fenwick Tree | Prefix sum |
| KD-tree | 最近鄰搜尋 |
| Quad Tree | 2D 分割 |
| Octree | 3D 空間分割 |
| Heap Tree | priority queue |
| Treap | BST+Heap |
| Splay Tree | 自調整 BST |

---

## #5 Tree Family（家族）

1. **General Tree**：任意多子
2. **Binary Tree**：至多 2 子
3. **Binary Search Tree（BST）**：左 < 根 < 右
4. **Balanced BST**：高度接近 log n（AVL、Red-Black）

---

## #6 Tree Traversal（走訪）

### 🌳 深度優先（DFT）

| 順序        | 訪問順序                | 用途        |
| --------- | ------------------- | --------- |
| Preorder  | Root → Left → Right | 複製樹       |
| Inorder   | Left → Root → Right | 取得 BST 排序 |
| Postorder | Left → Right → Root | 刪除樹       |

### 🌳 廣度優先（BFT / Level order）

* 用 queue
* 逐層訪問

---

## #7 Tree Representation（表示法）

1. **List representation**
2. **Left child – right sibling**：可把 General Tree 轉成 Binary Tree
3. **Degree-two binary representation**

---

## #8 General Tree → Binary Tree

流程：

1. 先做 left-child right-sibling 表示
2. 旋轉 45°
3. 得到二元樹版本

好處：
可以統一用 BST、AVL 之類的二元樹方法分析一般樹

---

## #9 Balanced vs Unbalanced

### 平衡樹優點

* **搜尋、插入 O(log n)**

### 不平衡（skewed）

若輸入為：
`1, 2, 3, 4, 5`
BST 會變成像 linked list → O(n)

---

## #10 Balancing Strategies（平衡策略）

| 樹               | 方法               |
| --------------- | ---------------- |
| AVL             | 左右高度差 ≤ 1        |
| Red-Black       | 顏色規則             |
| B-Tree / B+Tree | 多層、多 key，用於 Disk |

---

## #11 ADT: Binary Tree

```
Create()
IsEmpty(bt)
MakeBT(bt1, item, bt2)
Lchild(bt)
Rchild(bt)
Data(bt)
```

---

## #12 Binary Tree（純結構）

* 每節點最多 2 子
* 沒有排序要求

---

## #13 Binary Search Tree（BST）

BST property:

* 左子樹所有節點 < root
* 右子樹所有節點 > root
* 遞迴成立

---

## #14 Binary Tree / BST 範例

輸入：

```
52, 18, 82, 7, 69, 36, 95, 3, 11, 23, 27,
41, 60, 64, 78, 31, 45, 56, 73, 89
```

展示內容包含：

* Binary Tree（插入順序）
* Binary Tree array representation
* BST（排序插入）
* BST array representation（可能有洞）

---

## #15 BST Deletion（刪除）

### Case 1：Leaf

→ 直接刪

### Case 2：One child

→ 子上移

### Case 3：Two children

→ 用以下取代：

* **左子樹最大值（inorder predecessor）**
* **右子樹最小值（inorder successor）**

---

## #16 BST Complexity

| 操作     | 時間（取決於樹高 h） |
| ------ | ----------- |
| Insert | O(h)        |
| Delete | O(h)        |
| Search | O(h)        |

### 若平衡：

**O(log n)**

### 若 skewed：

**O(n)**

---

## #17 AVL Tree（自平衡 BST）

* 條件：每節點左右高度差 ≤ 1
* 插入刪除時會自動旋轉調整
* 搜尋/插入/刪除皆 O(log n)

---

## #18 Tree Evolution

1. **Binary Tree**：只有形狀限制
2. **BST**：加排序規則
3. **AVL Tree**：再加高度規則
4. **Red-Black Tree**：高度平衡但更鬆散（保證 log n）

---


## #19 Reference

* [https://www.cs.usfca.edu/~galles/visualization/Algorithms.html](https://www.cs.usfca.edu/~galles/visualization/Algorithms.html)
* [https://kubokovac.eu/gnarley-trees/](https://kubokovac.eu/gnarley-trees/)
* 搜尋關鍵字：AVL、BST、Red-Black、B-Tree、B+ Tree
---
本筆記/專案的部分內容係輔助生成自人工智慧（AI）。筆記內容已由本人進行人工審核、修正與驗證，以確保其準確性與可靠性。儘管如此，使用者仍應自行評估資訊的正確性。
