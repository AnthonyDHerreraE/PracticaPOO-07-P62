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
    QString ruta = ":/Clientes.csv";
    m_archivo->nombreArchivo.setFileName(ruta);
    m_archivo->nombreArchivo.open(QIODevice::Text | QIODevice::WriteOnly);
    if(!m_archivo->nombreArchivo.isOpen()){
        qDebug()<<"Error...!"<<m_archivo->nombreArchivo.errorString()<<"\n";
        return;
    }
    m_archivo->io.setDevice(&m_archivo->nombreArchivo);
    m_archivo->io<<m_cliente.nombres()<<";"<<m_cliente.apellidos()<<";"<<m_cliente.cedula()<<";"<<m_cliente.direccion()<<";"<<m_cliente.ciudad()<<";"<<m_cliente.telefono()<<";"<<m_cliente.correo()<<"\n";

    m_archivo->nombreArchivo.close();
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
    m_archivo->setWindowModality(Qt::ApplicationModal);
    m_archivo->show();
}


void MainWindow::on_txtEntrada_textChanged()
{
    ui->lblguardado->setText("");
}

