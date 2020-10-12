#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

#include "../includes/utilities.h"
#include "../includes/fileio.h"

using namespace std;
using namespace constants;


//opens file
bool openFile(fstream& myfile, const string& myFileName,
		ios_base::openmode mode){
	myfile.open(myFileName,mode);
	if (myfile.is_open()){return true;}
	else{return false;}
}

//close file if open

void closeFile(fstream& myfile){
	if(myfile.is_open()){
		myfile.close();}
	}

int writetoFile(vector<entry>  &entries,
		const string &outputfilename){
	fstream output;
	openFile(output, outputfilename, ios_base::out);
	if(!output.is_open()){
		return FAIL_FILE_DID_NOT_OPEN;
	}
	if(entries.size()==0){
		return FAIL_NO_ARRAY_DATA;
	}
	for(int i =0; i<entries.size(); i++){
	output<<entries[i].word<<" "<<intToString(entries[i].number_occurences)<<endl;
	}
	closeFile(output);
	return SUCCESS;
}

