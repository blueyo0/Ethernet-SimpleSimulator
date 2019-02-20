#include <QApplication>
#include "widget.h"
//#include "ui_widget.h"

int main(int argc,char *argv[])
{
	QApplication app(argc,argv);
	QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));

	CellWidget *w = new CellWidget;
    w->show();

	return app.exec();
}

