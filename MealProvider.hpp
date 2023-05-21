#pragma once

#include "generated/meals_generated.h"

class MealProvider
{
public:
	MealProvider(std::string binaryName);
	const Meals::Meals* getMeal();
private:
	std::string binaryName;
	
};