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
}