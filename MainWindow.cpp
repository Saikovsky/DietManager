#include "MainWindow.hpp"


MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent)
{
	setObjectName("MainWindow");
	setWindowTitle("Main window");

	QSize qs(1000, 500);
	setMinimumSize(qs);
	setMaximumSize(qs);
	setGeometry(100, 100, 1000, 500);
	
	mlw = new MealListWindow(this);

	dww = new DescriptionWidgetWindow(this);

	QObject::connect(mlw, SIGNAL(itemClicked(QListWidgetItem*)), dww, SLOT(handleItemClicked(QListWidgetItem*)));
}