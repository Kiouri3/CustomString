# Custom String Implementation in C++

Полноценная реализация динамической строки на C++ с нуля, аналогичная `std::string`.

## 🚀 Особенности

- **Полное управление памятью** — динамический буфер, геометрическое расширение
- **Безопасность исключений** — strong exception guarantee
- **SSO-оптимизация** (опционально) — Small String Optimization
- **Полный набор операций** — конструкторы, операторы, модификаторы
- **100+ unit-тестов** на базе тестов МФТИ

## 📋 Реализованный функционал

✅ **Конструкторы:** по умолчанию, от C-string, от буфера, заполняющий, копирования  
✅ **Доступ:** `operator[]`, `at()`, `front()`, `back()`, `c_str()`, `data()`  
✅ **Модификаторы:** `push_back()`, `pop_back()`, `clear()`, `swap()`  
✅ **Управление памятью:** `reserve()`, `resize()`, `shrink_to_fit()`  
✅ **Конкатенация:** `operator+`, `operator+=`  
✅ **Сравнение:** все операторы сравнения (`==`, `!=`, `<`, `<=`, `>`, `>=`)   

## 🛠 Сборка и тестирование

### Требования
- CMake 3.15+
- Компилятор C++17 (GCC 9+, Clang 10+, MSVC 2019+)

### Linux / macOS
```bash
git clone https://github.com/Kiouri3/CustomString-CPP.git
cd CustomString-CPP
mkdir build && cd build
cmake .. -G Ninja -DCMAKE_BUILD_TYPE=Release
ninja
ninja test
