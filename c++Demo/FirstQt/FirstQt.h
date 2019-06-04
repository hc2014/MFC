#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_FirstQt.h"

class FirstQt : public QMainWindow
{
	Q_OBJECT

public:
	FirstQt(QWidget *parent = Q_NULLPTR);

private:
	Ui::FirstQtClass ui;
};
