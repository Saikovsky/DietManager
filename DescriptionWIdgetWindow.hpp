#pragma once
#include <qwidget.h>
#include <QLabel>

class DescriptionWidgetWindow : public QWidget
{
	Q_OBJECT
public:
	explicit DescriptionWidgetWindow(QWidget* parent = nullptr);
signals:
public slots:
	void handleItemClicked();
private:
	QLabel* description;
	QLabel* category;
	QLabel* title;

};