#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "cliente.h"
#include "txtsave.h"
#include "archivo.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnEntrada_clicked();

    void on_btnTerminar_clicked();

    void on_btnLista_clicked();

    void on_txtEntrada_textChanged();



    void on_btnCancelar_clicked();

signals:


private:
    Ui::MainWindow *ui;
    Cliente m_cliente;
    Archivo m_datos;
};
#endif // MAINWINDOW_H
