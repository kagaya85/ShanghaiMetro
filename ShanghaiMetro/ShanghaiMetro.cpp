#include <ShanghaiMetro.h>
#include <qfile.h>
#include <qdebug.h>
#include "myDialog.h"
#include <queue>
#include <vector>

struct cmp
{
	bool operator()(Node* a, Node* b) const
	{
		//因为优先出列判定为!cmp，所以反向定义实现最小值优先
		return a->costF+a->costT > b->costF + b->costT;
	}
};

ShanghaiMetro::ShanghaiMetro(QWidget *parent)
	: QMainWindow(parent) 
{	
	ui.setupUi(this);
	setWindowTitle("ShanghaiMetro ver:1.0.0");
	//setAttribute(Qt::WA_DeleteOnClose); // 设置窗口关闭后自动释放内存 会报错
	QFile fp("info.txt");

	if (!fp.open(QIODevice::ReadOnly | QIODevice::Text))
		qDebug() << "open file error" << endl;

	QString str;
	QStringList strList;
	Node tempNode;
	Link tempLink;

	while (!fp.atEnd()) {

		str = fp.readLine();
		strList = str.split(' ');

		if (strList.size() == 3) {
			tempNode.set_node(strList);
		}
		else if (strList.size() == 4) {
			tempLink.set_link(strList);
			tempNode.links.append(tempLink);
		}
		else if (str == "*****\n") {
			Nodes.append(tempNode);
		}

	}

	//testShow();

	// 添加链接
	for (int i = 0; i < Nodes.size(); i++) {
		for (int j = 0; j < Nodes[i].links.size(); j++) {
			Nodes[i].links[j].from = &Nodes[i];
			Nodes[i].links[j].to = findNode(Nodes[i].links[j].toName);
		}
	}

	connect(ui.map, &MapView::addNewStation, this, &ShanghaiMetro::addNode);
	connect(ui.addLink, &QPushButton::clicked, this, &ShanghaiMetro::addLinkDialog);
	connect(ui.search, &QPushButton::clicked, this, &ShanghaiMetro::search);
	connect(ui.clear, &QPushButton::clicked, this, &ShanghaiMetro::clear);

	mapScene = new MapScene(Nodes);
	ui.map->setScene(mapScene);
}

Node* ShanghaiMetro::findNode(QString name) {
	for (int i = 0; i < Nodes.size(); i++) {
		if (Nodes[i].name == name)
			return &Nodes[i];
	}

 	return NULL; // null
}

void ShanghaiMetro::addNode(QString n, QPoint pos)
{
	if (n == QString::null)
		return;
	/*pos为scene坐标*/
	int realx = (pos.x() - X0) / Radio;
	int realy = (pos.y() - X0) / Radio;
	Node newNode(n, QPoint(realx, realy));
	Nodes.append(newNode);

	delete mapScene;
	mapScene = new MapScene(Nodes);
	ui.map->setScene(mapScene);

	return;
}

void ShanghaiMetro::addLinkDialog()
{
	AddLink* addLink = new AddLink();
	connect(addLink, &AddLink::addNewLink, this, &ShanghaiMetro::addLink);
	if (addLink->exec() == QDialog::Accepted) {
		//emit addLink->addNewLink(addLink->returnStaFrom(), addLink->returnStaTo(), addLink->returnLineNum());
	}
	//disconnect(addLink, &AddLink::addNewLink, this, &ShanghaiMetro::addLink);
}

/*将找到的路径存入Path中, 并显示在scene中*/
void ShanghaiMetro::searchPath(QString staFrom, QString staTo)
{
	Node* from = findNode(staFrom);
	Node* to = findNode(staTo);

	if (from == NULL | to == NULL)
		return;

	if (from->name == to->name) {
		Station *station = new Station(*from);
		delete mapScene;
		mapScene->addItem(station);
		ui.map->setScene(mapScene);
		return;
	}

	Path = findShortestPath(from, to);

	if (Path.isEmpty() == false) {
		Link tempLink;
		Route *route;
		Station *station;
		Lable *lable;

		delete mapScene;
		mapScene = new MapScene;
		while (Path.isEmpty() == false) {
			tempLink = Path.pop();
			route = new Route(tempLink, tempLink.line.color);
			mapScene->addItem(route);
			station = new Station(*tempLink.to);
			mapScene->addItem(station);
			lable = new Lable(*tempLink.to);
			mapScene->addItem(lable);
		}
		station = new Station(*tempLink.from);
		mapScene->addItem(station);
		lable = new Lable(*tempLink.from);
		mapScene->addItem(lable);

		ui.map->setScene(mapScene);
	}

	return;
}

