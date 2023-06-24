#include "archivo.h"

Archivo::Archivo()
{

    leerArchivoCSV();
}

void Archivo::leerArchivoCSV()
{
    m_clientes.clear();
    m_lista.clear();
    QFile nombreArchivo;
    QTextStream io;
    nombreArchivo.setFileName("Clientes.csv");
    nombreArchivo.open(QIODevice::Text | QIODevice::ReadOnly);
    if(!nombreArchivo.isOpen()){
        qDebug()<<"Error...!"<<nombreArchivo.errorString()<<"\n";
        return;
    };
    io.setDevice(&nombreArchivo);

    while(!io.atEnd()){
        QString datosLinea=io.readLine();
        QStringList datos=datosLinea.split(";");

        Cliente* actual = new Cliente();
        actual->setNombre(datos[0]+" "+datos[1]);
        actual->setCedula(datos[2]);
        actual->setDireccion(datos[3]);
        actual->setCiudad(datos[4]);
        actual->setTelefono(datos[5]);
        actual->setCorreo(datos[6]);

        m_clientes.push_back(actual);
        m_lista.push_back(actual->nombre());

    }
    nombreArchivo.flush();
    nombreArchivo.close();


}

void Archivo::guardarArchivoCSV()
{
    QFile nombreArchivo;
    QTextStream io;
    nombreArchivo.setFileName("Clientes.csv");
    nombreArchivo.open(QIODevice::Text | QIODevice::WriteOnly | QIODevice::Append);
    if(!nombreArchivo.isOpen()){
        QMessageBox::critical(0,tr("Error"),nombreArchivo.errorString());
        return;
    }
    io.setDevice(&nombreArchivo);


    io<<actual()->nombres()<<";"
     <<actual()->apellidos()<<";"
    <<actual()->cedula()<<";"
    <<actual()->direccion()<<";"
    <<actual()->ciudad()<<";"
    <<actual()->telefono()<<";"
    <<actual()->correo()<<"\n";


    nombreArchivo.flush();
    nombreArchivo.close();
    leerArchivoCSV();
}

void Archivo::guardarCliente(Cliente &dato)
{
    m_clientes.push_back(&dato);
    setActual(&dato);
    guardarArchivoCSV();
}


const QList<Cliente *> &Archivo::clientes()
{
    return m_clientes;
}

const QStringList &Archivo::lista()
{
    return m_lista;
}

Cliente *Archivo::actual() const
{
    return m_actual;
}

void Archivo::setActual(Cliente *newActual)
{
    m_actual = newActual;
}

