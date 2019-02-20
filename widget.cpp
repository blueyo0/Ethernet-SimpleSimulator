#include "widget.h"
#include "ui_widget.h"

CellWidget::CellWidget(QWidget *parent) :
    QWidget(parent)
{
    this->setupUi(this);
    connect(confirm,SIGNAL(clicked()),this,SLOT(confirm_clicked()));
    connect(start,SIGNAL(clicked()),this,SLOT(start_clicked()));
    connect(pause,SIGNAL(clicked()),this,SLOT(pause_clicked()));
    connect(pushButton_3,SIGNAL(clicked()),this,SLOT(PC1_add()));
    connect(pushButton_4,SIGNAL(clicked()),this,SLOT(PC1_minus()));
    connect(pushButton_5,SIGNAL(clicked()),this,SLOT(PC2_add()));
    connect(pushButton_6,SIGNAL(clicked()),this,SLOT(PC2_minus()));
    connect(pushButton_7,SIGNAL(clicked()),this,SLOT(PC3_add()));
    connect(pushButton_8,SIGNAL(clicked()),this,SLOT(PC3_minus()));
    connect(pushButton_11,SIGNAL(clicked()),this,SLOT(PC4_add()));
    connect(pushButton_12,SIGNAL(clicked()),this,SLOT(PC4_minus()));
    connect(pushButton_9,SIGNAL(clicked()),this,SLOT(PC5_add()));
    connect(pushButton_10,SIGNAL(clicked()),this,SLOT(PC5_minus()));
    connect(pushButton_13,SIGNAL(clicked()),this,SLOT(PC6_add()));
    connect(pushButton_14,SIGNAL(clicked()),this,SLOT(PC6_minus()));
    
    PC[0].package_number = 1;
    PC[1].package_number = 1;
    for(int i=2;i<6;i++)
        PC[i].package_number = 0;
    for (int i=0;i<6;i++)//初始化各PC的值
    {
        PC[i].wantsend=0;
        PC[i].watch=0;
        PC[i].back_number=0;
    }
    PC[0].station=1;//初始化各个主机的位置
    PC[1].station=16;
    PC[2].station=2;
    PC[3].station=5;
    PC[4].station=7;
    PC[5].station=12;
    for(int i=0;i<16;i++) Bus[i]=0;
    confirm_flag = false;
    start_flag = false;
    stop_flag = true;
    count = 0;
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimeout()));
    sendTimer = new QTimer(this);
    connect(sendTimer, SIGNAL(timeout()), this, SLOT(onSendTimeout()));
}

