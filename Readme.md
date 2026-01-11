# C/C++ Practice

C/C++ 語法學習與演算法練習專案

## 📁 專案結構

```
C_C++_Partice/
├── Basic_Syntax/        # C++ 基礎語法範例
├── Interview/           # 面試題實作
├── LeetCode/           # LeetCode 題目解答
└── Readme.md
```

## 📚 內容說明

### Basic_Syntax（基礎語法）
學習 C++ 基礎語法與標準庫使用，包含資料結構（Vector、Linklist、Stack、Queue、Hash）和基本語法（指標、控制語句、輸出等）的實作範例。

### Interview（面試題）
常見的程式面試題目實作與練習。

### LeetCode（題目解答）
LeetCode 平台的演算法題目解答與實作。

## 🔧 編譯與執行

### 使用 g++ 編譯 C++ 程式

```bash
# 基本編譯
g++ -std=c++11 FileName.cpp -o FileName

# 執行
./FileName
```

### 編譯器選擇
- **C 程式**：使用 `gcc`
- **C++ 程式**：使用 `g++`（會自動連結 C++ 標準庫）

### 常用編譯參數
```bash
# 開啟警告訊息
g++ -std=c++11 -Wall FileName.cpp -o FileName

# 除錯模式
g++ -std=c++11 -g FileName.cpp -o FileName

# 優化編譯
g++ -std=c++11 -O2 FileName.cpp -o FileName
```

## 📝 注意事項

- 所有程式碼使用 C++11 標準
- 編譯 C++ 檔案請使用 `g++` 而非 `gcc`
- 若使用 `gcc` 編譯 C++ 需加上 `-lstdc++` 參數