/*初始化搜索变量*/
void ShanghaiMetro::initCost(Node* dest)
{
	QQueue<Node*> qin;	// 待扩展的队列
	QQueue<Node*> qout;  // 已扩展的队列

	// 设置初始花费为一个大数
	for (int i = 0; i < Nodes.size(); i++) {
		Nodes[i].costT = 9999;
		Nodes[i].costF = 9999;
		Nodes[i].pathFrom = NULL;
	}
	
	dest->costT = 0;

	qin.enqueue(dest);
	while (qin.isEmpty() == false) {
		Node* x = qin.dequeue();
		qout.enqueue(x);
		for (int i = 0; i < x->links.size(); i++) {
			int newCost = x->costT + x->links[i].weight;
			if (newCost < x->links[i].to->costT)
				x->links[i].to->costT = newCost;	// 更新花费
			if (!isInQueue(qout, x->links[i].to)) {
				// 加入扩展队列
				qin.enqueue(x->links[i].to);
			}
		}
	}
}

QStack<Link> ShanghaiMetro::findShortestPath(Node* start, Node* end)
{
	QStack<Link> result;
	std::priority_queue<Node*, std::vector<Node*>, cmp> qin;
	QQueue<Node*> qout;  // 已扩展的队列
	int flag = 0;	// 找到终点标志

	initCost(end);
	start->costF = 0;

	qin.push(start);
	while (qin.empty() == false) {
		Node* x = qin.top();
		qin.pop();
		qout.enqueue(x);
		for (int i = 0; i < x->links.size(); i++) {
			int newCost = x->costF + x->links[i].weight;
			if (newCost < x->links[i].to->costF) {
				x->links[i].to->costF = newCost;	// 更新花费
				x->links[i].to->pathFrom = x->links[i].from;
				if (x->links[i].to == end)
					flag = 1;
			}
			if (!isInQueue(qout,x->links[i].to)) {
				// 加入扩展队列
				qin.push(x->links[i].to);
			}
		}
		if (flag)
			break;
	}

	/*提取路径*/
	if (flag) {
		Link L;
		Node* p;
		for (int i = 0; i < end->links.size(); i++)
			if (end->links[i].to == end->pathFrom) {
				L = end->links[i];
				break;
			}
		result.push(L);
		p = end->pathFrom;
		while (p->name != start->name) {
			// 先搜索同线路的link
			for (int i = 0; i < p->links.size(); i++) {
				if (p->links[i].to == p->pathFrom && p->links[i].line.num == result.top().line.num) {
					L = p->links[i];
					break;
				}
			}
			// 判断是否找到，未找到重新搜索
			if (L == result.top()) {
				for (int i = 0; i < p->links.size(); i++) {
					if (p->links[i].to == p->pathFrom) {
						L = p->links[i];
						break;
					}
				}
			}
			result.push(L);
			p = p->pathFrom;
		}
	}

	return result;
}

//
//QStack<Node> ShanghaiMetro::findDirectPath(Node start, Node end)
//{
//	return QStack<Node>();
//}
//
//QStack<Node> ShanghaiMetro::findOneTransferPath(Node start, Node end)
//{
//	return QStack<Node>();
//}

bool ShanghaiMetro::isInQueue(const QQueue<Node*> q, const Node* x)
{
	for (int i = 0; i < q.size(); i++)
		if (x == q[i])
			return true;

	return false;
}

void ShanghaiMetro::clear()
{
	ui.startInput->clear();
	ui.destInput->clear();

	delete mapScene;
	mapScene = new MapScene(Nodes);
	ui.map->setScene(mapScene);
}

void ShanghaiMetro::search()
{
	searchPath(ui.startInput->text(), ui.destInput->text());
}

void ShanghaiMetro::addLink(QString staFrom, QString staTo, int lineNum)
{
	Node* nodeFrom = findNode(staFrom);
	Node* nodeTo = findNode(staTo);
	Link newLink;

	if (nodeFrom && nodeTo) {

		newLink.set_link(nodeTo, nodeFrom, lineNum, -1);
		nodeFrom->links.append(newLink);

		newLink.set_link(nodeFrom, nodeTo, lineNum, 0);
		nodeTo->links.append(newLink);

		// update scene
		delete mapScene;
		mapScene = new MapScene(Nodes);
		ui.map->setScene(mapScene);
	}
}

void ShanghaiMetro::testShow()
{
	qDebug() << Nodes.size();

	for (int i = 0; i<Nodes.size(); i++)
	{
		qDebug() << Nodes[i].name << "  " << Nodes[i].posx << "  " << Nodes[i].posy;
		for (int j = 0; j<Nodes[i].links.size(); j++)
		{
			qDebug() << Nodes[i].links.size();
			qDebug() << Nodes[i].links[j].to << "  " <<
				Nodes[i].links[j].line.get_num() << "  " <<
				Nodes[i].links[j].flag;
		}

	}
}
