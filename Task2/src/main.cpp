#include <iostream>

class smart_array{
public:
    smart_array(const smart_array &other) = delete;

    smart_array(int size):_size(size){
        _real_size = 2 * _size;
        _arr = new int[_real_size]{0};
    }
    
    void add_element(int elem){
        if (_count < _size){
            _arr[_count] = elem;
            ++_count;
        }else if (_count == _size){
            _arr[_count] = elem;
            ++_size;
            ++_count;
            if (_size == _real_size) resize_array();
        }
    }

    int get_element(int num_elem){
        if (num_elem >= _size){
            std::cout << "Wrong element number";
            return -1;
        }
        return _arr[num_elem];
    }

    smart_array &operator= (const smart_array &other){
        this->_size = other._size;
        this->_real_size = other._real_size;
        this->_count = other._count;
        this->_arr = new int[_real_size];
        for (int i = 0; i < _size; ++i){
            this->_arr[i] = other._arr[i];
        }
        return *this;
    }

    ~smart_array(){
        delete [] _arr;
    }

private:
    int _size;
    int _real_size;
    int *_arr = nullptr;
    int _count = 0;
    void resize_array(){
        int *tmp_arr = new int[_size];
        for (int i=0; i<_size; ++i){
            tmp_arr[i] = _arr[i];
        }
        _real_size *= 2;
        _arr = new int[_real_size]{0};
        for (int i=0; i<_size; ++i){
            _arr[i] = tmp_arr[i];
        }
        delete [] tmp_arr;
    }
};

int main(){
    
    try {
        smart_array arr(5);
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);

        smart_array new_array(2);
        new_array.add_element(44); 
        new_array.add_element(34);

        arr = new_array;
        std::cout << arr.get_element(1) << std::endl;
    }
    catch (const std::exception& ex) {
	    std::cout << ex.what() << std::endl;
    }

    return 0;
}