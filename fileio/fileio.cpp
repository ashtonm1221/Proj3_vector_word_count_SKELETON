#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "../includes/constants.h"
#include "../includes/fileio.h"

bool openFile(std::fstream& myfile, const std::string& myFileName,
		std::ios_base::openmode mode = std::ios_base::in){
	return false;
}

void closeFile(std::fstream& myfile){

}

int writetoFile(std::vector<constants::entry>  &entries, const std::string &outputfilename){
	return -1;
}
