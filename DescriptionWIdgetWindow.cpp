#include "DescriptionWIdgetWindow.hpp"
#include "MealProvider.hpp"
#include <algorithm>

DescriptionWidgetWindow::DescriptionWidgetWindow(QWidget* parent) : QWidget(parent)
{
	prepareLayout();
}

void DescriptionWidgetWindow::handleItemClicked(QListWidgetItem* item)
{
	MealProvider mp("meals");
	auto mpPtr = mp.getMeal();

	auto selectedItemName = item->text();

	auto findMealToUpdate = std::find_if(mpPtr->meals()->begin(), mpPtr->meals()->end(), 
		[&selectedItemName](auto mealElement) 
		{
			return mealElement->title()->c_str() == selectedItemName;
		});


	if (findMealToUpdate != mpPtr->meals()->end())
	{
		titleLabel->setText(titleString + findMealToUpdate->title()->c_str());
		descriptionLabel->setText(findMealToUpdate->description()->c_str());

		switch (findMealToUpdate->meal_type())
		{
			case Meals::MealType::MealType_Breakfast:
				categoryLabel->setText(categoryString + "Breakfast");
				break;
			case Meals::MealType::MealType_secndBreakfast:
				categoryLabel->setText(categoryString + "Second Breakfast");
				break;
			case Meals::MealType::MealType_Dinner:
				categoryLabel->setText(categoryString + "Dinner");
				break;
			case Meals::MealType::MealType_AfternoonSnack:
				categoryLabel->setText(categoryString + "Pre Supper");
				break;
			case Meals::MealType::MealType_Supper:
				categoryLabel->setText(categoryString + "Supper");
				break;
			default:
				categoryLabel->setText(categoryString + "Default");
		}

		QString ingrString{ingredientsString+"\n"};
		for (auto it = findMealToUpdate->ingredients()->begin(); it != findMealToUpdate->ingredients()->end(); it++)
		{
			ingrString += QString("\u2022 ") + QString(it->name()->c_str());
			if (it->weight_g() > 0.0f)
			{
				auto weight = std::to_string(it->weight_g());
				weight.resize(weight.size() - 7);
				ingrString += " " + weight +" g\n";
			}
			if (it->volume_ml() > 0.0f)
			{
				auto volume = std::to_string(it->volume_ml());
				volume.resize(volume.size() - 7);
				ingrString += " " + volume + " ml\n";
			}
		}
		ingredientsLabel->setText(ingrString);
	}
}

void DescriptionWidgetWindow::prepareLayout()
{
	//TODO: Add grid layout
	//Separate labels from text;
	setGeometry(10, 10, 800, 400);

	titleLabel = new QLabel("", this);
	titleLabel->setGeometry(5, 0, 200, 200);
	titleLabel->setAlignment(Qt::AlignLeft);

	categoryLabel = new QLabel("", this);
	categoryLabel->setGeometry(5, 14, 200, 200);
	categoryLabel->setAlignment(Qt::AlignLeft);

	ingredientsLabel = new QLabel("", this);
	ingredientsLabel->setGeometry(5, 50, 200, 400);
	ingredientsLabel->setAlignment(Qt::AlignLeft);

	descriptionLabel = new QLabel("", this);
	descriptionLabel->setGeometry(0, 0, 540, 290);
	descriptionLabel->setAlignment(Qt::AlignLeft);
	//QFont font("Arial", 15);
	//font.setBold(true);
	//descriptionLabel->setFont(font);
	descriptionScrollArea = new QScrollArea(this);
	descriptionScrollArea->setWidget(descriptionLabel);
	descriptionScrollArea->setGeometry(180, 5, 540, 300);
	descriptionScrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	descriptionScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
	descriptionScrollArea->setFrameStyle(QFrame::Box | QFrame::Plain);
	descriptionScrollArea->setLineWidth(1);

}