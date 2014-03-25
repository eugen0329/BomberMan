#ifndef _MATRIX_HPP_
#define _MATRIX_HPP_

#include <vector>
#include <iostream>

template<class T> 
class Matrix {
private:
    T** matrix;
    size_t xSize;
    size_t ySize; 
public:
    //Matrix(const Matrix<T>&);
    Matrix(size_t xSize = 0, size_t ySize = 0);
    ~Matrix();

    void setSize(size_t, size_t);
    const size_t getXSize() const;
    const size_t getYSize() const;

    T*& operator [] (size_t);
    const T*& operator [] (size_t) const;
};

template<class T>
const size_t Matrix<T>::getXSize() const 
{
    return xSize;
}

template<class T>
const size_t Matrix<T>::getYSize() const 
{
    return ySize;
}    

template<class T>
Matrix<T>::Matrix(size_t x, size_t y) 
{
    xSize = x;
    ySize = y;

    matrix = new T* [ySize];
    for (int i = 0; i < this->ySize; i++) {
        matrix[i] = new T [xSize];
    }
}

template<class T>
void Matrix<T>::setSize(size_t x, size_t y) 
{
    for (int i = 0; i < this->ySize; i++) {
        delete [] matrix[i];
    }
    delete matrix;

    xSize = x;
    ySize = y;

    matrix = new T* [ySize];
    for (int i = 0; i < this->ySize; i++) {
        matrix[i] = new T [xSize];
    }

}

template<class T>
Matrix<T>::~Matrix()
{
    for (int i = 0; i < this->ySize; i++) {
        delete [] matrix[i];
    }
    delete matrix;
}

template<class T>
const T*& Matrix<T>::operator [] (size_t index) const
{
    return matrix[index];
}

template<class T>
T*& Matrix<T>::operator [] (size_t index)
{
    return matrix[index];
}

//template<class T>
//Matrix<T>::Matrix(const Matrix<T>& second)
//{
//}
//
//template<class T>
//Matrix<T>& Matrix<T>::operator = (const Matrix<T>& second) 
//{
//    return *this;
//}

#endif /* end of include guard: _MATRIX_HPP_ */
