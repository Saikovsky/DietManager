#pragma once

#include <qmainwindow.h>
#include <qlabel.h>

#include "MealListWindow.hpp"
#include "DescriptionWIdgetWindow.hpp"
#include "MealAddButton.hpp"
#include "MealAddPopup.hpp"

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
	MealAddButton* mab;
	MealAddPopup* mapop;
};