#ifndef INHERITANCE_MYSET_H
#define INHERITANCE_MYSET_H

#include <iostream>
#include <cstring>
#include "myvector.hpp"

template<class T>
class MySet : public MyVector<T> {
public:
    MySet(T el = NULL);

    bool operator==(const MySet<T>& s) const;

    MySet<T>& operator+=(const MySet<T>& s);
    MySet<T>& operator-=(const MySet<T>& s);
    MySet<T>& operator*=(const MySet<T>& s);

    void add_element(T el);
    void delete_element(T el);
    bool is_element(T el) const;

    int q_find(T el) const;

    template <typename Z>
    friend std::ostream& operator<<(std::ostream& out, const MySet<Z>& s);

    template <typename Z>
    friend MySet<Z> operator+(const MySet<Z>& s1, const MySet<Z>& s2);

    template <typename Z>
    friend MySet<Z> operator-(const MySet<Z>& s1, const MySet<Z>& s2);

    template <typename Z>
    friend MySet<Z> operator*(const MySet<Z>& s1, const MySet<Z>& s2);
};

template<class T>
MySet<T>::MySet(T el) : MyVector<T>(el) {}

template<class T>
bool MySet<T>::operator==(const MySet<T>& s) const {
    if (this->size != s.size) return false;
    for (int i = 0; i < this->size; ++i) {
        if (!s.is_element((*this)[i])) return false;
    }
    return true;
}

template<class T>
MySet<T>& MySet<T>::operator+=(const MySet<T>& s) {
    for (int i = 0; i < s.size; ++i) {
        this->add_element(s[i]);
    }
    return *this;
}

template<class T>
MySet<T>& MySet<T>::operator-=(const MySet<T>& s) {
    for (int i = 0; i < s.size; ++i) {
        this->delete_element(s[i]);
    }
    return *this;
}

template<class T>
MySet<T>& MySet<T>::operator*=(const MySet<T>& s) {
    for (int i = 0; i < this->size;) {
        if (!s.is_element((*this)[i])) {
            this->delete_element((*this)[i]);
        } else {
            ++i;
        }
    }
    return *this;
}

template<class T>
void MySet<T>::add_element(T el) {
    if (!this->is_element(el)) {
        MyVector<T>::add_element(el);
        this->sort();
    }
}

template<class T>
void MySet<T>::delete_element(T el) {
    int index = this->q_find(el);
    if (index != -1) {
        MyVector<T>::delete_element(index);
    }
}

template<class T>
bool MySet<T>::is_element(T el) const {
    return q_find(el) != -1;
}

template<class T>
int MySet<T>::q_find(T el) const {
    int left = 0, right = this->size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (this->pdata[mid] == el) return mid;
        else if (this->pdata[mid] < el) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

template<>
int MySet<const char*>::q_find(const char* el) const {
    int left = 0, right = this->size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int cmp = strcmp(this->pdata[mid], el);
        if (cmp == 0) return mid;
        else if (cmp < 0) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

template<class Z>
std::ostream& operator<<(std::ostream& out, const MySet<Z>& s) {
    out << "[";
    for (int i = 0; i < s.size; ++i) {
        if (i > 0) out << ", ";
        out << s[i];
    }
    out << "]";
    return out;
}

template<class Z>
MySet<Z> operator+(const MySet<Z>& s1, const MySet<Z>& s2) {
    MySet<Z> result = s1;
    result += s2;
    return result;
}

template<class Z>
MySet<Z> operator-(const MySet<Z>& s1, const MySet<Z>& s2) {
    MySet<Z> result = s1;
    result -= s2;
    return result;
}

template<class Z>
MySet<Z> operator*(const MySet<Z>& s1, const MySet<Z>& s2) {
    MySet<Z> result = s1;
    result *= s2;
    return result;
}

#endif // INHERITANCE_MYSET_H
