#ifndef CPPSTRING_H
#define CPPSTRING_H

#include <stdexcept>
#include <iostream>

class StringOutOfRange : public std::runtime_error {
  public:
   StringOutOfRange() : std::runtime_error("StringOutOfRange") {
   }
 };

size_t Strlen(const char* str);
template<typename T>
void Swap(T& a, T& b);

class String {
 public:
  // Конструкторы
  String();
  String(const char* str);  // NOLINT
  String(const char* str, size_t size);
  String(size_t size, char symbol);

  // Правило трех
  ~String();
  String(const String& other);
  String& operator=(const String& other);

  // Оператор [] и методы доступа
  char& operator[](size_t index);
  const char& operator[](size_t index) const;
  char& At(size_t index);
  const char& At(size_t index) const;
  char& Front();
  const char& Front() const;
  char& Back();
  const char& Back() const;

  // Указатели на 1 элемент
  const char* CStr() const;
  char* CStr();
  const char* Data() const;

  // Размер строки
  bool Empty() const;
  size_t Size() const;
  size_t Length() const;
  size_t Capacity() const;

  // Прочие методы
  void Clear();
  void Swap(String& other);
  void PopBack();
  void PushBack(const char symbol);

  // Управление памятью
  void ShrinkToFit();
  void Resize(size_t new_size, const char symbol);
  void Reserve(size_t new_capacity);

  String& operator+=(const String& other);


 private:
  size_t size_;
  size_t capacity_;
  char* data_;

  // Перераспределение памяти(е/и новой капасити)
  void Reallocate(size_t new_capacity);

};

String operator+(const String& left, const String& right);

// Операции сравнения
bool operator==(const String& left, const String& right);
bool operator!=(const String& left, const String& right);
bool operator<(const String& left, const String& right);
bool operator<=(const String& left, const String& right);
bool operator>(const String& left, const String& right);
bool operator>=(const String& left, const String& right);

// Оператор вывода из потока
std::ostream& operator<<(std::ostream& os, const String& str);

#endif