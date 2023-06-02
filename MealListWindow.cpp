#include "MealListWindow.hpp"
#include "utils/MealProvider.hpp"
#include "utils/Logger.hpp"

MealListWindow::MealListWindow(QWidget* parent) : QListWidget(parent)
{
    setGeometry(780, 20, 200, 200);
    
    // Adding items to the list
    MealProvider mp("meals");
    auto mpPtr = mp.getMeal();

    for (auto it = mpPtr->meals()->begin(); it != mpPtr->meals()->end(); it++)
    {
        addItem(it->title()->c_str());
    }
    
    setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    //QScrollBar* qsb = this->verticalScrollBar();
    //setVerticalScrollBar(qsb);
    //Logger log;
    //log.info();

    //addItem(mpPtr->title()->c_str());
    
};