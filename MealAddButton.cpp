#include "MealAddButton.hpp"

MealAddButton::MealAddButton(QWidget* parent) : QPushButton(parent)
{
	setGeometry(950, 220, 20, 20);
	setText("+");
}