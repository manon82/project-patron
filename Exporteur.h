#include <QSvgGenerator> // Nouveau module
#include <QPainter>

class Exporteur {
public:
    static void exporterEnSVG(const std::vector<QPainterPath>& pieces, const QString& nomFichier) {
        QSvgGenerator generator;
        generator.setFileName(nomFichier);
        generator.setSize(QSize(800, 1000)); // Définit la taille globale du canevas
        generator.setViewBox(QRect(0, 0, 800, 1000));
        generator.setTitle("Mon Patron de Jupe");

        QPainter painter(&generator);
        for (const auto& path : pieces) {
            painter.drawPath(path);
        }
        painter.end();
    }
};