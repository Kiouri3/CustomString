#include "cppstring.h"

size_t Strlen(const char* str) {
  size_t size = 0;
  while (str[size]) {
    ++size;
  }
  return size;
}

template<typename T>
void Swaps(T& a, T& b) {
  T c = a;
  a = b;
  b = c;
}

// Конструкторы
String::String() : size_(0), capacity_(0), data_(nullptr) {}
String::String(const char* str) : size_(Strlen(str)) {
  if (size_ == 0) {
    capacity_ = 0;
    data_ = nullptr;
  } else {
    capacity_ = size_;
    data_ = new char[capacity_];
    for (size_t i = 0; i < size_; ++i) {
      data_[i] = str[i];
    }
  }
}
String::String(const char* str, size_t size) : size_(size) {
  if (size_ == 0) {
    capacity_ = 0;
    data_ = nullptr;
  } else {
    capacity_ = size_;
    data_ = new char[capacity_];
    for (size_t i = 0; i < size_; ++i) {
      data_[i] = str[i];
    }
  }
}
String::String(size_t size, char symbol) : size_(size) {
  if (size_ == 0) {
    capacity_ = 0;
    data_ = nullptr;
  } else {
    capacity_ = size_;
    data_ = new char[capacity_];
    for (size_t i = 0; i < size_; ++i) {
      data_[i] = symbol;
    }
  }
}

// Правило трех
String::~String() {
  delete[] data_;
};
String::String(const String& other) : size_(other.size_) {
  if (size_ == 0) {
    capacity_ = 0;
    data_ = nullptr;
  } else {
    capacity_ = other.capacity_;
    data_ = new char[capacity_];
    for (size_t i = 0; i < size_; ++i) {
      data_[i] = other[i];
    }
  }
}
String& String::operator=(const String& other) {
  if (this != &other) {
    delete[] data_;
    size_ = other.size_;
    capacity_ = other.capacity_;
    if (size_ == 0) {
      data_ = nullptr;
    } else {
      data_ = new char[capacity_];
      for (size_t i = 0; i < size_; ++i) {
        data_[i] = other[i];
      }
    }
  }
  return *this;
}

// Оператор [] и методы доступа
char& String::operator[](size_t index) {
  return data_[index];
}
const char& String::operator[](size_t index) const {
  return data_[index];
}
char& String::At(size_t index) {
  if (index >= size_) {
    throw StringOutOfRange{};
  }
  return data_[index];
}
const char& String::At(size_t index) const { {
  if (index >= size_) {
    throw StringOutOfRange{};
  }
}
  return data_[index];
}
char& String::Front() {
  return data_[0];
}
const char& String::Front() const {
  return data_[0];
}
char& String::Back() {
  return data_[size_ - 1];
}
const char& String::Back() const {
  return data_[size_ - 1];
}

// Указатели на 1 элемент
char* String::CStr() {
  if (size_ == capacity_) {
    char* new_data = new char[capacity_ + 1];
    for (size_t i = 0; i < size_; ++i) {
      new_data[i] = data_[i];
    }
    delete[] data_;
    data_ = new_data;
  }
  data_[size_] = '\0';
  return data_;
}
const char* String::CStr() const {
  return data_;
}
const char* String::Data() const {
  return data_;
}

// Размер строки
bool String::Empty() const {
  return size_ == 0;
}
size_t String::Size() const {
  return size_;
}
size_t String::Length() const {
  return size_;
}
size_t String::Capacity() const {
  return capacity_;
}

// Прочие методы
void String::Clear() {
  size_ = 0;
}
void String::Swap(String& other) {
  Swaps(size_, other.size_);
  Swaps(capacity_, other.capacity_);
  Swaps(data_, other.data_);
}
void String::PopBack() {
  if (size_) {
    --size_;
  }
}
void String::PushBack(const char symbol) {
  if (size_ == capacity_) {
    Reallocate(capacity_ == 0 ? 1 : capacity_ * 2);
  }
  size_++;
  data_[size_ - 1] = symbol;
}

// Управление памятью
void String::ShrinkToFit() {
  if (capacity_ > size_) {
    Reallocate(size_);
  }
}
void String::Resize(size_t new_size, const char symbol) {
  if (capacity_ < new_size) {
    Reallocate(new_size);
  }
  if (new_size > size_) {
    for (size_t i = size_; i < new_size; ++i) {
      data_[i] = symbol;
    }
  }
  size_ = new_size;
}
void String::Reserve(size_t new_capacity) {
  if (new_capacity > capacity_) {
    Reallocate(new_capacity);
  }
}

// Если новый капасити
void String::Reallocate(size_t new_capacity) {
  char* new_data = new char[new_capacity];
  for (size_t i = 0; i < size_; ++i) {
    new_data[i] = data_[i];
  }
  delete[] data_;
  data_ = new_data;
  capacity_ = new_capacity;
}

String& String::operator+=(const String& other) {
  if (size_ + other.size_ > capacity_) {
    Reallocate((size_ + other.size_) * 2);
  }

  for (size_t i = 0; i < other.size_; ++i) {
    data_[size_ + i] = other.data_[i];
  }
  size_ += other.size_;
  return *this;
}

String operator+(const String& left, const String& right) {
  String result(left);
  result += right;
  return result;
}

// Операции сравнения
bool operator==(const String& left, const String& right) {
  if (left.Size() != right.Size()) {
    return false;
  }
  for (size_t i = 0; i < left.Size(); ++i) {
    if (left[i] != right[i]) {
      return false;
    }
  }
  return true;
}
bool operator!=(const String& left, const String& right) {
  return !(left == right);
}
bool operator<(const String& left, const String& right) {
  size_t min_size = 0;
  if (left.Size() > right.Size()) {
    min_size = right.Size();
  } else {
    min_size = left.Size();
  }

  for (size_t i = 0; i < min_size; ++i) {
    if (left[i] < right[i]) {
      return true;
    }
    if (left[i] > right[i]) {
      return false;
    }
  }
  return left.Size() < right.Size();
}
bool operator<=(const String& left, const String& right) {
  return left == right || left < right;
}
bool operator>(const String& left, const String& right) {
  return !(left <= right);
}
bool operator>=(const String& left, const String& right) {
  return !(left < right);
}

// Оператор вывода из потока
std::ostream& operator<<(std::ostream& os, const String& str) {
  for (size_t i = 0; i < str.Size(); ++i) {
    os.put(str[i]);
  }
  return os;
}