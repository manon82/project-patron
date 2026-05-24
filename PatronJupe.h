#include <QGraphicsPathItem>
#include "Mesures.h"

double echelle = 4;

class PatronJupe : public QGraphicsPathItem {
public:
    PatronJupe(const Mesures &m) {
        QPainterPath path;
        double largeurHanche = (m.tourHanche / 4.0) * echelle;
        double longueurJupe = m.longueurJupe * echelle;

        double offsetX = 100;
        double offsetY = 100;

        path.moveTo(offsetX, offsetY); 
        path.lineTo(offsetX + largeurHanche, offsetY);
        path.lineTo(offsetX + largeurHanche, offsetY + longueurJupe);
        path.lineTo(offsetX, offsetY + longueurJupe);
        path.lineTo(offsetX, offsetY);

        setPath(path);
        setBrush(Qt::cyan);
    }
};