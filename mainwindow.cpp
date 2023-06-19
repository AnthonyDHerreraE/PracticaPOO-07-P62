#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnEntrada_clicked()
{
    //entrada
    QString entrada = ui->txtEntrada->toPlainText();

    m_cliente.inDatos(entrada);

    //salida
    ui->txtNombre->clear();
    ui->txtNombre->insert(m_cliente.nombre());
    ui->txtCedula->clear();
    ui->txtCedula->insert(m_cliente.cedula());
    ui->txtDireccion->clear();
    ui->txtDireccion->insert(m_cliente.direccion());
    ui->txtCiudad->clear();
    ui->txtCiudad->insert(m_cliente.ciudad());
    ui->txtTelefono->clear();
    ui->txtTelefono->insert(m_cliente.telefono());
    ui->txtCorreo->clear();
    ui->txtCorreo->insert(m_cliente.correo());
}


void MainWindow::on_btnTerminar_clicked()
{
    m_cliente.reset();
    ui->txtEntrada->clear();
    ui->txtNombre->clear();
    ui->txtCedula->clear();
    ui->txtDireccion->clear();
    ui->txtCiudad->clear();
    ui->txtTelefono->clear();
    ui->txtCorreo->clear();
}

