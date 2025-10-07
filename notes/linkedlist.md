
# 資料結構筆記：鏈結串列 (Linked Lists)

## 一、 基本概念與簡介

### 1\. 什麼是鏈結串列 (Linked List)？

**鏈結串列**是一種**線性資料結構**，它的元素（稱為**節點，Node**）在記憶體中不是儲存在**連續**的位置。

  * 每個**節點**包含兩部分：
    1.  **資料 (Data/Item)**：儲存實際的數值。
    2.  **參考/指標 (Reference/Pointer)**：指向序列中**下一個節點**的記憶體位址。
  * 串列中的最後一個節點的指標會指向 **NULL** (空引用)，表示串列的結束。
  * 整個串列是透過**頭節點 (Head)** 來存取第一個元素。

### 2\. 與陣列 (Array) 的比較

鏈結串列與陣列都是用來儲存一組資料，但它們在記憶體管理和操作效率上有顯著不同。

| 特性 | 陣列 (Array) | 鏈結串列 (Linked List) |
| :--- | :--- | :--- |
| **記憶體** | **連續**記憶體空間 | **非連續**記憶體空間 |
| **大小** | 固定大小（通常在編譯時確定） | 可在**執行時 (Runtime)** 增長或縮小 |
| **存取元素** | 透過索引 (Index) **直接存取** | 必須從 **Head** 開始**遍歷 (Traverse)** 才能存取 |
| **插入/刪除** | 需要移動大量元素，效率較低 (O(n)) | 只需調整前後節點的指標，效率較高 (O(1))（若已知節點位置） |

### 3\. 效率考量 (Complexity Analysis)

| 操作 | 陣列 (Array) | 鏈結串列 (Linked List) | 備註 |
| :--- | :--- | :--- | :--- |
| **存取元素** | $O(1)$ | $O(n)$ | 鏈結串列需要遍歷。 |
| **在已知位置插入/刪除** | $O(n)$ | $O(1)$ | 鏈結串列只需調整指標。 |
| **在列表尾部插入** | $O(1)$ 或 $O(n)$ | $O(n)$ | 單向串列需遍歷到尾部。 |
| **空間複雜度** | $O(n)$ | $O(n)$ | 鏈結串列需要額外的空間來儲存指標。 |

-----

## 二、 抽象資料型態 (ADT: Abstract Data Type)

ADT 定義了一組資料處理方法和規範，它只關注**能做什麼**，而不限制**如何實作**。

### ADT: LinkedList 的物件

鏈結串列 ADT 的物件是一個節點的有限序列：

  * **節點 (Node)**：包含一個資料項 (Item) 和一個指向下一個節點的參考 (Pointer)。
  * **終止點 (Null Reference)**：序列以一個空參考結束。

### ADT: LinkedList 的操作 (Functions)

| 函數名稱 | 描述 (功能) |
| :--- | :--- |
| `Create()` | 返回一個空的鏈結串列。 |
| `IsEmpty(L)` | 判斷串列 `L` 是否為空。 |
| `Length(L)` | 返回串列 `L` 中節點的數量。 |
| `Retrieve(L, p)` | 取得位置 `p` 的資料項。 |
| `Insert(L, p, x)` | 在位置 `p` 插入資料項 `x`，並返回更新後的串列。 |
| `Delete(L, p)` | 移除位置 `p` 的節點，並返回更新後的串列。 |
| `Update(L, p, x)` | 將位置 `p` 的資料項替換為 `x`。 |
| `Search(L, x)` | 返回資料項 `x` 第一次出現的位置。 |

-----

## 三、 單向鏈結串列實作 (Singly Linked List Implementation)

單向鏈結串列 (Singly Linked List) 是最基本的類型，每個節點只包含一個指向**下一個**節點的指標。

### 1\. C 語言實作 (使用 `struct`)

在 C 語言中，通常使用結構體 `struct` 來定義節點：

```c
// 定義節點結構
typedef struct node {
    int data;            // 節點資料（範例使用 int）
    struct node *next;   // 指向下一個節點的指標
} Node;

// 也可以使用以下方式 (檔案中的範例)
typedef struct list {
    int integerValue;
    struct list *nextPtr;
} IntegerNode;
```

### 2\. C++ 語言實作 (使用 `class`)

在 C++ 中，可以使用 `class` 來實現更好的**封裝 (Encapsulation)**。

#### 節點類別 (Node Class)

```cpp
// 節點類別
class Node {
public:
    int data;     // 儲存節點資料
    Node* next;   // 指向下一節點的指標

    // 建構子 (Constructor)
    Node(int value) {
        this->data = value;
        this->next = nullptr; // 將新節點的 next 初始化為空
    }
};
```

#### 鏈結串列類別 (LinkedList Class)

```cpp
// 鏈結串列類別 (Wrapper Class)
class LinkedList {
private:
    Node* head; // 鏈結串列的頭節點

public:
    // 建構子：初始化 Head 為空
    LinkedList() {
        head = nullptr;
    }

    // 範例操作：在尾部插入元素 (Insert at End)
    void insert(int value) {
        Node* newNode = new Node(value);

        // 1. 如果串列為空，新節點即為 Head
        if (head == nullptr) {
            head = newNode;
        } else {
            // 2. 遍歷到尾部
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            // 3. 將原尾節點指向新節點
            temp->next = newNode;
        }
    }

    // 範例操作：印出串列 (Print)
    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL" << std::endl;
    }

    // 記得要寫解構子 (Destructor) 來釋放動態配置的記憶體，防止記憶體洩漏
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current; // 釋放當前節點的記憶體
            current = nextNode;
        }
    }
};
```

-----

## 四、 鏈結串列的變體 (Variations of Linked Lists)

除了基本的**單向鏈結串列 (Singly Linked List)**，還有其他兩種常見的變體：

1.  **雙向鏈結串列 (Doubly Linked List)**：

      * 每個節點除了指向**下一個 (Next)** 節點的指標外，還包含一個指向**前一個 (Previous)** 節點的指標。
      * 優點：可以進行**雙向導航**，從尾部或中間節點往回遍歷。
      * 缺點：需要額外的記憶體空間來儲存第二個指標，且插入/刪除操作需要更新兩個指標。

2.  **循環鏈結串列 (Circular Linked List)**：

      * 串列中的最後一個節點的指標不指向 `NULL`，而是指向**第一個節點 (Head)**。
      * 優點：可以從任何一個節點開始遍歷整個串列，且沒有明顯的頭尾區分。
      * 循環鏈結串列又可分為：**單向循環**和**雙向循環**。
