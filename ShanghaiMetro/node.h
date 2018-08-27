#include <qstring.h>
#include <qlist.h>
#include <link.h>

class Node {
public:
	QString name;
	int posx;
	int posy;
	QList<Link> links;

	Node();
	Node(QStringList strList);
	void set_node(QStringList strList);
	bool operator==(const Node b);
};
