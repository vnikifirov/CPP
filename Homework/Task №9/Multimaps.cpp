// Include of libraries
#include <iostream>
#include <algorithm>
#include <conio.h>
#include <string>
#include <map>
#include <utility>
#include <fstream>
#include <iterator>

// Prototype of functions
bool loadFile(std::multimap<std::string, std::string>&);
	// loadFile - loading of an including file and filling of multimap
std::string get_key_word(std::string);
	// get_key_word - getting of a key word
void show(std::multimap<std::string, std::string>&, std::string);
	// show - display data on the screen
int main()
{
	// Members of program
	// Multimap
	std::multimap<std::string, std::string> my_map;
	// Input an information from user
	std::string key_word;
	
	/* Loading of file and if file doesn't load,
	   just do nothing */
	if (loadFile(my_map))
	{
		// Getting of key word
		key_word = get_key_word(key_word);
		// The display of resalt
		show(my_map, key_word);
	} else
		std::cout << "File is not open or can't be find" << std::endl;

	_getch();
}

bool loadFile(std::multimap<std::string, std::string>& my_map)
{
	// Members of function
	std::string word, stands_for;
	// Input of data
	// ifstream - can only read of file.
	std::ifstream my_file("words_in_english.txt");
	
	// If was load and find
	if (my_file.is_open())
	{
		while (!my_file.eof()) // if not at end of file, continue reading it
		{
			my_file >> word;
			std::getline(my_file, stands_for);			
			stands_for.erase(std::remove(stands_for.begin(), stands_for.end(), '\t'), stands_for.end());
			my_map.insert(std::pair<std::string, std::string>(word, stands_for));
		}
		// Close of file
		my_file.close();

		// if file has loaded
		return true;
	} else { return false; }
}

std::string get_key_word(std::string key_word)
{
	// Asking user
	std::cout << "Enter a word: ";
	std::cin >> key_word;
	
	return key_word;
}

void show(std::multimap<std::string, std::string>& mymap, std::string key_word)
{
	// Members of function
	/* It's multimap of iterators, pr is gonna be the pair of iterators.
	Returns the bounds of a range that includes all the elements in
	the container which have a key equivalent to k.
	How it will be look like:
	equal_range (const key_type& k) */
	std::pair<std::multimap<std::string, std::string>::iterator,
		std::multimap<std::string, std::string>::iterator> 
		pr = mymap.equal_range(key_word);

	// Display of request 
	std::multimap<std::string, std::string>::iterator it;
	for (it = pr.first; it != pr.second; ++it)
	{
		std::cout << it->first << " => " << it->second << std::endl;
	}
}