#pragma once
#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>

class Logger
{
public:
	Logger();
	~Logger();

private:
	std::time_t getTime();
	std::ofstream file;
	void trimString(std::string& s);
	std::string filepath = "logs.txt";

	void openLogFile();

public:
	void info(std::string s);
	void warning(std::string s);
	void error(std::string s);

	void setUpAndClean();

};