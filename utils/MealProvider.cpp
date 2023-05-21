#include "MealProvider.hpp"
#include <fstream>


MealProvider::MealProvider(std::string binaryName) : binaryName(binaryName)
{
	//auto result = system("")
	//Automating this with either json + fbs Parser or explicit call for flatc or leave manual flatc bin generation
	//Maybe filesystem?
}


const Meals::Meals* MealProvider::getMeal()
{
	//Maybe use std::filesystem
	Logger log;
	try
	{
		std::ifstream infile;
		infile.open("bin/" + binaryName + ".bin", std::ios::binary | std::ios::in);
		if (!infile.is_open())
			throw std::runtime_error("");
		infile.seekg(0, std::ios::end);
		int length = infile.tellg();
		infile.seekg(0, std::ios::beg);
		char* data = new char[length];
		infile.read(data, length);
		infile.close();
		auto meals = Meals::GetMeals(data);
		return meals;
	}
	catch (...)
	{
		log.error("No file with name " + binaryName);
	}
	return nullptr;
	
}