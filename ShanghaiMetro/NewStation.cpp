#include "NewStation.h"

NewStation::NewStation(QWidget *parent) :QDialog(parent)
{
	ui.setupUi(this);
	setWindowTitle("Add New Station");
}