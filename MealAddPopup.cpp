#include "MealAddPopup.hpp"
#include <qformlayout.h>
#include <qlabel.h>
#include <qline.h>
#include <qcombobox.h>
#include <qspinbox.h>
#include <qlineedit.h>



MealAddPopup::MealAddPopup(QWidget* parent) : QDialog(parent, Qt::MSWindowsFixedSizeDialogHint)
{
	resize(300, 300);
    
    createButtonBox();
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
}

void MealAddPopup::createForm()
{
    formGroupBox = new QGroupBox(tr("Form layout"), this);
    QFormLayout* layout = new QFormLayout(this);
    layout->addRow(new QLabel(tr("Line 1:")), new QLineEdit);
    layout->addRow(new QLabel(tr("Line 2, long text:")), new QComboBox);
    layout->addRow(new QLabel(tr("Line 3:")), new QSpinBox);
    formGroupBox->setLayout(layout);
}