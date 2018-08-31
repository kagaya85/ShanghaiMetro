#pragma once
#include "ui_NewStation.h"
#include <qdialog.h>
#include <qwidget.h>

class NewStation : public QDialog {
	Q_OBJECT

public:
	NewStation(QWidget *parent = Q_NULLPTR);
private:
	Ui::newStation ui;
};