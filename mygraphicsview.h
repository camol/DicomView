#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QGraphicsRectItem>

/**
* @page MyGraphicsView Class MyGraphicsView.
* Class which inheritates of QGraphicsView and reimplements few original methods to improve to functionality.
*/

class MyGraphicsView : public QGraphicsView
{
    Q_OBJECT;
public:

    /**
    * Constructor for MyGraphicsView Class.@n
    * Sets the QGraphcsView constructor.
    * @param QWidget*
    */
    MyGraphicsView(QWidget* parent = NULL);


    /**
    * Variable containing the difference between two points in X axis during mouse move.
    */
    int diffX;

    /**
    * Variable containing the difference between two points in Y axis during mouse move.
    */
    int diffY;


public:
    //Holds the current centerpoint for the view, used for panning and zooming
    QPointF CurrentCenterPoint;

    //From panning the view
    QPoint LastPanPoint;
    QPoint EventPos;


    /**
    * Sets the current centerpoint.  Also updates the scene's center point.
    * Unlike centerOn, which has no way of getting the floating point center
    * back, SetCenter() stores the center point.  It also handles the special
    * sidebar case.  This function will claim the centerPoint to sceneRec ie.
    * the centerPoint must be within the sceneRec.
    * @param const QPointF&
    * @return void
    */
    void SetCenter(const QPointF& centerPoint);


    QPointF GetCenter() { return CurrentCenterPoint; }

    //Take over the interaction


    /**
    * Handles when the mouse button is pressed
    * @param QMouseEvent*
    * @return void
    */
    virtual void mousePressEvent(QMouseEvent* event);


    /**
    * Handles when the mouse button is released
    * @param QMouseEvent*
    * @return void
    */
    virtual void mouseReleaseEvent(QMouseEvent* event);


    /**
    * Handles when the mouse is moved and stores iformations about movement in diffX and diffY.
    * @param QMouseEvent*
    * @return void
    */
    virtual void mouseMoveEvent(QMouseEvent* event);

    /**
    * Zoom the view in and out.
    * @param QMouseEvent*
    * @return void
    */
    virtual void wheelEvent(QWheelEvent* event);

};

#endif // MYGRAPHICSVIEW_H
