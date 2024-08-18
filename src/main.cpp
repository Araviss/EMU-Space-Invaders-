#include <iostream>
#include <fstream>
#include <cstdio>
#include <stdlib.h>
#include <vector>

//Program headers
#include "../includes/disassembler.h"
#include "../includes/Instructions.h"





int main() {
    disassembler file_disassembler;
    
    //Program Counter
    int counter = 0;

    // Open the files in binary mode
    std::ifstream file_h("../roms/invaders.h", std::ios::binary);
    std::ifstream file_g("../roms/invaders.g", std::ios::binary);
    std::ifstream file_f("../roms/invaders.f", std::ios::binary);
    std::ifstream file_e("../roms/invaders.e", std::ios::binary);

    printf("started\n");
    std::vector<std::ifstream*> streams = {&file_h, &file_g, &file_f, &file_e}; 


    if (!(file_h.is_open() & file_g.is_open() & file_f.is_open() & file_e.is_open())) {
        std::cerr << "Failed to open the file\n";
        return 1;
    }

    // Get the total size of files
    std::streamsize size = file_disassembler.get_size(streams);
    
    // Allocate memory for the array
    printf("Hex Array Success");
    char* hex_array = new char[size];
    printf("Hex Array Success");
    // At this point, hex_array contains the concatenated contents of all files
    file_disassembler.store_files(hex_array, streams);



    // for(int i=0; i <size; i++){
    //     printf("%02X \n", static_cast<unsigned char>(hex_array[i]));
    // };

    Instructions instruction =  Instructions(counter);

    //loop to iterate over memory array 
    while(true){
        instruction.getOpcode(hex_array[counter]);
        // printf("%02X \n", static_cast<unsigned char>(hex_array[counter]));
        break;
    };

    // Clean up: Free the allocated memory
    delete[] hex_array;

    return 0;
}

