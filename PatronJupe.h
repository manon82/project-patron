#include <QGraphicsPathItem>
#include "Mesures.h"

double echelle = 4;

class PatronJupe : public QGraphicsPathItem {
public:
    // On ajoute un type de pièce : 0 pour devant, 1 pour demi-dos
    PatronJupe(const Mesures &m, int typePiece, double decalageX) {
        QPainterPath path;
        
        // 1. Calculs
        // Le devant = tourHanche/2. Le demi-dos = tourHanche/4
        double largeur = (typePiece == 0) ? (m.tourHanche / 2.0) * echelle 
                                          : (m.tourHanche / 4.0) * echelle;
        double hauteur = m.longueurJupe * echelle;
        
        double offsetY = 100;

        // 2. Tracé
        path.addRect(decalageX, offsetY, largeur, hauteur);

        setPath(path);
        // Couleur différente pour mieux distinguer
        setBrush(typePiece == 0 ? Qt::cyan : Qt::lightGray);
    }
};