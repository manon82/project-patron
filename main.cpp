#include <QApplication>
#include <QGraphicsView>
#include "PatronJupe.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    
    // Tes mesures personnelles
    // tourTaille;tourHanche;longueurJupe;
    Mesures mesMesures = {74.0, 100.0, 40.0}; 
    
    QGraphicsScene scene(0, 0, 400, 400);
    PatronJupe *maJupe = new PatronJupe(mesMesures);
    scene.addItem(maJupe);
    
    QGraphicsView view(&scene);
    view.show();
    return a.exec();
}