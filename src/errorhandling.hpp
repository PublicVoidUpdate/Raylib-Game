#include "stdio.h"
#include <filesystem>
#include <iostream>
#include "fstream"

using namespace std;
namespace fs = std::filesystem;

void readcheck()
{
    const char path[] = "./ReadWritecheck";
    try{
        //std::ofstream(path).flush();;
        std::ofstream output(path);
        fs::path f{path};
        if (!fs::exists(f)) throw runtime_error("");
            }
    catch(const exception& error){
        printf("I can't seem to create anything... Please dont be mad....", "\n");
        printf("\n\x1B[31mERROR!! NO READ/WRITE PERMISSIONS CANNOT SAVE OR LOAD DATA!!\033[0m\n");
    }
    std::filesystem::remove(path);
}