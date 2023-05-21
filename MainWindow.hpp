#pragma once

#include <qmainwindow.h>
#include <qlabel.h>

#include "MealListWindow.hpp"
#include "DescriptionWIdgetWindow.hpp"
class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget* parent = nullptr);

signals:
public slots:

private:
	MealListWindow* mlw;
	DescriptionWidgetWindow* dww;
};