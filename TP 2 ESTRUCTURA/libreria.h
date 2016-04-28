typedef struct
{
    int edad, estado;
    char nombre[25];
    char DNI[50];

} ePersonas;

int validarRango(int x, int inf, int sup);
void Inicializar(ePersonas vec[],int cant);
int ObtenerLugar(ePersonas vec[],int cant);
int BuscarLugar(ePersonas vec[],int cant);
void CargarDNI(char DNI[]);
int BuscarxDNI(ePersonas vec[],int cant,char DNI[]);
ePersonas cargarPersona(void);
void mostrarListaPersonas(ePersonas vec[],int cant);
void mostrarPersona(ePersonas UnaPersona);
void ordenarPersona(ePersonas Persona[],int cant);
int ContarPersonas(ePersonas vec[],int cant, int inf, int sup);
void GraficarPersonas(int A, int B, int C);
