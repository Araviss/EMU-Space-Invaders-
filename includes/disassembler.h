
// disassembler.h
#ifndef DISASSEMBLER_H
#define DISASSEMBLER_H

#include <fstream>
#include <stdlib.h>
#include <vector>

class disassembler {
public:
    disassembler() {}
    ~disassembler() {}
    
    //Get the total size of the files
    const std::streamsize get_size(std::vector<std::ifstream*>& files) const {
        
        std::streamsize size;
        for(std::ifstream* file: files){
            file->seekg(0, file->end);
            size = size + file->tellg();
            file->seekg(0, file->beg);
    }        
        return size;
    }

    //store all the hex values in an array
    const void store_files(char hex_array[], std::vector<std::ifstream*> files){
        std::streamsize offset = 0;
    // Read the file content into the array
    for (std::ifstream* file : files) {
    if (file->is_open()) {
        // Get the size of the current file
        file->seekg(0, file->end);
        std::streamsize size = file->tellg();
        file->seekg(0, file->beg);

        // Read the content of the current file into the array at the current offset
        if (!file->read(hex_array + offset, size)) {
            std::cerr << "Failed to read the file\n";
            delete[] hex_array;
            break;
        }

        // Update the offset by adding the size of the current file
        offset += size;

        // Close the file
        file->close();
    } else {
        std::cerr << "Failed to open a file\n";
        }
    }
        
    }


};

#endif // DISASSEMBLER_H