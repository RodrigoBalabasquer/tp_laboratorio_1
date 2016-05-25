typedef struct
{
    int Puntaje;
    char *Titulo;
    char *Genero;
    char *Descripcion;
    char *LinkImagen;
    int Duracion;
}ePelicula;

int validarString(char *palabra,int inf,int sup);
int validarRango(int x, int inf, int sup);
void CargarTitulo(char *titulo);
int BuscarTitulo(ePelicula*peli,int cant,char *titulo);
void CargarPelicula(ePelicula *peli);
void swapear(ePelicula *peliborrar,ePelicula *pelireubilar);
void ModificarPelicula(ePelicula *peli,int option,int indice);
void MostrarCarteleras(ePelicula *pelicula,int cant);
void MostrarPelicula(ePelicula *pelicula);
void GenerarPaginaWeb(ePelicula *pelicula,int cant);



