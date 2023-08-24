#include <iostream>

class smart_array{
public:
    smart_array(const smart_array&) = delete;
    smart_array(int size):real_size_(size){
        arr_ = new int[real_size_]{0};
    }

    
    void add_element(int elem){
        if (count_ < real_size_){
            arr_[count_] = elem;
            ++count_;
        }else{
            resize_array();
            arr_[count_] = elem;
            ++count_;
        }
    }

    int get_element(int num_elem){
        using namespace std::literals;
        if (num_elem >= count_ || num_elem < 0){
            throw(std::out_of_range("Error: wrong element number"s));
        }
        return arr_[num_elem];
    }

    smart_array &operator= (const smart_array &other){
        if (this != &other){
            this->real_size_ = other.real_size_;
            this->count_ = other.count_;
            delete [] arr_;
            this->arr_ = new int[real_size_];
            for (int i = 0; i <= count_; ++i){
                this->arr_[i] = other.arr_[i];
            }
        }
        return *this;
    }

    ~smart_array(){
        delete [] arr_;
    }

private:
    int real_size_;
    int *arr_ = nullptr;
    int count_ = 0;
    void resize_array(){
        int *tmp_arr = new int[count_];
        for (int i=0; i < real_size_; ++i){
            tmp_arr[i] = arr_[i];
        }
        real_size_ *= 2;
        delete [] arr_;
        arr_ = new int[real_size_]{0};
        for (int i=0; i < count_; ++i){
            arr_[i] = tmp_arr[i];
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

        arr = arr;
        std::cout << arr.get_element(1) << std::endl;
        
        arr = new_array;
        std::cout << arr.get_element(1) << std::endl;
    }
    catch (const std::exception& ex) {
	    std::cout << ex.what() << std::endl;
    }

    return 0;
}