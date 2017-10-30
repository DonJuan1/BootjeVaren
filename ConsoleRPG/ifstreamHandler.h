#pragma once

#include <fstream> 

class ifstreamHandler
{
public:
	ifstreamHandler(const char* fileName) { stream.open(fileName); };
	~ifstreamHandler() { stream.close(); };

	std::ifstream& getStream() { return stream; }

private:
	std::ifstream stream;
};
