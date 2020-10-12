#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

#include "../includes/array_functions.h"
#include "../includes/utilities.h"

using namespace std;
using namespace constants;

namespace KP{


	//zero out vector that tracks words and their occurrences
	void clear(vector<entry>  &entries){
		entries.clear() ;
	}

	//how many unique words are in the vector
	int getSize(vector<entry>  &entries){
		return entries.size();

	}

	//get data at a particular location, if i>size() then get the last value in the vector
	//(this is lazy, should throw an exception instead)
	string getWordAt(vector<entry>  &entries, int i){
		if(i>entries.size()){
			return intToString(entries[i].number_occurences);
		}
		return entries.at(i).word;

	}

	int getNumbOccurAt(vector<entry>  &entries,int i){
		return entries.at(i).number_occurences;
	}

	/*loop through whole file, one line at a time
	 * call processLine on each line from the file
	 * returns false: myfstream is not open
	 *         true: otherwise*/
	bool processFile(vector<entry>  &entries,fstream &myfstream){
		string ms;
		while(myfstream.eof() == false){
			if(!myfstream.is_open()){
				return false;
			}
			getline(myfstream,ms);
			processLine(entries,ms);
		}
		return true;

	}


	/*take 1 line and extract all the tokens from it
	feed each token to processToken for recording*/
	void processLine(vector<entry>  &entries,string &myString){
		stringstream s(myString);
		string t;
		while(getline(s,t,CHAR_TO_SEARCH_FOR)){
			processToken(entries, t);
		}
	}

	/*Keep track of how many times each token seen*/
	void processToken(vector<entry>  &entries,string &token){

		if(strip_unwanted_chars(token)==false){return;}
		string s =token;
		toUpper(s);
		for(int i=0; i< entries.size() ; i++){
			if(entries[i].word_uppercase== s){
				entries[i].number_occurences ++;
				return;
			}
		}
		entry time ={token, s, 1};
		if(token != " "){
			entries.push_back(time);}



	}

	//these bools alow for sorting of the file
	bool first(const entry& e1, const entry& e2){
		return e1.word_uppercase > e2.word_uppercase;
	}
	bool second(const entry& e1, const entry& e2){
			return e1.word_uppercase < e2.word_uppercase;
	}
	bool numOcur(const entry& e1, const entry& e2){
				return e1.number_occurences > e2.number_occurences;
	}

	/*
	 * Sort myEntryArray based on so enum value.
	 * Please provide a solution that sorts according to the enum
	 * The presence of the enum implies a switch statement based on its value
	 * See the course lectures and demo project for how to sort a vector of structs
	 */
	void sort(vector<entry>  &entries, sortOrder so){

		switch(so){
		case
			(sortOrder::ASCENDING):
			sort(entries.begin(), entries.end(), second);
			break;


		case
			(sortOrder::DESCENDING):
			sort(entries.begin(), entries.end(), first);
			break;

		case
			(sortOrder::NUMBER_OCCURRENCES):
			sort(entries.begin(), entries.end(), numOcur);
			break;
		case
			(sortOrder::NONE):
			break;

		}


	}
}
