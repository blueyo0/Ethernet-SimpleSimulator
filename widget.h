#ifndef WIDGET_H
#define WIDGET_H
#include <QtGui>
#include <QtCore>
#include <QWidget>
#include <time.h>
#include <QThread>
#include "ui_widget.h"
#include <stdlib.h>
#include "PC.h"
#include "math.h"
#include <windows.h>
#include <QTimer>

namespace Ui {
    class CellWidget;
}


class CellWidget : public QWidget,public Ui::Widget
{
    Q_OBJECT

public:
    explicit CellWidget(QWidget *parent = 0);
    void refresh();
    void refresh_state();
    void check_conflict();
    void send_update();
    void sending_update();
    void sending(int);
private:
    QTimer* timer;
    QTimer* sendTimer;
    int sendTime;
    int count;
    int sender;
    int Bus[16];
    PC_Entity PC[6];   
    bool confirm_flag;
    bool start_flag;
    bool stop_flag;
//public slots:

private slots:
    void start_clicked();
    void confirm_clicked();
    void pause_clicked();
    void PC1_add();
    void PC1_minus();
    void PC2_add();
    void PC2_minus();
    void PC3_add();
    void PC3_minus();
    void PC4_add();
    void PC4_minus();
    void PC5_add();
    void PC5_minus();
    void PC6_add();
    void PC6_minus();
    void onTimeout();
    void onSendTimeout();
};  
#endif // WIDGET_H
