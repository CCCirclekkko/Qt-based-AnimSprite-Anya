#ifndef WIDGET_H
#define WIDGET_H

#include <QPaintEvent>
#include <QWidget>
#include <QRect>
#include <QMouseEvent>
#include <QMovie>

const QSize startPicSize(449,386);
const float picScale = 0.25;    //图片缩放比例
//const QRect rectWin(1345,887,startPicSize.width()*picScale,startPicSize.height()*picScale);
const QPoint startP(1345,887);
const int absorbDis = 70;
const int ScrWidth=1680, ScrHeight=981;     //有效屏幕尺寸

enum direction{TOP=1, BOTTOM=2, LEFT=3, RIGHT=4};

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    //Widget(QWidget *parent = 0, Qt::WFlags flags =Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint|Qt::Tool);//构造函数
    ~Widget();

    QImage pic,bottom,top,right,left;
    QMovie *startUp, *drag, *stand, *turn;

    bool isDragging=false, dragGifShown=false;

    int isByEdge();

    void paintEvent(QPaintEvent * event)    Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent * event)    Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent * event)    Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent * event)    Q_DECL_OVERRIDE;

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
