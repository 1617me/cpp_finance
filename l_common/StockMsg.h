#ifndef __STOCKMSG_H__
#define __STOCKMSG_H__

#include <QtGlobal>

struct StockTick
{
    uint   StockCode;
    uint   TimeStamp;
    double LastPrice;
};
#endif
