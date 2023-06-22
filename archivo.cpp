#include "archivo.h"

Archivo::Archivo()
{
    leerArchivo();
}



void Archivo::leerArchivo()
{
    nombreArchivo.setFileName(":/Clientes.csv");
    nombreArchivo.open(QIODevice::Text | QIODevice::ReadWrite);
    if(!nombreArchivo.isOpen()){
        QMessageBox::critical(0,tr("Error"),nombreArchivo.errorString());
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

        /*nombreArchivo.flush();
        nombreArchivo.close();
*/
}
}

void Archivo::guardarCliente(Cliente &dato)
{
    //nombreArchivo.setFileName(":/uno.csv");
    if(nombreArchivo.isOpen()){
            qDebug()<<"Error...!"<<"ok\n";
           // return;
        }else{
        qDebug()<<"Error...!"<<"nook\n";
    }
    nombreArchivo.flush();
    nombreArchivo.close();
    //nombreArchivo.open(QIODevice::Text | QIODevice::WriteOnly);
    if(!nombreArchivo.isOpen()){
        qDebug()<<"Error...!"<<nombreArchivo.errorString()<<"\n";
        return;
    }
    io.setDevice(&nombreArchivo);

    io<<dato.nombres()<<";"<<dato.apellidos()<<";"<<dato.cedula()<<";"<<dato.direccion()<<";"<<dato.ciudad()<<";"<<dato.telefono()<<";"<<dato.correo()<<"\n";

    nombreArchivo.flush();
    nombreArchivo.close();
}


const QList<Cliente *> &Archivo::clientes()
{
    return m_clientes;
}

const QStringList &Archivo::lista()
{
    return m_lista;
}

