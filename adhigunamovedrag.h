#ifndef DRAGMOVECHARM_H
#define DRAGMOVECHARM_H

#include <QObject>
#include <QtWidgets/QLabel>
#include <QtWidgets/QDialog>
#include <QtWidgets/QtWidgets>
#include <QtWidgets/QTableWidget>
#include <QtWebKitWidgets/QtWebKitWidgets>

class DragMoveCharmPrivate;
class QWidget;

class DragMoveCharm: public QObject
{
    Q_OBJECT
public:
    DragMoveCharm(QObject *parent = 0);
    ~DragMoveCharm();
    void activateOn(QWidget *widget);
    void deactivateFrom(QWidget *widget);
    bool eventFilter(QObject *object, QEvent *event);

private:
    DragMoveCharmPrivate *d;
};

#endif // DRAGMOVECHARM_H
