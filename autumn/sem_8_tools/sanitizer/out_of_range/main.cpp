#include <iostream>

int main()
{
    size_t N = 11;
    int* array = new int[N];
    int* array1 = new int[N];

    std::cout << "Address: " << array << "\n";
	int* ptr = &array[11];
	for (int i = 0; i < N + 1; ++i) {
        array[i] = 27;
    }

    delete[] array;
	delete[] array1;

    return 0;
}
