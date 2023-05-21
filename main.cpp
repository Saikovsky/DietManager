#include <iostream>
#include <fstream>
#include <qapplication.h>
#include <qpushbutton.h>
#include <flatbuffers/flatbuffers.h>
#include "generated/meals_generated.h"
#include "MealProvider.hpp"
#include "Logger.hpp"
#include "MainWindow.hpp"


int main(int argc, char** argv)
{
	QApplication app(argc, argv);


	MainWindow mainWindow;
	mainWindow.show();

	return app.exec();
}