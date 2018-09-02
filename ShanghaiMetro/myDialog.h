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
	Q_OBJECT

public:
	AddLink(QWidget *parent = Q_NULLPTR);
	QString returnStaFrom();
	QString returnStaTo();
	int returnLineNum();
private:
	Ui::Dialog ui;
signals:
	void addNewLink(QString StaFrom, QString StaTo, int lineNum);
public slots:
	void sendSignal(bool checked);
};
