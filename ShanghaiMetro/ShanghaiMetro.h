#include <QtWidgets/QMainWindow>
#include "ui_ShanghaiMetro.h"
#include "node.h"

class ShanghaiMetro : public QMainWindow 
{
	Q_OBJECT

public:
	ShanghaiMetro(QWidget *parent = Q_NULLPTR);
	Node findNode(QString name);
	void paintEvent(QPaintEvent *);

private:
	Ui::ShanghaiMetroClass ui;
	QVector<Node> Nodes;

};
