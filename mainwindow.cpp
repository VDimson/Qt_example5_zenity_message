#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    z_process=new QProcess(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //z_process->start("/bin/bash");
    //z_process->start("/bin/sh -c \"ps -ef | grep Xorg\"");
    //z_process->start("/bin/sh -c \"pwd\"");
   // z_process->start("sh",QStringList()<<"-c"<<"pwd");
    z_process->start("sh");
    z_process->waitForStarted();
    QString disp_com="export DISPLAY='"+ui->lineEdit->text()+"'\n";

    const char* disp; //определяем символьную переменную
    //disp=disp_com.toStdString().allocator_type//перевод строки в символную переменную
    disp=disp_com.toLocal8Bit().data();
    z_process->write(disp);
     //z_process->write("export DISPLAY=':14'\n");
    //z_process->write("echo $DISPLAY");
    z_process->waitForBytesWritten();
    z_process->write("zenity --question --title='Внимание,сообщение!' --text='Просьбы выйти из системы!!!Вы согласны?'\n");
    z_process->closeWriteChannel();
    z_process->waitForFinished();
   //z_process->start("echo",QStringList()<<"$DISPLAY");

    //z_process->write("pwd");
    //z_process->write("export DISPLAY=:12");
    //z_process->waitForBytesWritten();
    //z_process->write("zenity --question --title='Внимание,сообщение!' --text='Просьбы выйти из системы!!!Вы согласны?'");
    //z_process->start("export",QStringList()<<"DISPLAY=:12");
    //z_process->start("zenity",QStringList()<<"--question"<<"--title='Внимание,сообщение!'"<<"--text='Просьбы выйти из системы!!!Вы согласны?'");
   //z_process->waitForReadyRead(1000);
    ui->statusBar->showMessage(QString::number(z_process->exitCode()));
  // ui->statusBar->showMessage(z_process->readAll());
    //z_process->write("export DISPLAY=:12");

}
