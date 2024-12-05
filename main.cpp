#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>

template<typename T>
void Bubble_sort(T a[], int maxn) {
    for(int i = 0; i < maxn; i++) {
        for(int j = 0; j < maxn - i - 1; j++) {
            if(a[j] > a[j + 1]) {
                T temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

template<typename T>
void Bubble_sort_pointer(T* a, int maxn) {
    for(int i = 0; i < maxn; i++) {
        for(int j = 0; j < maxn - i - 1; j++) {
            if(*(a + j) > *(a + j + 1)) {
                T temp = *(a + j);
                *(a + j) = *(a + j + 1);
                *(a + j + 1) = temp;
            }
        }
    }
}

template<typename T>
void Bubble_sort_vector(std::vector<T>& vec) {
    int maxn = vec.size();
    for(int i = 0; i < maxn; i++) {
        for(int j = 0; j < maxn - i - 1; j++) {
            if(vec[j] > vec[j + 1]) {
                std::swap(vec[j], vec[j + 1]);
            }
        }
    }
}

template<typename T>
void Tab_create(T a[], int maxn) {
    for(int i = 0; i < maxn; i++) {
        a[i] = maxn - i;
    }
}

template<>
void Tab_create(float a[], int maxn) {
    for(int i = 0; i < maxn; i++) {
        a[i] = std::sqrt(maxn - i);
    }
}

template<typename T>
std::vector<T> Tab_create_vector(int maxn) {
    std::vector<T> vec(maxn);
    for(int i = 0; i < maxn; i++) {
        vec[i] = maxn - i;
    }
    return vec;
}

template<>
std::vector<float> Tab_create_vector(int maxn) {
    std::vector<float> vec(maxn);
    for(int i = 0; i < maxn; i++) {
        vec[i] = std::sqrt(maxn - i);
    }
    return vec;
}

template<typename T>
void backup(T a[], T b[], int maxn) {
    for(int i = 0; i < maxn; i++) {
        b[i] = a[i];
    }
}

template<typename T>
bool is_sorted(T a[], int maxn) {
    for(int i = 0; i < maxn - 1; i++) {
        if(a[i] > a[i + 1]) {
            return false;
        }
    }
    return true;
}

template<typename T>
bool is_sorted_vector(const std::vector<T>& vec) {
    for(size_t i = 0; i < vec.size() - 1; i++) {
        if(vec[i] > vec[i + 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    int sizes[] = {10000, 20000, 30000};
    std::cout << std::setw(20) << "Sort Type(INT)" << "|";
    for(int size : sizes) {
        std::cout << std::setw(15) << size << "|";
    }
    std::cout << std::endl;
    std::cout << std::string(20 + 16 * std::size(sizes), '-') << std::endl;

    std::cout << std::setw(20) << "Bubble_sort" << "|";
    for(int size : sizes) {
        int* array = new int[size];
        int* original_array = new int[size];

        Tab_create(array, size);
        backup(array, original_array, size);

        auto start = std::chrono::high_resolution_clock::now();
        Bubble_sort(array, size);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        std::cout << std::setw(15) << duration.count() << "s|";

        delete[] array;
        delete[] original_array;
    }
    std::cout << std::endl;

    std::cout << std::setw(20) << "Bubble_sort_pointer" << "|";
    for(int size : sizes) {
        int* array = new int[size];
        int* original_array = new int[size];

        Tab_create(array, size);
        backup(array, original_array, size);

        auto start = std::chrono::high_resolution_clock::now();
        Bubble_sort_pointer(array, size);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        std::cout << std::setw(15) << duration.count() << "s|";

        delete[] array;
        delete[] original_array;
    }
    std::cout << std::endl;

    std::cout << std::setw(20) << "Bubble_sort_vector" << "|";
    for(int size : sizes) {
        std::vector<int> vec = Tab_create_vector<int>(size);

        auto start = std::chrono::high_resolution_clock::now();
        Bubble_sort_vector(vec);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        std::cout << std::setw(15) << duration.count() << "s|";
    }
    std::cout << std::endl;

    std::cout << std::string(20 + 16 * std::size(sizes), '-') << std::endl;

    std::cout << std::setw(20) << "Sorted Correctly" << "|";
    for(int size : sizes) {
        int* array = new int[size];
        int* original_array = new int[size];

        Tab_create(array, size);
        backup(array, original_array, size);
        Bubble_sort(array, size);
        std::cout << std::setw(15) << (is_sorted(array, size) ? "Yes" : "No") << "|";

        delete[] array;
        delete[] original_array;
    }
    std::cout << std::endl;

    std::cout << std::setw(20) << "Sorted Correctly" << "|";
    for(int size : sizes) {
        int* array = new int[size];
        int* original_array = new int[size];

        Tab_create(array, size);
        backup(array, original_array, size);
        Bubble_sort_pointer(array, size);
        std::cout << std::setw(15) << (is_sorted(array, size) ? "Yes" : "No") << "|";

        delete[] array;
        delete[] original_array;
    }
    std::cout << std::endl;

    std::cout << std::setw(20) << "Sorted Correctly" << "|";
    for(int size : sizes) {
        std::vector<int> vec = Tab_create_vector<int>(size);
        Bubble_sort_vector(vec);
        std::cout << std::setw(15) << (is_sorted_vector(vec) ? "Yes" : "No") << "|";
    }
    std::cout << std::endl;

    // Float sorting table
    std::cout << std::setw(20) << "\n\n\n\n\n Sort Type (float)" << "|";
    for(int size : sizes) {
        std::cout << std::setw(15) << size << "|";
    }
    std::cout << std::endl;
    std::cout << std::string(20 + 16 * std::size(sizes), '-') << std::endl;

    std::cout << std::setw(20) << "Bubble_sort" << "|";
    for(int size : sizes) {
        float* array = new float[size];
        float* original_array = new float[size];

        Tab_create(array, size);
        backup(array, original_array, size);

        auto start = std::chrono::high_resolution_clock::now();
        Bubble_sort(array, size);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        std::cout << std::setw(15) << duration.count() << "s|";

        delete[] array;
        delete[] original_array;
    }
    std::cout << std::endl;

    std::cout << std::setw(20) << "Bubble_sort_pointer" << "|";
    for(int size : sizes) {
        float* array = new float[size];
        float* original_array = new float[size];

        Tab_create(array, size);
        backup(array, original_array, size);

        auto start = std::chrono::high_resolution_clock::now();
        Bubble_sort_pointer(array, size);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        std::cout << std::setw(15) << duration.count() << "s|";

        delete[] array;
        delete[] original_array;
    }
    std::cout << std::endl;

    std::cout << std::setw(20) << "Bubble_sort_vector" << "|";
    for(int size : sizes) {
        std::vector<float> vec = Tab_create_vector<float>(size);

        auto start = std::chrono::high_resolution_clock::now();
        Bubble_sort_vector(vec);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        std::cout << std::setw(15) << duration.count() << "s|";
    }
    std::cout << std::endl;

    std::cout << std::string(20 + 16 * std::size(sizes), '-') << std::endl;

    std::cout << std::setw(20) << "Sorted Correctly" << "|";
    for(int size : sizes) {
        float* array = new float[size];
        float* original_array = new float[size];

        Tab_create(array, size);
        backup(array, original_array, size);
        Bubble_sort(array, size);
        std::cout << std::setw(15) << (is_sorted(array, size) ? "Yes" : "No") << "|";

        delete[] array;
        delete[] original_array;
    }
    std::cout << std::endl;

    std::cout << std::setw(20) << "Sorted Correctly" << "|";
    for(int size : sizes) {
        float* array = new float[size];
        float* original_array = new float[size];

        Tab_create(array, size);
        backup(array, original_array, size);
        Bubble_sort_pointer(array, size);
        std::cout << std::setw(15) << (is_sorted(array, size) ? "Yes" : "No") << "|";

        delete[] array;
        delete[] original_array;
    }
    std::cout << std::endl;

    std::cout << std::setw(20) << "Sorted Correctly" << "|";
    for(int size : sizes) {
        std::vector<float> vec = Tab_create_vector<float>(size);
        Bubble_sort_vector(vec);
        std::cout << std::setw(15) << (is_sorted_vector(vec) ? "Yes" : "No") << "|";
    }
    std::cout << std::endl;

    return 0;
}