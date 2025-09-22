# Array
---
## 1.基本概念 (Array Basics)

- **陣列 (array) :** 連續記憶體位置中的元素集合  
- **特性 :**
  - 固定大小 (Fixed size)  
  - 隨機存取 (Random access)，透過索引 (index) 可直接存取，時間複雜度 O(1)  
  - 元素型別一致 (Same data type)，利於效率與儲存  
---
## 2.陣列維度 (Dimensions)

- **一維陣列 (1D array)**
  ```c
  int array[5] = {10, 20, 30, 40, 50};
  printf("%d", array[2]); // 輸出 30
  ```
- **二維陣列 (2D array)**
  ```c
  int array2d[3][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12}
  };
  printf("%d", array2d[1][2]); // 輸出 7
  ```
- **三維陣列 (3D array)**
  ```c
  int array3d[2][3][4] = {
    {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}},
    {{13, 14, 15, 16}, {17, 18, 19, 20}, {21, 22, 23, 24}}
  };
  printf("%d", array3d[1][2][3]); // 輸出 24
  ```
---
## 3. 陣列 ADT (Abstract Data Type)

- 定義：一組索引 (index) 與值 (value) 的對應。
- 基本操作：
  A-array,i-index,x-value
  - `Create(n)` : 建立長度為 n 的陣列。
  - `Retrieve(A, i)` : 取得索引 i 的元素。
  - `Store(A, i, x)` ：在索引 i 儲存值 x。
  - `Insert/Delete`：需位移其他元素，效率低。
  - `Resize`：動態陣列才可調整大小。
 
---
## 4. 靜態與動態陣列

- 靜態陣列 (Static array)：大小在編譯期決定，無法改變。
- 動態陣列 (Dynamic array)：大小可於執行期 (runtime) 變動，需使用 `malloc` / `realloc` / `free`。
```c
int *array;
int n = 10;
array = (int*) malloc(n * sizeof(int));
free(array);
```
---
## 5. 排序 (Sorting)

- 目標：將陣列由小到大排序。
- 方法：
  1. Bubble Sort (氣泡排序)：反覆交換相鄰錯序元素。O(n²)
  2. Selection Sort (選擇排序)：每回合選最小值，放到前面。O(n²)
  3. Insertion Sort (插入排序)：將元素插入到已排序區域。O(n²)
---

## 6. 優缺點 (Pros & Cons)
- 優點：
  - 快速隨機存取 (O(1))。
  - 適合靜態資料。
- 缺點：
  - 插入 / 刪除成本高 (需位移大量元素)。
  - 動態擴充需重新配置記憶體。

---

## 7. 陣列型別


















