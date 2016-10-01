#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
 private:
    void  timerEvent(QTimerEvent *event);

private:
    Ui::MainWindow *ui;
    void * subscriber;
    int count;
};

#endif // MAINWINDOW_H
