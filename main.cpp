#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>

using namespace std;

int main(int argc, char* argv[])
{
 
    if (argc < 2) {
        return 1;
    }
    
std::ifstream file(argv[1], std::ios::binary | std::ios::ate);//abre el archivo
std::streamsize size = file.tellg();//calcula la memoria a utilizar
file.seekg(0, std::ios::beg);//apunta al comienzo del archivo

vector<char> buffer(size);

if (file.read(buffer.data(), size))
{
    
    std::ofstream outFile(argv[1], std::ofstream::binary);

    for (const auto &e : buffer) {
    	
    	if(e!='\xEF' && e!='\xBB' && e!='\xBF'){
    		outFile << e;
		}
    	
	}
	
}
    
    return 0;
}