void CellWidget::refresh()
{
    Pos1->setText(QString::number(Bus[0],10));
    Pos2->setText(QString::number(Bus[1],10));
    Pos3->setText(QString::number(Bus[2],10));
    Pos4->setText(QString::number(Bus[3],10));
    Pos5->setText(QString::number(Bus[4],10));
    Pos6->setText(QString::number(Bus[5],10));
    Pos7->setText(QString::number(Bus[6],10));
    Pos8->setText(QString::number(Bus[7],10));
    Pos9->setText(QString::number(Bus[8],10));
    Pos10->setText(QString::number(Bus[9],10));
    Pos11->setText(QString::number(Bus[10],10));
    Pos12->setText(QString::number(Bus[11],10));
    Pos13->setText(QString::number(Bus[12],10));
    Pos14->setText(QString::number(Bus[13],10));
    Pos15->setText(QString::number(Bus[14],10));
    Pos16->setText(QString::number(Bus[15],10));

    Pos1->setAlignment(Qt::AlignHCenter);
    Pos2->setAlignment(Qt::AlignHCenter);
    Pos3->setAlignment(Qt::AlignHCenter);
    Pos4->setAlignment(Qt::AlignHCenter);
    Pos5->setAlignment(Qt::AlignHCenter);
    Pos6->setAlignment(Qt::AlignHCenter);
    Pos7->setAlignment(Qt::AlignHCenter);
    Pos8->setAlignment(Qt::AlignHCenter);
    Pos9->setAlignment(Qt::AlignHCenter);
    Pos10->setAlignment(Qt::AlignHCenter);
    Pos11->setAlignment(Qt::AlignHCenter);
    Pos12->setAlignment(Qt::AlignHCenter);
    Pos13->setAlignment(Qt::AlignHCenter);
    Pos14->setAlignment(Qt::AlignHCenter);
    Pos15->setAlignment(Qt::AlignHCenter);
    Pos16->setAlignment(Qt::AlignHCenter);

    QString Bcolor[16];
    for(int i=0;i<16;i++)
    {
        if(Bus[i]>0)
            Bcolor[i] = "color:red;font-weight:bold;font-style:normal";
    }


    Pos1->setStyleSheet(Bcolor[0]);
    Pos2->setStyleSheet(Bcolor[1]);
    Pos3->setStyleSheet(Bcolor[2]);
    Pos4->setStyleSheet(Bcolor[3]);
    Pos5->setStyleSheet(Bcolor[4]);
    Pos6->setStyleSheet(Bcolor[5]);
    Pos7->setStyleSheet(Bcolor[6]);
    Pos8->setStyleSheet(Bcolor[7]);
    Pos9->setStyleSheet(Bcolor[8]);
    Pos10->setStyleSheet(Bcolor[9]);
    Pos11->setStyleSheet(Bcolor[10]);
    Pos12->setStyleSheet(Bcolor[11]);
    Pos13->setStyleSheet(Bcolor[12]);
    Pos14->setStyleSheet(Bcolor[13]);
    Pos15->setStyleSheet(Bcolor[14]);
    Pos16->setStyleSheet(Bcolor[15]);

    PC1->setText(QString::number(PC[0].package_number,10));
    PC2->setText(QString::number(PC[1].package_number,10));
    PC3->setText(QString::number(PC[2].package_number,10));
    PC4->setText(QString::number(PC[3].package_number,10));
    PC5->setText(QString::number(PC[4].package_number,10));
    PC6->setText(QString::number(PC[5].package_number,10));

    PC1->setStyleSheet("color:red;font-weight:bold;font-style:normal;");
    PC2->setStyleSheet("color:red;font-weight:bold;font-style:normal;");
    PC3->setStyleSheet("color:red;font-weight:bold;font-style:normal;");
    PC4->setStyleSheet("color:red;font-weight:bold;font-style:normal;");
    PC5->setStyleSheet("color:red;font-weight:bold;font-style:normal;");
    PC6->setStyleSheet("color:red;font-weight:bold;font-style:normal;");
    
    PC1->setAlignment(Qt::AlignHCenter);
    PC2->setAlignment(Qt::AlignHCenter);
    PC3->setAlignment(Qt::AlignHCenter);
    PC4->setAlignment(Qt::AlignHCenter);
    PC5->setAlignment(Qt::AlignHCenter);
    PC6->setAlignment(Qt::AlignHCenter);

}

void CellWidget::refresh_state()
{
    QString str[6];
    QString style[6];
    for(int i=0;i<6;i++)
    {
        if(PC[i].package_number<=0) 
        {
            str[i] = "停止";
            style[i] = "color:#FF0000";
        }
        else if(PC[i].wantsend == 1)
        {
            str[i] = "发送";
            style[i] = "color:#008800";
        }
        else
        {
            str[i] = "等待";
            style[i] = "color:#000099";
        }
    }

    info1->setText(str[0]);
    info1->setStyleSheet(style[0]);
    info2->setText(str[1]);
    info2->setStyleSheet(style[1]);
    info3->setText(str[2]);
    info3->setStyleSheet(style[2]);
    info4->setText(str[3]);
    info4->setStyleSheet(style[3]);
    info5->setText(str[4]);
    info5->setStyleSheet(style[4]);
    info6->setText(str[5]);
    info6->setStyleSheet(style[5]);

    info1->setAlignment(Qt::AlignHCenter);
    info2->setAlignment(Qt::AlignHCenter);
    info3->setAlignment(Qt::AlignHCenter);
    info4->setAlignment(Qt::AlignHCenter);
    info5->setAlignment(Qt::AlignHCenter);
    info6->setAlignment(Qt::AlignHCenter);
}

