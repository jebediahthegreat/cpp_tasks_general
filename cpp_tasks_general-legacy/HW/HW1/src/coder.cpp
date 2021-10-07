#include <iostream>

#include "functions.h"

int main(int argc, char *argv[]) {
    if (argc < 4) {
        std::cerr << "Too few args\n";
        return -1;
    }
    srand(atoi(argv[1]));


    std::ifstream fd_in(argv[2]);
    std::ofstream fd_out(argv[3], std::ios::binary);
    if (!fd_in.is_open()) {
        std::cerr << "File not opened\n";
        return -1;
    }

    code_text(fd_in, fd_out);
    fd_in.close();
    fd_out.close();
}
