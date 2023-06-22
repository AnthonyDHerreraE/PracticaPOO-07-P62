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
    ui->txtNombres->clear();
    ui->txtNombres->insert(m_cliente.nombres());
    ui->txtApellidos->clear();
    ui->txtApellidos->insert(m_cliente.apellidos());
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
    m_datos.guardarCliente(m_cliente);
    //borra todo
    m_cliente.reset();
    ui->txtEntrada->clear();
    ui->txtNombres->clear();
    ui->txtApellidos->clear();
    ui->txtCedula->clear();
    ui->txtDireccion->clear();
    ui->txtCiudad->clear();
    ui->txtTelefono->clear();
    ui->txtCorreo->clear();
    ui->lblguardado->setText("Cliente Registrado");
}

void MainWindow::on_btnLista_clicked()
{
    TxtSave *m_archivo = new TxtSave();
    m_archivo->setDatos(m_datos);
    m_archivo->setWindowModality(Qt::ApplicationModal);
    m_archivo->show();
}


void MainWindow::on_txtEntrada_textChanged()
{
    ui->lblguardado->setText("");
}

