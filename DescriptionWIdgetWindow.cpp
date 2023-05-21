#include "DescriptionWIdgetWindow.hpp"

DescriptionWidgetWindow::DescriptionWidgetWindow(QWidget* parent) : QWidget(parent)
{
	setGeometry(10, 10, 400, 400);
	title = new QLabel("Title:", this);
	title->setGeometry(0, 0, 200, 200);
	title->setAlignment(Qt::AlignLeft);

	category = new QLabel("Category:", this);
	category->setGeometry(0, 50, 200, 200);
	category->setAlignment(Qt::AlignLeft);

	description = new QLabel("Description:", this);
	description->setGeometry(0, 100, 200, 200);
	description->setAlignment(Qt::AlignLeft);
	
}

void DescriptionWidgetWindow::handleItemClicked()
{
	title->setText("Dupa");
}