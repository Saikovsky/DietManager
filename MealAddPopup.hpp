#include <qdialog.h>
#include <qdialogbuttonbox.h>
#include <qgroupbox.h>
#include <qpushbutton.h>
#include <qformlayout.h>

class MealAddPopup : public QDialog
{
	Q_OBJECT
public:
	explicit MealAddPopup(QWidget* parent = nullptr);
signals:
public slots:
	void addItem();
	void cleanUp();
	void removeItem();
private:
	QGroupBox* formGroupBox;
	QDialogButtonBox* buttonBox;
	QPushButton* addIngredientButton;
	QPushButton* removeIngredientButton;
	QFormLayout* layout;
	QHBoxLayout* ingredientLayout;
	void createButtonBox();
	void createForm();
	void addIngredientRow(QHBoxLayout* ingredientLayout);
	uint8_t ingredientCounter{ 0 };
};