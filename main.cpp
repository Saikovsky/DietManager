#include <iostream>
#include <fstream>
#include <qapplication.h>
#include <qpushbutton.h>
#include <flatbuffers/flatbuffers.h>
#include "generated/meals_generated.h"
#include "utils/MealProvider.hpp"
#include "utils/Logger.hpp"
#include "MainWindow.hpp"
#include "utils/MealSaver.hpp"
#include <flatbuffers/util.h>
#include <flatbuffers/idl.h>

int main(int argc, char** argv)
{
	QApplication app(argc, argv);

	Logger log;
	log.setUpAndClean();

	MealSaver ms;
	
	MainWindow mainWindow;
	mainWindow.show();

	return app.exec();
}