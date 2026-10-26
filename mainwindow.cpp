#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>
#include <QTableWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initialiserBaseDeDonnees();
    afficherEnseignants();
}

MainWindow::~MainWindow()
{
    delete ui;
}
    void MainWindow::initialiserBaseDeDonnees()
    {
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("gestion_ecole.db");

        if (!db.open()) {
            QMessageBox::critical(this, "Erreur", "la base de données n'est pas accessible: " + db.lastError().text());
        } else {
            QSqlQuery query;
            query.exec("CREATE TABLE IF NOT EXISTS enseignant ("
                       "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                       "nom TEXT, "
                       "prenom TEXT, "
                       "email TEXT)");
        }
    }

    void MainWindow::afficherEnseignants()
    {
        ui->tableEnseignants->setRowCount(0);
        QSqlQuery query("SELECT id, nom, prenom, email FROM enseignant");

        int row = 0;
        while (query.next()) {
            ui->tableEnseignants->insertRow(row);
            ui->tableEnseignants->setItem(row, 0, new QTableWidgetItem(query.value(0).toString())); // ID
            ui->tableEnseignants->setItem(row, 1, new QTableWidgetItem(query.value(1).toString())); // Nom
            ui->tableEnseignants->setItem(row, 2, new QTableWidgetItem(query.value(2).toString())); // Prénom
            ui->tableEnseignants->setItem(row, 3, new QTableWidgetItem(query.value(3).toString())); // Email
            row++;
        }
    }


    void MainWindow::on_btnAjouter_clicked()
    {
        // 1. Récuperer le texte dans le champs (Line Edits)
        QString nom = ui->txtNom->text();
        QString prenom = ui->txtPrenom->text();
        QString email = ui->txtEmail->text();

        // 2. Vérifier s'il n'y a pas de champ vide
        if (nom.isEmpty() || prenom.isEmpty() || email.isEmpty()) {
            QMessageBox::warning(this, "Avertissement", "remplissez tous les champs (Nom, Prénom, Email)!");
            return;
        }

        // 3. Insérer les données dans SQLite
        QSqlQuery query;
        query.prepare("INSERT INTO enseignant (nom, prenom, email) VALUES (:nom, :prenom, :email)");
        query.bindValue(":nom", nom);
        query.bindValue(":prenom", prenom);
        query.bindValue(":email", email);

        // 4. Exécuter l'intension
        if (query.exec()) {
            QMessageBox::information(this, "Succès", "sauvegardé avec succès!");

            // Effacher tous les champs terminés
            ui->txtNom->clear();
            ui->txtPrenom->clear();
            ui->txtEmail->clear();

            // Actualiser le tableau pour afficher la nouvelle entrée que vous avez ajoutée
            afficherEnseignants();
        } else {
            QMessageBox::critical(this, "Erreur", "il'ya probleme: " + query.lastError().text());
        }
    }


    void MainWindow::on_btnActualiser_clicked()
    {

            afficherEnseignants(); // Actualiaser à nouveau le tableau
            ui->txtNom->clear();
            ui->txtPrenom->clear();
            ui->txtEmail->clear();
    }


    void MainWindow::on_btnSupprimer_clicked()
    {
            // Récuperer la ligne (row)sélectionnée dans le tableau
            int currentRow = ui->tableEnseignants->currentRow();

            // S'il n'y a rien de sélectionné (ou si le résultat est-1)
            if (currentRow == -1) {
                QMessageBox::warning(this, "Avertissement", "Sélectionner d'abord un enseignant dans le tableau avant de cliquer!");
                return;
            }

            // Récupérer l'ID de la personne sélectionnée
            int id = ui->tableEnseignants->item(currentRow, 0)->text().toInt();

            // Demande d'abord une confirmation
            QMessageBox::StandardButton reponse = QMessageBox::question(this, "confirmation",
                                                                        "Vous-vous vraiment supprimer cet enseignant ?",
                                                                        QMessageBox::Yes | QMessageBox::No);

            if (reponse == QMessageBox::Yes) {
                QSqlQuery query;
                query.prepare("DELETE FROM enseignant WHERE id = :id");
                query.bindValue(":id", id);

                if (query.exec()) {
                    QMessageBox::information(this, "Succès", "L'enseignant a été supprimé!");
                    afficherEnseignants(); // Actualiser le tableau
                } else {
                    QMessageBox::critical(this, "Erreur", "Non supprimer: " + query.lastError().text());
                }
         }
    }


    void MainWindow::on_btnModifier_clicked()
    {
        int currentRow = ui->tableEnseignants->currentRow();

        if (currentRow == -1) {
            QMessageBox::warning(this, "Avertissement", "Séléctionnez d'abord un enseignant dans le tableau!");
            return;
        }

        // Récuper l'ID
        int id = ui->tableEnseignants->item(currentRow, 0)->text().toInt();

        // Récuper le texte nouvellement saisi dans le champ
        QString nom = ui->txtNom->text();
        QString prenom = ui->txtPrenom->text();
        QString email = ui->txtEmail->text();

        if (nom.isEmpty() || prenom.isEmpty() || email.isEmpty()) {
            QMessageBox::warning(this, "Avertissement", "Remplissez tous les champs avant de cliquer sur modifier!");
            return;
        }

        // Modifier les données daans SQLite
        QSqlQuery query;
        query.prepare("UPDATE enseignant SET nom = :nom, prenom = :prenom, email = :email WHERE id = :id");
        query.bindValue(":nom", nom);
        query.bindValue(":prenom", prenom);
        query.bindValue(":email", email);
        query.bindValue(":id", id);

        if (query.exec()) {
            QMessageBox::information(this, "Succès", "Enregistré avec succès selon le contexte!");
            afficherEnseignants(); // Mettre à jour la table
            // Supprimer le champ
            ui->txtNom->clear();
            ui->txtPrenom->clear();
            ui->txtEmail->clear();
        } else {
            QMessageBox::critical(this, "Erreur", "non enregistré: " + query.lastError().text());
        }
    }


    void MainWindow::on_tableEnseignants_cellClicked(int row, int column)
    {
            // Récupérer le texte de la table et le placer dans le champ (Line Edit)
            ui->txtNom->setText(ui->tableEnseignants->item(row, 1)->text());
            ui->txtPrenom->setText(ui->tableEnseignants->item(row, 2)->text());
            ui->txtEmail->setText(ui->tableEnseignants->item(row, 3)->text());
    }