void CellWidget::check_conflict()//检测是否冲突
{
    int send=0;
    int can_send=0;
    for(int i=0;i<6;i++)//wantsend为1表示正在发送数据包，wantsend为0表示想要发送数据包（使用watch进行检测），wantsend<0表示处于回退中
    {
        if(PC[i].wantsend==1)//有主机正在发送数据包 
            send=1;
        if(PC[i].wantsend==0 && PC[i].watch==6)//可以发送数据包的主机的数目（想要发送数据包，并且已经监听了96比特时间信道空闲）
            can_send++;
    }
    if(can_send>1)//冲突 可以发送数据包的主机数目>1
    {
        displayEdit->append(QString("------发生冲突------\n"));
        srand((unsigned)time(NULL));
        for(int i=0;i<6;i++)
        {
            if(PC[i].wantsend==0 && PC[i].watch==6)//有哪些主机产生了冲突
            {             
                displayEdit->append("【主机"+QString::number(i+1,10)+QString("】检测到冲突，回退了"));
                int answer = pow(2,PC[i].back_number)+1;//0-2^n-1 回退时间的计算
                int back_length=rand()%answer;//0-2^n-1之间随机数回退
                int back=back_length*32;//转化为16时间槽单位表示
                PC[i].back_number++;//回退次数的计算，与answer的计算有关
                PC[i].wantsend-=back;//回退
                PC[i].watch=0;
                displayEdit->append(QString::number(back_length,10)+"    *512比特时间\n");
            }
        }
    }
    if(can_send==1)//只有一个主机可以发送数据，（这台主机想要发送数据包，并且已经监听了96比特时间信道空闲）
    {
        for(int i=0;i<6;i++)
        {
            if(PC[i].wantsend==0 && PC[i].watch==6)
                PC[i].wantsend=1;//wantsend置为1表示正在发送数据包
        }
    }       
    if(send==1)//有主机占用信道
    {
        for(int i=0;i<6;i++)
        {
            PC[i].watch=0;//有主机占用信道，那么其余主机的持续监听置为0
        }
    }
    //displayEdit->append(QString("test:发生冲突------\n")+QString::number(1,10)+"\n"+"2");    
}

void CellWidget::send_update()//刷新函数，虚拟自设时钟
{
    for(int i=0;i<6;i++)
    {
        if(PC[i].wantsend!=1 && PC[i].package_number>0)//对不是正在发送数据包的主机进行刷新
        {
            if(PC[i].wantsend==0&&PC[i].watch<6)//想要发送数据包但还未满足检测到96比特时间空闲
                PC[i].watch++;//监听时间+1
            if(PC[i].wantsend<0)//处于回退状态，回退时间+1
                PC[i].wantsend++;
        }
        refresh_state();
    }   

}

void CellWidget::sending_update()
{
    for(int i=0;i<6;i++)
    {
        if(PC[i].wantsend!=1)//对不是正在发送数据包的主机进行刷新
        {
            if(PC[i].wantsend==0&&PC[i].watch<=6)//想要发送数据包但还未满足检测到96比特时间空闲
                PC[i].watch=0;//有主机发送数据，监听重置
            if(PC[i].wantsend<0)//处于回退状态，回退时间+1
                PC[i].wantsend++;
        }   
    }
}

void CellWidget::sending(int send_number)//发送数据包的主机函数，内含时钟刷新
{
    if(timer->isActive())
        timer->stop();
    displayEdit->append(QString("-----主机")+QString::number(send_number+1,10)+"开始发送-----");
    Bus[PC[send_number].station-1] = send_number+1;
    sendTimer->start(500);    
}

