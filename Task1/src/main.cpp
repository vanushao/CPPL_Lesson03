#include <iostream>
#include <exception>



class smart_array{
public:
    smart_array(int size):real_size_(size){
        arr_ = new int[real_size_]{0};
    }

    smart_array(const smart_array&) = delete;
    smart_array& operator=(const smart_array&) = delete;
    
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
	smart_array arr(1);
	arr.add_element(1);
	arr.add_element(4);
	arr.add_element(155);
	arr.add_element(14);
	arr.add_element(15);
    std::cout << arr.get_element(0) << std::endl;
    std::cout << arr.get_element(4) << std::endl;
    std::cout << arr.get_element(6) << std::endl;
    }
    catch (const std::exception& ex) {
	    std::cout << ex.what() << std::endl;
    }

    return 0;
}