#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <string>

#include <QMainWindow>
#include <QThread>

using namespace std;

namespace Ui {
class MainWindow;
}

class Updater;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void onStuffUpdated(string const&);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Updater* u;
    QThread worker;
};

#endif // MAINWINDOW_HPP
