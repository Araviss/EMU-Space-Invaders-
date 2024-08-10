#include <iostream>
#include <fstream>
#include <cstdio>

int main() {
    printf("Program Started \n");
    
    // Open the file in binary mode
    std::ifstream file_f("roms/invaders.h", std::ios::binary);

    if (file_f.is_open()) {
        printf("File is open\n");

        // Read the entire file into a buffer
        std::streambuf* pbuf = file_f.rdbuf();

        // Get the size of the file
        std::streamsize size = pbuf->pubseekoff(0, file_f.end);
        pbuf->pubseekpos(0);

        // Allocate a buffer to hold the file content
        char* buffer = new char[size];

        // Read the file content into the buffer
        pbuf->sgetn(buffer, size);

        // Output the content to the console (for demonstration purposes)
        // This is where you'd process the bits in your actual application
        for (std::streamsize i = 0; i < size; ++i) {
            printf("%02X ", static_cast<unsigned char>(buffer[i]));
            if ((i + 1) % 16 == 0) printf("\n"); // Newline every 16 bytes
        }

        delete[] buffer; // Free the buffer
    } else {
        printf("Failed to open the file\n");
    }

    printf("Program End\n");

    return 0;
}