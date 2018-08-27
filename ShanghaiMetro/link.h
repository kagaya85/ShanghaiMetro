#include <qstring.h>
#include <line.h>

class Link {
public:
	QString to;
	Line line;
	int flag;
	int weight;

	Link();
	Link(QStringList strList);
	void set_link(QStringList strList);
};