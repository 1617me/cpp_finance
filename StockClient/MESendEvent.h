#ifndef MESENDEVENT_H
#define MESENDEVENT_H


#include <QEvent>

class MESendEvent : public QEvent
{
public:
    MESendEvent(Type type);
};

#endif // MESENDEVENT_H
