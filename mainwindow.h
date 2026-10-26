#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void on_btnAjouter_clicked();

    void on_btnActualiser_clicked();

    void on_btnSupprimer_clicked();

    void on_btnModifier_clicked();

    void on_tableEnseignants_cellClicked(int row, int column);

private:
    Ui::MainWindow *ui;
    void initialiserBaseDeDonnees();
    void afficherEnseignants();
};
#endif // MAINWINDOW_H
