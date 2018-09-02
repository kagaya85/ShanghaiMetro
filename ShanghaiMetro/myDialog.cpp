#include "myDialog.h"

NewStation::NewStation(QWidget *parent) :QDialog(parent)
{
	ui.setupUi(this);
	setWindowTitle("Add New Station");
	setAttribute(Qt::WA_DeleteOnClose);
}

QString NewStation::returnText()
{
	return ui.lineEdit->text();
}

AddLink::AddLink(QWidget *parent) :QDialog(parent)
{
	ui.setupUi(this);
	setWindowTitle("Add Link");
	setAttribute(Qt::WA_DeleteOnClose);
	ui.lineNum->setMaximum(20);
	ui.lineNum->setMinimum(1);
	ui.lineNum->setValue(1);
	//ui.lineNum->setSuffix("ºÅÏß");
}

QString AddLink::returnStaFrom()
{
	return ui.fromSta->text();
}

QString AddLink::returnStaTo()
{
	return ui.toSta->text();
}

int AddLink::returnLineNum()
{
	return ui.lineNum->value();
}
