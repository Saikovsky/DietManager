#include "DescriptionWIdgetWindow.hpp"
#include "MealProvider.hpp"
#include <algorithm>

DescriptionWidgetWindow::DescriptionWidgetWindow(QWidget* parent) : QWidget(parent)
{
	//TODO: Add grid layout
	//Separate labels from text;
	setGeometry(10, 10, 800, 400);
	titleLabel = new QLabel("Title:", this);
	titleLabel->setGeometry(5, 0, 200, 200);
	titleLabel->setAlignment(Qt::AlignLeft);

	categoryLabel = new QLabel("Category:", this);
	categoryLabel->setGeometry(5, 14, 200, 200);
	categoryLabel->setAlignment(Qt::AlignLeft);

	ingredientsLabel = new QLabel("Ingredients:", this);
	ingredientsLabel->setGeometry(5, 50, 200, 400);
	ingredientsLabel->setAlignment(Qt::AlignLeft);

	descriptionLabel = new QLabel(descriptionString, this);
	descriptionLabel->setGeometry(200, 5, 500, 300);
	descriptionLabel->setAlignment(Qt::AlignLeft);
	//QFont font("Arial", 15);
	//font.setBold(true);
	//descriptionLabel->setFont(font);
	
	descriptionLabel->setFrameStyle(QFrame::Box | QFrame::Plain);
	descriptionLabel->setLineWidth(1);

	//frame = new QFrame(this);
	//frame->setFrameStyle(QFrame::Box | QFrame::Plain);
	//frame->setLineWidth(2);
	//frame->setGeometry(0, 0, 400, 400);


}

void DescriptionWidgetWindow::handleItemClicked(QListWidgetItem* item)
{
	MealProvider mp("sample_breakfast");
	auto mpPtr = mp.getMeal();

	auto selectedItemName = item->text();
	//mpPtr->meals()->begin()->
	auto findMealToUpdate = std::find_if(mpPtr->meals()->begin(), mpPtr->meals()->end(), 
		[&selectedItemName](auto mealElement) 
		{
			return mealElement->title()->c_str() == selectedItemName;
		});
	if (findMealToUpdate != mpPtr->meals()->end())
	{
		titleLabel->setText(titleString + findMealToUpdate->title()->c_str());
		descriptionLabel->setText(descriptionString + findMealToUpdate->description()->c_str());

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
			ingrString += QString(" ") + QString(it->name()->c_str()) + QString("\n");
			if (it->weight_g() > 0.0f)
			{
				auto weight = std::to_string(it->weight_g());
				weight.resize(weight.size() - 4);
				ingrString += "\t Weight [g]:" + weight +"\n";
			}
			if (it->volume_ml() > 0.0f)
			{
				auto volume = std::to_string(it->volume_ml());
				volume.resize(volume.size() - 4);
				ingrString += "\t Volume [ml]:" + volume + "\n";
			}
		}
		ingredientsLabel->setText(ingrString);
	}
}