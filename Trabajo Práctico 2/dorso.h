typedef struct
{
    char nombre[50];
    int edad;
    int dni;
    int flagEstado;
}ePersona;

int validarPositivo(int x);
void inicVec(ePersona vecPersona[], ePersona auxVecPersona[], int cantPersonas);
void cargarVecPersona(ePersona vecPersona[], int cantPersonas);
void eliminarVecPersona(ePersona vecPersona[], int cantPersonas);
void listarVecPersona(ePersona vecPersona[], int cantPersonas, int criterio);
void graficar(ePersona vecPersona[], int cantPersonas);
