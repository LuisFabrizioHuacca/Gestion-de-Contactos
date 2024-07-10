#include <iostream>
#include <cstring>

using namespace std;

struct ContactoEmail {
    char nombresCompletos[100];
    char sexo;
    int edad;
    char telefono[20];
    char email[50];
    char nacionalidad[50];
};

void agregarContacto(ContactoEmail contactos[], int &numContactos) {
    ContactoEmail nuevoContacto;

    cout << "Ingrese nombres completos: ";
    cin.ignore();
    cin.getline(nuevoContacto.nombresCompletos, 100);

    cout << "Ingrese sexo (M/F): ";
    cin >> nuevoContacto.sexo;
    
    cout << "Ingrese edad: ";
    cin >> nuevoContacto.edad;
    cin.ignore(); 
    
    cout << "Ingrese telefono: ";
    cin.getline(nuevoContacto.telefono, 20);
    
    cout << "Ingrese email: ";
    cin.getline(nuevoContacto.email, 50);
    
    cout << "Ingrese nacionalidad: ";
    cin.getline(nuevoContacto.nacionalidad, 50);

    contactos[numContactos] = nuevoContacto;
    numContactos++;
    cout << "Contacto agregado exitosamente.\n";
}

void eliminarContacto(ContactoEmail contactos[], int &numContactos) {
    if (numContactos == 0) {
        cout << "No hay contactos para eliminar.\n";
        return;
    }

    int indice;
    cout << "Ingrese el indice del contacto a eliminar (0 a " << numContactos - 1 << "): ";
    cin >> indice;

    if (indice < 0 || indice >= numContactos) {
        cout << "Índice inválido.\n";
        return;
    }

    for (int i = indice; i < numContactos - 1; i++) {
        contactos[i] = contactos[i + 1];
    }
    numContactos--;
    cout << "Contacto eliminado exitosamente.\n";
}

void mostrarContactos(const ContactoEmail contactos[], int numContactos) {
    if (numContactos == 0) {
        cout << "No hay contactos para mostrar.\n";
        return;
    }

    for (int i = 0; i < numContactos; i++) {
        cout << "Contacto #" << i << ":\n";
        cout << "Nombres Completos: " << contactos[i].nombresCompletos << endl;
        cout << "Sexo: " << contactos[i].sexo << endl;
        cout << "Edad: " << contactos[i].edad << endl;
        cout << "Teléfono: " << contactos[i].telefono << endl;
        cout << "Email: " << contactos[i].email << endl;
        cout << "Nacionalidad: " << contactos[i].nacionalidad << endl;
        cout << "--------------------------\n";
    }
}

void mostrarContactosOrdenadosPorDominio(ContactoEmail contactos[], int numContactos) {
    if (numContactos == 0) {
        cout << "No hay contactos para mostrar.\n";
        return;
    }

    for (int i = 0; i < numContactos - 1; i++) {
        for (int j = i + 1; j < numContactos; j++) {
            char *dominioA = strchr(contactos[i].email, '@');
            char *dominioB = strchr(contactos[j].email, '@');

            if (dominioA && dominioB) {
                if (strcmp(dominioA, dominioB) > 0) {
                    ContactoEmail temp = contactos[i];
                    contactos[i] = contactos[j];
                    contactos[j] = temp;
                }
            }
        }
    }

    mostrarContactos(contactos, numContactos);
}




int main() {
    ContactoEmail contactos[100]; 
    int numContactos = 0;
    int opcion;

    do {
        cout << "\nGestion de Contactos\n";
        cout << "1. Agregar un contacto\n";
        cout << "2. Eliminar un contacto\n";
        cout << "3. Mostrar listado general de contactos\n";
        cout << "4. Mostrar listado de contactos ordenado por servidor de correo\n";
        cout << "5. Salir\n";
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                agregarContacto(contactos, numContactos);
                break;
            case 2:
                eliminarContacto(contactos, numContactos);
				break;    
			 case 3:
                mostrarContactos(contactos, numContactos);
                break;	
            case 4:
                mostrarContactosOrdenadosPorDominio(contactos, numContactos);
                break;  
			case 5:
                cout << "Saliendo del programa...\n";
                break;		  
            default:
                cout << "Opcion no valida. Intente de nuevo.\n";
                break;
        }
    } while(opcion != 5);

    return 0;
}

