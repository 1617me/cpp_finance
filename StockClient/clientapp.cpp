#include "clientapp.h"
#include <zmq.h>

ClientApp::ClientApp(int & argc, char ** argv) :
    QApplication(argc,argv),context(zmq_ctx_new())
{
    Q_ASSERT(context);
}