void CellWidget::onSendTimeout()
{
    if(sendTime>36)
    {
        sendTime = 0;
        if(sendTimer->isActive()) sendTimer->stop();
        PC[sender].package_number--;//发送的数据包数量
        PC[sender].watch=0;//检测重置
        PC[sender].wantsend = (PC[sender].package_number>0)?0:2;
        //数据包发送标志，=1表示正在发送数据包，=0表示想要发送数据包 并正在进行96比特时间的空闲监听，<0表示处于回退状态中
        PC[sender].back_number = 0;//回退次数
       
        for(int i=0;i<16;i++)//重置总线
            Bus[i]=0;
        displayEdit->append(QString("-----主机")+QString::number(sender+1,10)+"发送完毕-----");
        timer->start(500);
        return;
    } 
    sending_update();//其他不能发送数据包主机进行刷新
    for(int pos=0;pos<15;pos++)
    {
        if(Bus[pos]==0 && Bus[pos+1]==sender+1)
            Bus[pos] = sender+1;
    }
    for(int pos=15;pos>0;pos--)
    {
        if(Bus[pos]==0 && Bus[pos-1]==sender+1)
            Bus[pos] = sender+1;
    }
    refresh();
    refresh_state();
    count++;
    sendTime++;
    displayEdit->append(QString("时间为：")+QString::number(count*16,10)+"（比特时间）");//自设时钟，当前时间   
}

void CellWidget::start_clicked()
{    
    if(!confirm_flag)
    {
        displayEdit->append(QString("【请先确认每台主机的数据包数量】\n"));
        return;
    }
    if(start_flag && !stop_flag)
    {
        displayEdit->append(QString("【请勿重复开始】\n"));
        return;
    }
    start_flag = true;
    stop_flag = false;
    if(sendTime>0)
    {
        sendTimer->start(500);
        displayEdit->append(QString("-----主机")+QString::number(sender+1,10)+"恢复发送-----");   
        return;
    }
    displayEdit->append(QString("-------仿真开始-------\n"));
    timer->start(500);   
}

void CellWidget::pause_clicked()
{    
    displayEdit->append(QString("-------仿真暂停-------\n"));
    if(timer->isActive())
        timer->stop(); 
    if(sendTimer->isActive())
        sendTimer->stop();
    stop_flag = true;  
}


void CellWidget::onTimeout()
{
    refresh();
    refresh_state();
    int stopNum = 0;
    for(int i=0;i<6;i++)
        if(PC[i].package_number<=0)
            stopNum++;
    if(stopNum==6)
    {
        if(timer->isActive())
            timer->stop();
        displayEdit->append(QString("-------仿真结束-------\n"));//自设时钟，当前时间
        return;
    }          
    if(stop_flag)
    {
        if(timer->isActive())
            timer->stop();
        return;
    }   
    displayEdit->append(QString("时间为：")+QString::number(count*16,10)+"（比特时间）");//自设时钟，当前时间
    int send=0;
    int can_send=0;
    int sending_number;
    for(int j=0;j<6;j++)
    {
        if(PC[j].wantsend==1 && PC[j].package_number>0)//wantsend为1表示主机正在发送数据包
        {
            send=1;//有主机发送数据包标志
            sending_number=j;//正在发送数据包的主机号
        }
        if(PC[j].wantsend==0 && PC[j].watch==6)//有主机想要发送数据包并且已经监听了96比特时间
            can_send=1;
    }   
    if(send==1)//有主机发送数据包
    {
        sending(sending_number);//返回发送时间
        sender = sending_number;
    }
    else//无主机发送数据包
    {
        if(can_send==1)//有可以发送数据包的主机，要进行冲突检测
            check_conflict();
        send_update();//时钟刷新
    }
    count++;
    refresh();
    refresh_state();
}


void CellWidget::confirm_clicked()
{
    PC1->setReadOnly(true);
    PC2->setReadOnly(true);
    PC3->setReadOnly(true);
    PC4->setReadOnly(true);
    PC5->setReadOnly(true);
    PC6->setReadOnly(true);
    confirm_flag = true;
    displayEdit->append(QString("【数据包数量已经锁定，可以开始仿真】\n"));
    refresh();
    refresh_state();
}

