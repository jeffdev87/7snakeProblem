/*
 * ParseInput class to parse data from the stdin.
 *
 * It is expected that the grid be in csv format in the 
 * input file.
 *
 */
 
#include<iostream>

class ParseInput
{
	public:
	
	ParseInput(){}
	~ParseInput(){}
		
	static int *ParseRow(std::string line, unsigned int size, char sep)
	{
		line+=sep;

		std::size_t prevSep = 0, 
					currSep = line.find_first_of(sep);
		
		int *row = new int[size], i = 0;

		while (currSep != std::string::npos && i < size)
		{
			std::string value = line.substr(prevSep, currSep - prevSep);		
			sscanf(value.c_str(), "%d ", &row[i++]);
			
			prevSep = currSep + 1;
			currSep = line.find_first_of(sep, prevSep);
		}
		
		return row;
	}
};