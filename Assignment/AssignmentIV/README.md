# Homework Assignment IV: Hash Function Design & Observation (C/C++ Version)

This assignment focuses on the design and observation of hash functions using C/C++. 
Students are expected to implement and analyze the behavior of hash functions, 
evaluate their efficiency, and understand their applications in computer science.

Developer: Ping-Li,Tien
Email: billytne0208@gmail.com

## My Hash Function
### Integer Keys 
- Formula / pseudocode:
  ```text
    long long int h;
	h = key * 99999839// a large prime number
		+ 1234567; // an arbitrary c
    if (h < 0)h = -h;// ensure non-negative
	key = static_cast<int>(h);
    return key % m;  // basic division method
  ```
- Rationale:    
  1.乘以大質數 : 打破 key 與 hash table 大小 m 的整除規律，避免像 21, 31, 41 這種鍵值落在同一個槽位。  
  2.加上偏移常數 : 增加額外變化，讓不同 key 的結果更不容易出現相同索引。  
  3.取絕對值 : 保證散列結果為非負，避免負數 modulo 導致索引錯誤。  

### Non-integer Keys
- Formula / pseudocode:
  ```text
  unsigned long hash = 0
  // 將每個字元累加，乘以質數，形成散列值
	for (char ch : str) {
	hash = hash * 31 + static_cast<unsigned long>(ch); // a common choice is 31
	}
	hash = hash * 99999839 + 1234567; // a large prime number and an arbitrary c
	if (hash < 0) hash = (-1)*hash; // ensure non-negative
	return static_cast<int>(hash % m);  // basic division method
  ```
- Rationale:   
  1.字元累加與基數乘法：將每個字元都納入計算，並乘以常用基數 31，使字串中即使只有一個字元不同，也會產生不同的 hash 值，避免順序相似的字串落在同一槽位。  
  2.乘以大質數並加上偏移常數：乘以大質數 99999839 並加上 1234567，打破與 hash table 大小 m 的整除規律，增加散列結果的變化，使不同字串更不容易出現相同索引。  
  3.取絕對值：保證散列結果為非負，避免因整數溢出或負數 modulo 導致索引錯誤。  

## Experimental Setup
- Table sizes tested (m): 10, 11, 37
- Test dataset:
  - Integers: 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60
  - Strings: "cat", "dog", "bat", "cow", "ant", "owl", "bee", "hen", "pig", "fox"
- Compiler: GCC and G++
- Standard: C23 and C++23

## Results
| Table Size (m) | Index Sequence         | Observation              |
|----------------|------------------------|--------------------------|
| 10             | 1, 2, 3, 4, ...        | Pattern repeats every 10 |
| 11             | 10, 0, 1, 2, ...       | More uniform             |
| 37             | 20, 21, 22, 23, ...    | Near-uniform             |

## Compilation, Build, Execution, and Output

### Compilation
- The project uses a comprehensive Makefile that builds both C and C++ versions with proper flags:
  ```bash
  # Build both C and C++ versions
  make all
  
  # Build only C version
  make c
  
  # Build only C++ version
  make cxx
  ```

### Manual Compilation (if needed)
- Command for C:
  ```bash
  gcc -std=c23 -Wall -Wextra -Wpedantic -g -o C/hash_function C/main.c C/hash_fn.c
  ```
- Command for C++:
  ```bash
  g++ -std=c++23 -Wall -Wextra -Wpedantic -g -o CXX/hash_function_cpp CXX/main.cpp CXX/hash_fn.cpp
  ```

### Clean Build Files
- Remove all compiled files:
  ```bash
  make clean
  ```

### Execution
- Run the compiled binary:
  ```bash
  ./hash_function
  ```
  or
  ```bash
  ./hash_function_cpp
  ```

### Result Snapshot
- Example output for integers:
  ```
  === Hash Function Observation (C Version) ===

  === Table Size m = 10 ===
  Key     Index
  -----------------
  21      1
  22      2
  ...

  === Table Size m = 11 ===
  Key     Index
  -----------------
  21      10
  22      0
  ...

  === Table Size m = 37 ===
  Key     Index
  -----------------
  21      21
  22      22
  ...

  === Hash Function Observation (C++ Version) ===

  === Table Size m = 10 ===
  Key     Index
  -----------------
  21      1
  22      2
  ...

  === Table Size m = 11 ===
  Key     Index
  -----------------
  21      10
  22      0
  ...

  === Table Size m = 37 ===
  Key     Index
  -----------------
  21      21
  22      22
  ...
  ```

- Example output for strings:
  ```
  === String Hash (m = 10) ===
  Key     Index
  -----------------
  cat     0
  dog     0
  ...

  === String Hash (m = 11) ===
  Key     Index
  -----------------
  cat     0
  dog     0
  ...

  === String Hash (m = 37) ===
  Key     Index
  -----------------
  cat     0
  dog     0
  ...
  ```

- Observations: Outputs align with the analysis, showing better distribution with prime table sizes.
- Example output for integers:
  ```
  Hash table (m=10): [1, 2, 3, 4, 5, 6, 7, 8, 9, 0]
  Hash table (m=11): [10, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
  Hash table (m=37): [20, 21, 22, 23, 24, 25, 26, 27, 28, 29, ...]
  ```
- Example output for strings:
  ```
  Hash table (m=10): ["cat", "dog", "bat", "cow", "ant", ...]
  Hash table (m=11): ["fox", "cat", "dog", "bat", "cow", ...]
  Hash table (m=37): ["bee", "hen", "pig", "fox", "cat", ...]
  ```
- Observations: Outputs align with the analysis, showing better distribution with prime table sizes.

## Analysis
- Prime vs non-prime `m`: Prime table sizes generally result in better distribution and fewer collisions.
- Patterns or collisions: Non-prime table sizes tend to produce repetitive patterns, leading to more collisions.
- Improvements: Use a prime table size and a well-designed hash function to enhance distribution.

## Reflection
1. Designing hash functions requires balancing simplicity and effectiveness to minimize collisions.
2. Table size significantly impacts the uniformity of the hash distribution, with prime sizes performing better.
3. The design using a prime table size and a linear transformation formula produced the most uniform index sequence.
