#pragma once

#include <qwidget.h>
#include <QLabel>
#include <qlistwidget.h>

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

	const QString descriptionString{ "Description: " };
	const QString categoryString{ "Category: " };
	const QString titleString{ "Title: " };
	const QString ingredientsString{ "Ingredients: " };

	QFrame* frame;
};