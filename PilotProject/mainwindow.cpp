#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSql>
#include <QtDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("qtest");
    db.setUserName("root");
    db.setPassword("rootpassword");
    if(!db.open()) qDebug() << "Failed to connect to root mysql admin";
//    model = new QSqlTableModel(this);
//    model->setTable("record");
//    model->select();
//    ui->tableView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}