void CellWidget::PC1_add()
{
    if(confirm_flag) return;
    PC[0].package_number++;
    PC1->setText(QString::number(PC[0].package_number,10));
    PC1->setStyleSheet("color:red;font-weight:bold;font-style:normal;");
    PC1->setAlignment(Qt::AlignHCenter);
}
void CellWidget::PC1_minus()
{
    if(confirm_flag) return;
    PC[0].package_number--;
    PC[0].package_number = (PC[0].package_number<0)?0:PC[0].package_number;
    PC1->setText(QString::number(PC[0].package_number,10));
    PC1->setStyleSheet("color:red;font-weight:bold;font-style:normal;");
    PC1->setAlignment(Qt::AlignHCenter);
}
void CellWidget::PC2_add()
{
    if(confirm_flag) return;
    PC[1].package_number++;
    PC2->setText(QString::number(PC[1].package_number,10));
    PC2->setStyleSheet("color:red;font-weight:bold;font-style:normal;");
    PC2->setAlignment(Qt::AlignHCenter);
}
void CellWidget::PC2_minus()
{
    if(confirm_flag) return;
    PC[1].package_number--;
    PC[1].package_number = (PC[1].package_number<0)?0:PC[1].package_number;
    PC2->setText(QString::number(PC[1].package_number,10));
    PC2->setStyleSheet("color:red;font-weight:bold;font-style:normal;");
    PC2->setAlignment(Qt::AlignHCenter);
}
void CellWidget::PC3_add()
{
    if(confirm_flag) return;
    PC[2].package_number++;
    PC3->setText(QString::number(PC[2].package_number,10));
    PC3->setStyleSheet("color:red;font-weight:bold;font-style:normal;");
    PC3->setAlignment(Qt::AlignHCenter);
}
void CellWidget::PC3_minus()
{
    if(confirm_flag) return;
    PC[2].package_number--;
    PC[2].package_number = (PC[2].package_number<0)?0:PC[2].package_number;
    PC3->setText(QString::number(PC[2].package_number,10));
    PC3->setStyleSheet("color:red;font-weight:bold;font-style:normal;");
    PC3->setAlignment(Qt::AlignHCenter);
}
void CellWidget::PC4_add()
{
    if(confirm_flag) return;
    PC[3].package_number++;
    PC4->setText(QString::number(PC[3].package_number,10));
    PC4->setStyleSheet("color:red;font-weight:bold;font-style:normal;");
    PC4->setAlignment(Qt::AlignHCenter);
}
void CellWidget::PC4_minus()
{
    if(confirm_flag) return;
    PC[3].package_number--;
    PC[3].package_number = (PC[3].package_number<0)?0:PC[3].package_number;
    PC4->setText(QString::number(PC[3].package_number,10));
    PC4->setStyleSheet("color:red;font-weight:bold;font-style:normal;");
    PC4->setAlignment(Qt::AlignHCenter);
}
void CellWidget::PC5_add()
{
    if(confirm_flag) return;
    PC[4].package_number++;
    PC5->setText(QString::number(PC[4].package_number,10));
    PC5->setStyleSheet("color:red;font-weight:bold;font-style:normal;");
    PC5->setAlignment(Qt::AlignHCenter);
}
void CellWidget::PC5_minus()
{
    if(confirm_flag) return;
    PC[4].package_number--;
    PC[4].package_number = (PC[4].package_number<0)?0:PC[4].package_number;
    PC5->setText(QString::number(PC[4].package_number,10));
    PC5->setStyleSheet("color:red;font-weight:bold;font-style:normal;");
    PC5->setAlignment(Qt::AlignHCenter);
}
void CellWidget::PC6_add()
{
    if(confirm_flag) return;
    PC[5].package_number++;
    PC6->setText(QString::number(PC[5].package_number,10));
    PC6->setStyleSheet("color:red;font-weight:bold;font-style:normal;");
    PC6->setAlignment(Qt::AlignHCenter);
}
void CellWidget::PC6_minus()
{
    if(confirm_flag) return;
    PC[5].package_number--;
    PC[5].package_number = (PC[5].package_number<0)?0:PC[5].package_number;
    PC6->setText(QString::number(PC[5].package_number,10));
    PC6->setStyleSheet("color:red;font-weight:bold;font-style:normal;");
    PC6->setAlignment(Qt::AlignHCenter);
}