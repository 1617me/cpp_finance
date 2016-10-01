#ifndef CLIENTAPP_H
#define CLIENTAPP_H

// container for GLOBAL resources

#include <QApplication>

// singleton
// qApp, QCoreApplication::instance()
#define CLIENT_APP  ((ClientApp*)qApp)

class ClientApp : public QApplication
{
    Q_OBJECT
public:
    explicit ClientApp(int &argc, char ** argv);

signals:

public slots:

public:
    void *context;     // container for sockets
};

#endif // CLIENTAPP_H
