#include "MainWindow.hpp"
#include "qdialog.h"
#include <QScreen>
#include <qguiapplication.h>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent)
{
	setObjectName("MainWindow");
	setWindowTitle("Diet Manager");
	QScreen* screen = QGuiApplication::primaryScreen();
	//TODO: Create some magic calculations and share dependant window size variables instead of absolute
	//1920x1080
	QRect mainScreenSize = screen->geometry();
	QSize qs = mainScreenSize.size()/1.5;
	setMinimumSize(qs);
	setMaximumSize(qs);
	resize(qs);
	move(mainScreenSize.topLeft());
	
	mlw = new MealListWindow(this);
	dww = new DescriptionWidgetWindow(this);
	mab = new MealAddButton(this);
	mapop = new MealAddPopup(this);

	//callendar
	//cww = new cll...

	QObject::connect(mlw, SIGNAL(itemClicked(QListWidgetItem*)), dww, SLOT(handleItemClicked(QListWidgetItem*)));
	QObject::connect(mab, SIGNAL(pressed()), mapop, SLOT(exec()));
}