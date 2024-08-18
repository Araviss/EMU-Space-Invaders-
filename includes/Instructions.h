#include <fstream>
#include <stdlib.h>
#include <vector>

class Instructions{
    int counter;

    public:
        Instructions(int &x){
            counter = x;
        }
        ~Instructions(){}
        

        void getOpcode(char opcode){
            printf("this is the opcode %s",opcode );
            // if(opcode == "00"){
            //     nop();
                    
            // }
        }
    
    private:
        void nop(){
            counter++;
        }

};