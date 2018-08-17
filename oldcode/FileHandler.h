#pragma once
#include <string>
#include <fstream>
#include <iostream>
class FileHandler
{
public:
	static void writeToFile(std::string, std::string, std::string &);
	static void writeToFile(std::string, std::string &);
	static std::string & readFromFile(std::string, std::string);
	static std::string & readFromFile(std::string);
};