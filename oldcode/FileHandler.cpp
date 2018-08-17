#include "FileHandler.h"

void FileHandler::writeToFile(std::string fileloc, std::string filename, 
	std::string & content)
{
}

void FileHandler::writeToFile(std::string filedir, std::string & content)
{
	std::ofstream out(filedir, std::ofstream::out);
	out << content;
	out.close();
}

std::string & FileHandler::readFromFile(std::string fileloc, std::string filename)
{
	std::string * filedir = new std::string();
	*filedir = fileloc + '\\' + filename;
	std::string content = readFromFile(*filedir);
	delete filedir;
	return content;
}

std::string & FileHandler::readFromFile(std::string filedir)
{
	std::ifstream inFile(filedir);
	std::string * content = new std::string();
	std::getline(inFile, *content, '\0');
	return *content;
}
