

# 🧱 專題三：堆疊與佇列（Stacks and Queues）

> 本章結構與 **Arrays / Linked Lists 完全一致**：
> **前半為考試速查版，後半為課堂用超詳細版本**

---

## ⚡ 第一部分：考試速查版（Quick Reference）

---

## 1️⃣ 堆疊（Stack）— LIFO

### 核心原則

* **後進先出（Last-In, First-Out, LIFO）**
* 所有操作都在 **同一端（Top）**

### 基本操作

* **Push**：將元素推入頂端
* **Pop**：移除並回傳頂端元素
* **Peek / Top**：查看頂端但不移除

### 時間複雜度

* Push：`O(1)`
* Pop：`O(1)`
* Peek：`O(1)`

### 常見應用

* 函式呼叫（Call Stack）
* Undo / Redo
* 括號匹配（Parentheses Matching）
* 反轉資料

---

## 2️⃣ 佇列（Queue）— FIFO

### 核心原則

* **先進先出（First-In, First-Out, FIFO）**
* 兩端操作：Front / Rear

### 基本操作

* **Enqueue**：從 Rear 加入
* **Dequeue**：從 Front 移除

### 時間複雜度

* Enqueue：`O(1)`
* Dequeue：`O(1)`

---

### 環形佇列（Circular Queue）

* 解決陣列實作中「前端空間浪費」問題
* 尾端可繞回開頭

```text
rear = (rear + 1) % capacity
```

---

## 3️⃣ 實作方式比較（考試愛考）

| 實作方式 | 優點   | 缺點               |
| ---- | ---- | ---------------- |
| 陣列   | 存取快  | 大小固定，可能 overflow |
| 鏈結串列 | 動態大小 | 指標額外空間           |

---

👉 **考試看到 Stack / Queue，先想到：**

> 「受限制線性結構、操作都在端點、Insert/Delete 都是 O(1)」

---

# 📘 第二部分：課堂用詳細版本（Detailed Notes）

---

## 一、堆疊（Stack）

### 1. 基本概念

* Stack 是一種 **受限制的線性資料結構**
* 只能在 **頂端（Top）** 進行插入與刪除
* 不支援隨機存取

```
Push → [  ] [  ] [Top]
Pop  ← [  ] [  ]
```

---

## 2. 抽象資料型態（ADT: Stack）

### 定義

* **Object**：n 個元素組成的有序集合
* **限制**：只允許在 Top 操作

### 基本操作

* `Create(size)`
* `IsFull(stack)`
* `IsEmpty(stack)`
* `Push(item)`
* `Pop()`

---

## 3. Stack 的實作範例

### 陣列實作（C 語言）

```c
int stack[MAX_SIZE];
int top = -1; // 空堆疊

void push(int item) {
    if (top >= MAX_SIZE - 1) return; // Overflow
    stack[++top] = item;
}

int pop() {
    if (top == -1) return -1; // Underflow
    return stack[top--];
}
```

### 重點

* `top = -1` 代表空
* `++top` 先移動再存
* Push / Pop 都是 `O(1)`

---

### 鏈結串列實作（概念）

* 將 **Head 當作 Top**
* 插入 / 刪除都在 Head

👉 **時間複雜度：`O(1)`**

---

## 二、佇列（Queue）

### 1. 基本概念

* Queue 模擬排隊
* 一端進（Rear），另一端出（Front）
* 不支援隨機存取

```
Front → [  ][  ][  ] ← Rear
```

---

## 2. 抽象資料型態（ADT: Queue）

### 定義

* **Object**：有序集合
* **限制**：一端插入，一端移除

### 基本操作

* `Enqueue(item)`
* `Dequeue()`
* `IsEmpty(queue)`
* `IsFull(queue)`

---

## 3. 環形佇列（Circular Queue）

### 問題來源

* 線性陣列實作中
* Dequeue 後 Front 前方空間無法再用

---

### 解法：頭尾相接（Modulo）

```c
rear = (rear + 1) % capacity;
front = (front + 1) % capacity;
```

### 空 / 滿判定方式

* **方法一**：保留一格不用
* **方法二**：使用計數器 `count`

---

## 三、應用與進階問題

---

## 1️⃣ Stack 的實際應用

### 括號匹配（Parentheses Matching）

* 遇 `(` → Push
* 遇 `)` → Pop
* 過程出錯或最後 Stack 非空 → 不匹配

---

### 遞迴與 Call Stack

* 系統用 Stack 儲存：

  * 回傳位址
  * 區域變數
* 過深遞迴 → Stack Overflow

---

## 2️⃣ 複雜度分析比較（補齊版）

| 操作      | Stack  | Queue  | 備註               |
| ------- | ------ | ------ | ---------------- |
| 插入      | `O(1)` | `O(1)` | 指標或 top/front 操作 |
| 移除      | `O(1)` | `O(1)` | 不需位移             |
| 存取 / 搜尋 | `O(n)` | `O(n)` | 不支援隨機存取          |

---

## 3️⃣ 常見考試 / 面試題型

### 用兩個 Stack 實作 Queue

* Push → Stack1
* Pop →

  * 若 Stack2 空
  * 將 Stack1 全部倒入 Stack2
  * 從 Stack2 Pop

👉 攤還時間複雜度：`O(1)`

---

### 迷宮問題（Maze / Backtracking）

* Stack 紀錄走過的路
* 走不通時 Pop 回上一格

---

## ✨ 本章總結（接老師語氣）

* Stack / Queue 都是 **受限制的線性結構**
* 設計重點在於「**操作位置被限制**」
* 是 **Tree / Graph / OS 排程** 的基礎

