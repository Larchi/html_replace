#include "threadmanager.h"

int main(int argc, char *argv[])
{
    if(argc == 1 || argc == 2) {
        std::cout << "Parameters count Error." << std::endl;
        std::cout << "Format: html_replace.exe <file> <new string>" << std::endl;
    } else {
        std::string fname = argv[1];
        std::string path = argv[2];

        ThreadManager manager(fname, path);
    }
    return 0;
}


