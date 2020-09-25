#ifndef _ARRATY_LIST_H
#define _ARRATY_LIST_H

template<typename T>
struct ArrayList;

typedef unsigned int uint;
#define CHECK_POS_OVER_SIZE(pos) do{if(pos >= _size) exit(1);}while(0);

template<typename T>
struct ArrayList
{
    ArrayList();
    ArrayList(uint);
    ArrayList(const ArrayList&);
    virtual ~ArrayList();

    bool empty() const;
    uint size() const;
    uint capacity() const;
    void destroy();
    void insert(uint, const T&);
    const T& remove(uint);
    const T& operator[](uint) const;

    private:
    void extendCapacity();
    void moveAfterPos(uint);
    void moveBeforePos(uint);

    private:
    T *_data;
    uint _size;
    uint _capacity;
};

template<typename T>
inline ArrayList<T>::ArrayList()
{
    _size = 0;
    _capacity = 50;
    _data = (T*)malloc(_capacity * sizeof(T));
    if(!_data) exit(1);
}

template<typename T>
inline ArrayList<T>::ArrayList(uint capacity)
{
    _size = 0;
    _capacity = capacity;
    _data = (T*)malloc(_capacity * sizeof(T));
    if(!_data) exit(1);
}

template<typename T>
inline ArrayList<T>::ArrayList(const ArrayList &rhs)
{
    _size = rhs._size;
    _capacity = rhs._capacity;
    memcpy(_data, rhs._data, rhs._capacity * sizeof(T));
}

template<typename T>
inline ArrayList<T>::~ArrayList()
{
    destroy();
}

template<typename T>
inline bool ArrayList<T>::empty() const
{
    return (0 == _size);
}

template<typename T>
inline uint ArrayList<T>::size() const
{
    return _size;
}

template<typename T>
inline uint ArrayList<T>::capacity() const
{
    return _capacity;
}

template<typename T>
inline void ArrayList<T>::destroy()
{
    if(_data) free(_data);
    _data = 0;
    _size = 0;
    _capacity = 0;
}

template<typename T>
void ArrayList<T>::insert(uint pos, const T& value)
{
    if(_size >= _capacity)
    {
        extendCapacity();
    }
    if(pos < _size)
    {
        moveAfterPos(pos);
    }
    _data[pos] = value;
    _size++;
}

template<typename T>
void ArrayList<T>::extendCapacity()
{
    T *temp = _data;
    uint newCapacity = _capacity + _capacity/2;

    _data = (T*)malloc(newCapacity * sizeof(T));
    if(!_data) exit(1);
    memcpy(_data, temp, _capacity * sizeof(T));
    _capacity = newCapacity;
    free(temp);
}

template<typename T>
void ArrayList<T>::moveAfterPos(uint pos)
{
    if(pos >= _size) return;
    for(uint i = _size; i > pos; i--)
    {
        _data[i] = _data[i-1];
    }
}

template<typename T>
void ArrayList<T>::moveBeforePos(uint pos)
{
    CHECK_POS_OVER_SIZE(pos);
    for(uint i = pos; i < _size-1; i++)
    {
        _data[i] = _data[i+1];
    }
}

template<typename T>
const T& ArrayList<T>::remove(uint pos)
{
    CHECK_POS_OVER_SIZE(pos);
    T &temp = _data[pos];
    moveBeforePos(pos);
    _size--;
    return temp;
}

template<typename T>
const T& ArrayList<T>::operator[](uint pos) const
{
    CHECK_POS_OVER_SIZE(pos);
    return _data[pos];
}

#endif