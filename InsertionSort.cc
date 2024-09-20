#include <iostream>

int main(void){
     int numbers[] = {8, 4, 6, 9, 5, 3, 1};

    // Print the original array
    std::cout << "Original array: ";
    for (int i = 0; i < 7; i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    for (int j = 1; j < 7; j++)
    {
         int key = numbers[j];
         int i = j - 1;

         while (numbers[i] > key && i >= 0)
         {
             numbers[i + 1] = numbers[i];
             i = i - 1;
         }

         numbers[i + 1] = key;
    }


    // Print the sorted array
    std::cout << "Sorted array: ";
    for (int i = 0; i < 7; i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;
}