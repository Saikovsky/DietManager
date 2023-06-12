#include "MealAddPopup.hpp"
#include <qformlayout.h>
#include <qlabel.h>
#include <qline.h>
#include <qcombobox.h>
#include <qspinbox.h>
#include <qlineedit.h>
#include <QHBoxLayout>



MealAddPopup::MealAddPopup(QWidget* parent) : QDialog(parent, Qt::MSWindowsFixedSizeDialogHint)
{
	resize(300, 300);
    
    createButtonBox();
    formGroupBox = new QGroupBox("Add recipe", this);
    layout = new QFormLayout(this);
    createForm();

    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(formGroupBox);
    mainLayout->addWidget(buttonBox);

}

void MealAddPopup::createButtonBox()
{
    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok
        | QDialogButtonBox::Cancel, this);

    //connect(buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    //connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
    QObject::connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    QObject::connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
    QObject::connect(buttonBox, SIGNAL(rejected()), this, SLOT(cleanUp()));
}

void MealAddPopup::createForm()
{

    
    //Category
    QComboBox* mealCategory = new QComboBox(this);
    //Add things from meal provider
    mealCategory->addItem("Breakfast");
    // 
    // 
    //Ingredient
    QHBoxLayout* ingredientLayout = new QHBoxLayout(this);
    addIngredientRow(ingredientLayout);



    addIngredientButton = new QPushButton(this);
    addIngredientButton->resize(20, 20);
    addIngredientButton->setText("+");

    layout->addRow(new QLabel("Meal name:"), new QLineEdit);
    layout->addRow(new QLabel("Category"), mealCategory);
    layout->addRow(new QLabel("Ingredients:"));
    layout->addRow(ingredientLayout);
    layout->addRow(addIngredientButton);
    formGroupBox->setLayout(layout);

   
    /*QComboBox* j = qobject_cast<QComboBox*>(layout->itemAt(1, QFormLayout::FieldRole)->widget());
    j->addItem("Dupa", 100);
    j->addItem("Asdf", 500);
    */

    QObject::connect(addIngredientButton, SIGNAL(pressed()), this, SLOT(addItem()));
}

void MealAddPopup::addIngredientRow(QHBoxLayout* ingredientLayout)
{
    ingredientCounter++;
    QComboBox* comboUnit = new QComboBox(this);
    comboUnit->setFixedSize(40, 20);
    comboUnit->addItem("ml");
    comboUnit->addItem("g");
    QSpinBox* volumeOrWeight = new QSpinBox(this);
    volumeOrWeight->setMaximum(9999);
    QLineEdit* ingredientName = new QLineEdit(this);
    QString str = QString::number(ingredientCounter);
    ingredientLayout->addWidget(new QLabel(str));
    ingredientLayout->addWidget(ingredientName);
    ingredientLayout->addWidget(volumeOrWeight);
    ingredientLayout->addWidget(comboUnit);
}

void MealAddPopup::addItem()
{
    QHBoxLayout* ingredientLayout = new QHBoxLayout(this);
    addIngredientRow(ingredientLayout);
    layout->insertRow(layout->rowCount()-1, ingredientLayout);
}

void MealAddPopup::cleanUp()
{
    //Absolute positions
    /*
    uint8_t lowerLimit = layout->rowCount()-(ingredientCounter+1);
    uint8_t upperLimit = layout->rowCount() - 2;
    //Has to be lower than rowCount and since "+" is last currently
    for (auto i = upperLimit; i >= lowerLimit; i--)
    {
        layout->removeRow(i);
    }
    
    */
    for (auto i = layout->rowCount() - 1; i >= 0; i--)
        layout->removeRow(i);
    ingredientCounter = 0;
    createForm();
    
}