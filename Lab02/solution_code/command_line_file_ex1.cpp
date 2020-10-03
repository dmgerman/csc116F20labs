#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char** argv) {
    // "argv[1]" is the first user provided command line argument
    std::string filename {argv[1]};
    std::ifstream myfile {};
    
    // open a file stream from the file 
    myfile.open(filename);

    if (myfile.is_open()) {
        std::string line{};
		
        // reads a line of text from the file, then prints it to standard output
        while (std::getline(myfile, line)) {
            std::cout << line << std::endl;
        }

        myfile.close();
    } else {
        std::cout << "Unable to open file." << std::endl;
    }
	
    return 0;
}
