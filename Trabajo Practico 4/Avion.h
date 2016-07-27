typedef struct
{
    int id;
    char marca[50];
    char modelo[50];
    float hsVuelo;
    int capacidad;
    int flagEstado;
}eAvion;

int validarRangoInt(int x, int inf, int sup);
eAvion* nuevoAvion (int id, char marca[], char modelo[], float hsVuelo, int capacidad);
void imprimirAvion (eAvion* avion);
int compararAvion (void* avion1, void* avion2);

