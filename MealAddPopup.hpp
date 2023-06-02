#include <qdialog.h>
#include <qdialogbuttonbox.h>
#include <qgroupbox.h>

class MealAddPopup : public QDialog
{
	Q_OBJECT
public:
	explicit MealAddPopup(QWidget* parent = nullptr);
signals:
public slots:
private:
	QGroupBox* formGroupBox;
	QDialogButtonBox* buttonBox;

	void createButtonBox();
	void createForm();
};