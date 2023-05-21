#include "Logger.hpp"

Logger::Logger()
	{
		//Opening new file and appending should be safe no throwable
		file.open("logs.txt", std::ios::out);
	}
Logger::~Logger()
	{
		file.close();
	}
std::time_t Logger::getTime()
	{
		auto now = std::chrono::system_clock::now();
		std::time_t time = std::chrono::system_clock::to_time_t(now);
		return time;
	}
void Logger::trimString(std::string& s)
	{
		if (s.size() > 150)
			s.resize(150);
	}
void Logger::info(std::string s)
	{
		auto time = getTime();
		trimString(s);
		file << std::strtok(std::ctime(&time), "\n") << "::Info::" << s << "\n";
	}

void Logger::warning(std::string s)
	{
		auto time = getTime();
		trimString(s);
		file << std::strtok(std::ctime(&time), "\n") << "::Warning::" << s << "\n";
	}

void Logger::error(std::string s)
	{
		auto time = getTime();
		trimString(s);
		file << std::strtok(std::ctime(&time), "\n") << "::Error::" << s << "\n";
	}

