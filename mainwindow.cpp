#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include "updater.hpp"

#include <QLabel>
#include <QTimer>
#include <QMetaObject>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    u = new Updater(nullptr);

    worker.start();
    u->moveToThread(&worker);

    connect(u, &Updater::updateStuff, this, &MainWindow::onStuffUpdated);

}

MainWindow::~MainWindow()
{
    u->finished = true;
    worker.quit();
    worker.wait();
    u->deleteLater();
    delete ui;
}

void MainWindow::onStuffUpdated(string const& msg)
{
    ui->label->setText(QString::fromStdString(msg));
}

void MainWindow::on_pushButton_clicked()
{
//    QMetaObject::invokeMethod(u, "doStuff", Qt::QueuedConnection);
    QTimer::singleShot(0, u, &Updater::doStuff);
}
