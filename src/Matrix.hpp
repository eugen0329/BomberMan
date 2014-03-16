#ifndef _MATRIX_HPP_
#define _MATRIX_HPP_

#include <vector>
using namespace std;

template<class T> 
class Matrix {
private:
    std::vector<T>* elements; 
    size_t xSize;
    size_t ySize; 
public:
    Matrix(const Matrix<T>&);
    Matrix(size_t, size_t);
    ~Matrix();

    Matrix<T>& operator = (const Matrix<T>&);
    std::vector<T>& operator [] (size_t);
    const std::vector<T>& operator [] (size_t) const;
};

template<class T>
Matrix<T>::Matrix(size_t x, size_t y) 
{
    xSize = x;
    ySize = y;

    elements = new std::vector<T> [this->ySize];
    for (int i = 0; i < this->ySize; i++) {
        elements[i].resize(this->xSize);
    }
}

template<class T>
Matrix<T>::Matrix(const Matrix<T>& second)
{

    this->xSize = second.xSize;
    this->ySize = second.ySize;

    elements = new std::vector<T> [this->ySize];
    for (int i = 0; i < this->ySize; i++) {
        elements[i] = second[i];
    }
}

template<class T>
Matrix<T>& Matrix<T>::operator = (const Matrix<T>& second) 
{
    this->xSize = second.xSize;
    this->ySize = second.ySize;

    elements = new std::vector<T> [this->ySize];
    for (int i = 0; i < this->ySize; i++) {
        elements[i] = second[i];
    }
    
    return *this;
}

template<class T>
Matrix<T>::~Matrix()
{
    if(elements) {
        delete [] elements;
    }
}

template<class T>
const std::vector<T>& Matrix<T>::operator [] (size_t index) const
{
    return elements[index];
}

template<class T>
std::vector<T>& Matrix<T>::operator [] (size_t index)
{
    return elements[index];
}

#endif /* end of include guard: _MATRIX_HPP_ */
