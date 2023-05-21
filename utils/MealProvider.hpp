#pragma once

#include "../generated/meals_generated.h"
#include "Logger.hpp"

class MealProvider
{
public:
	MealProvider(std::string binaryName);
	const Meals::Meals* getMeal();
private:
	std::string binaryName;
};