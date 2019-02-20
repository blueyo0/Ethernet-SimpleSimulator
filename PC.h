#include <time.h>
#include <QtGui>
#include <QtCore>
#include <windows.h>
#include <QThread>
#include <QMutex>
#include <stdlib.h>

class PC_Entity : public QThread
{
public:
	int wantsend;//数据包发送标志，=1表示正在发送数据包，=0表示想要发送数据包 并正在进行96比特时间的空闲监听，<0表示处于回退状态中
	int station;//主机位置
	int watch;//96比特时间检测完成度，watch==6表示完成了96比特时间信道空闲检测
    int back_number;//回退次数
    int package_number;//发送的数据包数量

    PC_Entity();
    void stop();
protected:
	void run();
private:
	volatile bool stopped;
};