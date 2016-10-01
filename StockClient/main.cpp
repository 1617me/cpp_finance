#include "mainwindow.h"
#include <QApplication>
#include "clientapp.h"

//limitation:the process of receving msg is controlled by timer
// NOT by the server-side publishing



int main(int argc, char *argv[])
{
    ClientApp a(argc, argv);

    // user athentication

    // lauch main window
    MainWindow w;
    w.show();

    // event loop
    return a.exec();
}
