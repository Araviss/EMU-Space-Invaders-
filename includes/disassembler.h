
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
        
        std::streamsize size = 0;
        for(std::ifstream* file: files){
            file->seekg(0, file->end);
            size = size + file->tellg();
            file->seekg(0, file->beg);
    }        
        return size;
    }

    //store all the hex values in an array
    void store_files(std::vector<char>& hex_array, const std::vector<std::ifstream*>& files) {
    std::streamsize offset = 0;
    printf("inside \n");

    std::streamsize size = 0;
    for (std::ifstream* file : files) {
        printf("inside loop \n");
        if (file->is_open()) {
            // Get the size of the current file
            printf("inside  if statement\n");
            file->seekg(0, file->end);
            printf("file seek \n");
            size = file->tellg();
            printf("file size \n");
            file->seekg(0, file->beg);
            printf("file seek beg \n");


            // Read the content of the current file into the array at the current offset
            if (!file->read(&hex_array + offset, size)) {
                std::cerr << "Failed to read the file\n";
                break;
            }
            printf("fi;e offset\n");
            // Update the offset by adding the size of the current file
            offset += size;
           ;
        } else {
            std::cerr << "Failed to open a file\n";
        }
        }   
    }
};

#endif // DISASSEMBLER_H