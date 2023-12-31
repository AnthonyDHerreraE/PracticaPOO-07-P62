#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>

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

    if(entrada.isEmpty())
        return;

    m_cliente.reset();
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
    //si cualquier dato falta no se puede guardar
    if(
            ui->txtNombres->text().isEmpty()||
            ui->txtApellidos->text().isEmpty()||
            ui->txtCedula->text().isEmpty()||
            ui->txtDireccion->text().isEmpty()||
            ui->txtCiudad->text().isEmpty()||
            ui->txtTelefono->text().isEmpty()||
            ui->txtCorreo->text().isEmpty()
            )
        return;

    m_cliente.reset();

    m_cliente.setNombres(ui->txtNombres->text());
    m_cliente.setApellidos(ui->txtApellidos->text());
    m_cliente.setCedula(ui->txtCedula->text());
    m_cliente.setDireccion(ui->txtDireccion->text());
    m_cliente.setCiudad(ui->txtCiudad->text());
    m_cliente.setTelefono(ui->txtTelefono->text());
    m_cliente.setCorreo(ui->txtCorreo->text());

    m_datos.guardarCliente(m_cliente);

    //borra todo
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





void MainWindow::on_btnCancelar_clicked()
{
    m_cliente.reset();
    ui->txtEntrada->clear();
    ui->txtNombres->clear();
    ui->txtApellidos->clear();
    ui->txtCedula->clear();
    ui->txtDireccion->clear();
    ui->txtCiudad->clear();
    ui->txtTelefono->clear();
    ui->txtCorreo->clear();
    ui->lblguardado->setText("Cancelado");
}

