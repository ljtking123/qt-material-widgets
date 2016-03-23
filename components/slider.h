#ifndef SLIDER_H
#define SLIDER_H

#include <QWidget>
#include <QPoint>

class Slider;

class Handle : public QWidget
{
    Q_OBJECT

public:
    explicit Handle(Slider *slider);
    ~Handle();

    inline QSize sizeHint() const { return QSize(16, 16); }

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private:
    Slider *const _slider;
    QPoint        _eventPos;
    QPoint        _offset;
};

class Slider : public QWidget
{
    Q_OBJECT

public:
    explicit Slider(QWidget *parent = 0);
    ~Slider();

    inline void setOrientation(Qt::Orientation orientation) { _orientation = orientation; }
    inline Qt::Orientation orientation() const { return _orientation; }

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);

private:
    Handle   *const _handle;
    Qt::Orientation _orientation;
};

#endif // SLIDER_H
