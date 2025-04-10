#include <iostream>
#include <iomanip>

void print_memory(void *ptr, size_t size)
{
    unsigned char *p = static_cast<unsigned char *>(ptr);
    std::cout << "Memory at address " << ptr << " (byte by byte):" << std::endl;
    std::cout << "Byte  | Hex  | Dec  | Char" << std::endl;
    std::cout << "---------------------" << std::endl;
    for (size_t i = 0; i < size; i++)
    {
        std::cout << std::setw(5) << i << " | ";
        std::cout << std::hex << std::setw(4) << std::setfill('0') << static_cast<int>(p[i]) << " | ";
        std::cout << std::dec << std::setw(4) << static_cast<int>(p[i]) << " | ";

        if (p[i] >= 32 && p[i] <= 126) // Printable ASCII
            std::cout << " '" << static_cast<char>(p[i]) << "'" << std::endl;
        else
            std::cout << " - " << std::endl;
    }
    std::cout << std::dec; // Reset to decimal
}

int main()
{
    // Create an int with value 65
    int *ptr = new int(65);

    // Print original value
    std::cout << "Original int value: " << *ptr << std::endl;

    // Print memory representation of the int (4 bytes)
    print_memory(ptr, sizeof(int));

    // Reinterpret as a char pointer
    char *ch = reinterpret_cast<char *>(ptr);

    // Show what happens with different prints
    std::cout << "\nAddress comparisons:" << std::endl;
    std::cout << "ptr address: " << static_cast<void *>(ptr) << std::endl;
    std::cout << "ch address:  " << static_cast<void *>(ch) << " (same address!)" << std::endl;

    std::cout << "\nOutput examples:" << std::endl;
    std::cout << "std::cout << ptr: " << ptr << std::endl;
    std::cout << "std::cout << ch:  " << ch << std::endl;    // Prints as C-string
    std::cout << "std::cout << *ptr: " << *ptr << std::endl; // Int value (65)
    std::cout << "std::cout << *ch:  " << *ch << std::endl;  // First byte as char ('A')

    // Show what happens when we modify through different views
    std::cout << "\nModifying through different pointers:" << std::endl;
    *ch = 'B'; // Change first byte to 'B' (ASCII 66)
    std::cout << "After *ch = 'B':" << std::endl;
    std::cout << "*ptr = " << *ptr << std::endl;
    print_memory(ptr, sizeof(int));

    // Clean up
    delete ptr;
    return 0;
}
