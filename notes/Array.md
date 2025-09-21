# Array
---
## 1.基本概念 (Array Basics)

- ** 陣列 (array) : **連續記憶體位置中的元素集合  
- ** 特性 : **
  - 固定大小 (Fixed size)  
  - 隨機存取 (Random access)，透過索引 (index) 可直接存取，時間複雜度 O(1)  
  - 元素型別一致 (Same data type)，利於效率與儲存  
---
## 2.陣列維度 (Dimensions)

- ** 一維陣列 (1D array)**
  ```c
  int array[5] = {10, 20, 30, 40, 50};
  printf("%d", array[2]); // 輸出 30
  ```
- ** 二維陣列 (2D array)**
  ```c
  int array2d[3][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12}
  };
  printf("%d", array2d[1][2]); // 輸出 7
  ```
