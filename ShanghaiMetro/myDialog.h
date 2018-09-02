#pragma once
#include "ui_NewStation.h"
#include "ui_AddLinkDialog.h"

#include <qdialog.h>
#include <qwidget.h>
#include <qstring.h>

class NewStation : public QDialog {
	Q_OBJECT

public:
	NewStation(QWidget *parent = Q_NULLPTR);
	QString returnText();
private:
	Ui::newStation ui;
};

class AddLink : public QDialog {
public:
	AddLink(QWidget *parent = Q_NULLPTR);

private:
	Ui::Dialog ui;
};
