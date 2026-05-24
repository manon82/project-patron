#include <QApplication>
#include <QGraphicsView>
#include "PatronJupe.h"
#include "Exporteur.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    
    // Tes mesures personnelles
    // tourTaille;tourHanche;longueurJupe;
    Mesures m = {74.0, 100.0, 40.0};

    // creation de scene 
    QGraphicsScene scene(0, 0, 400, 400);
    // Devant (type 0)
    PatronJupe *devant = new PatronJupe(m, 0, 50); 
    scene.addItem(devant);

    // Demi-dos 1 (type 1)
    PatronJupe *dos1 = new PatronJupe(m, 1, 300);
    scene.addItem(dos1);

    // Demi-dos 2 (type 1)
    PatronJupe *dos2 = new PatronJupe(m, 1, 450);
    scene.addItem(dos2);

    // Exporteur
    std::vector<QPainterPath> pieces;
    pieces.push_back(devant->path());
    pieces.push_back(dos1->path());
    pieces.push_back(dos2->path());

    Exporteur::exporterEnSVG(pieces, "mon_patron.svg");
    
    QGraphicsView view(&scene);
    view.show();
    return a.exec();
}