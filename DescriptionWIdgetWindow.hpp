#pragma once

#include <qwidget.h>
#include <QLabel>
#include <qlistwidget.h>
#include <qscrollarea.h>

class DescriptionWidgetWindow : public QWidget
{
	Q_OBJECT
public:
	explicit DescriptionWidgetWindow(QWidget* parent = nullptr);
signals:
public slots:
	void handleItemClicked(QListWidgetItem*);
private:
	QLabel* descriptionLabel;
	QLabel* categoryLabel;
	QLabel* titleLabel;
	QLabel* ingredientsLabel;
	QScrollArea* descriptionScrollArea;

	const QString descriptionString{ "Description:\n" };
	const QString categoryString{ "Category: " };
	const QString titleString{ "Title: " };
	const QString ingredientsString{ "Ingredients: " };

	QFrame* frame;

	void prepareLayout();
};