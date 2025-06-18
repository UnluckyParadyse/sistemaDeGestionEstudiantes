#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include <algorithm>
#include <fstream>
#include <exception>

using namespace std;

// Asignatura
class Asignatura
{
private:
    string nombre;
    float nota;
    int anno;
    int semestre;

public:
    Asignatura(string, float, int, int);
    void mostrar();
    string getNombre();
    float getNota();
    int getAnno();
    int getSemestre();
};
Asignatura::Asignatura(string _nombre, float _nota, int _anno, int _semestre)
{
    nombre = _nombre;
    nota = _nota;
    anno = _anno;
    semestre = _semestre;
}
void Asignatura::mostrar()
{
    cout << "Asignatura: " << nombre << endl;
    cout << "Nota: " << nota << endl;
    cout << "Año: " << anno << endl;
    cout << "Semestre: " << semestre << endl;
}
float Asignatura::getNota()
{
    return nota;
};
int Asignatura::getAnno()
{
    return anno;
};
int Asignatura::getSemestre()
{
    return semestre;
}
string Asignatura::getNombre()
{
    return nombre;
}

// Estudiante
class Estudiante
{
private:
    string nombre;
    string apellidos;
    string CI;
    float estipendio;
    int annoCurso;
    int grupo;
    bool isProyecto;
    string proyecto;

    vector<Asignatura> asignaturas;

    string clase;

public:
    Estudiante(string, string, string, float, int, int, bool, string, vector<Asignatura> _asignaturas, string);
    virtual void calcularEstipendio();
    virtual void mostrar();
    vector<Asignatura> getAsignaturas();
    string getNombre();
    string getApellidos();
    string getCI();
    float getEstipendio();

    int getAnnoCurso();
    int getGrupo();
    bool getiIsProyecto();
    string getProyecto();
    string getClase();
};
Estudiante::Estudiante(string _nombre, string _apellidos, string _CI, float _estipendio, int _annoCurso, int _grupo, bool _isProyecto, string _proyecto, vector<Asignatura> _asignaturas, string _clase)
{
    nombre = _nombre;
    apellidos = _apellidos;
    CI = _CI;
    estipendio = _estipendio;
    annoCurso = _annoCurso;
    grupo = _grupo;
    isProyecto = _isProyecto;
    proyecto = _proyecto;
    asignaturas = _asignaturas;
    clase = _clase;
};
void Estudiante::calcularEstipendio()
{
    float estipendio, estipendioFijo, ayudaFinanciera;
    estipendio = estipendioFijo + ayudaFinanciera;
}
void Estudiante::mostrar()
{
    cout << "Nombre: " << nombre << endl;
    cout << "Apellidos: " << apellidos << endl;
    cout << "CI: " << CI << endl;
    cout << "Estipendio: " << estipendio << endl;
    cout << "Año de curso: " << annoCurso << endl;
    cout << "Grupo: " << grupo << endl;
    cout << "Proyecto: " << (isProyecto ? proyecto : "No tiene proyecto") << endl;
    cout << "\n";
    cout << "Asignaturas: " << endl;
    cout << " Tipo: " << clase << endl;

    for (int i = 0; i < asignaturas.size(); i++) // al parecer esto va con ++i
    {
        asignaturas[i].mostrar();
    };
}
string Estudiante::getCI()
{
    return CI;
}
vector<Asignatura> Estudiante::getAsignaturas()
{
    return asignaturas;
}
string Estudiante::getNombre()
{
    return nombre;
}
string Estudiante::getApellidos()
{
    return apellidos;
}
float Estudiante::getEstipendio()
{
    return estipendio;
}
int Estudiante::getAnnoCurso()
{
    return annoCurso;
}
int Estudiante::getGrupo()
{
    return grupo;
}
bool Estudiante::getiIsProyecto()
{
    return isProyecto;
}
string Estudiante::getProyecto()
{
    return proyecto;
}
string Estudiante::getClase()
{
    return clase;
}

// EstudianteAyudante
class EstudianteAyudante : public Estudiante
{
private:
    int annosAyudantia;
    vector<Asignatura> asignaturasImpartidas;

public:
    EstudianteAyudante(string, string, string, float, int, int, bool, string, vector<Asignatura>, string, int, vector<Asignatura>);
    void calcularEstipendio() override;
    void mostrar() override;
    string getCI(); /// esto puede dar bateo porque si
    int getAnnosAyudantia();
    vector<Asignatura> getAsignaturasImpartidas();
};
EstudianteAyudante::EstudianteAyudante(string _nombre, string _apellidos, string _CI, float _estipendio, int _annoCurso, int _grupo, bool _isProyecto, string _proyecto, vector<Asignatura> _asignaturas, string _clase, int _annosAyudantia, vector<Asignatura> _asignaturasImpartidas)
    : Estudiante(_nombre, _apellidos, _CI, _estipendio, _annoCurso, _grupo, _isProyecto, _proyecto, _asignaturas, _clase)
{
    annosAyudantia = _annosAyudantia;
    asignaturasImpartidas = _asignaturasImpartidas;
}; // Esta funcion la hizo chatgpt, cuidado
void EstudianteAyudante::calcularEstipendio()
{

    float estipendio, estipendioFijo, ayudaFinanciera;

    estipendio = estipendioFijo + ayudaFinanciera + 50; // Tengo dudas en esto, preguntarle a la profesora luego
}
void EstudianteAyudante::mostrar()
{
    Estudiante::mostrar();
    cout << "\n";
    cout << "Años de ayudantía: " << annosAyudantia << endl;
    cout << "Asignaturas impartidas: " << endl;
    for (int i = 0; i < asignaturasImpartidas.size(); i++)
    {
        asignaturasImpartidas[i].mostrar();
    }
};
int EstudianteAyudante::getAnnosAyudantia()
{
    return annosAyudantia;
}
vector<Asignatura> EstudianteAyudante::getAsignaturasImpartidas()
{
    return asignaturasImpartidas;
}

// EstudianteLicenciaEspecial
class EstudianteLicenciaEspecial : public Estudiante
{
private:
    string asignaturaRepetida;
    int annoRepetido;

public:
    EstudianteLicenciaEspecial(string, string, string, float, int, int, bool, string, vector<Asignatura>, string, string, int);
    void calcularEstipendio() override;
    void mostrar() override;
    string getCI(); // esto puede dar bateo porque si
    string getAsignaturaRepetida() { return asignaturaRepetida; }
    int getAnnoRepetido() { return annoRepetido; }
};
EstudianteLicenciaEspecial::EstudianteLicenciaEspecial(string _nombre, string _apellidos, string _CI, float _estipendio, int _annoCurso, int _grupo, bool _isProyecto, string _proyecto, vector<Asignatura> _asignaturas, string _clase, string _asignaturaRepetida, int _annoRepetido)
    : Estudiante(_nombre, _apellidos, _CI, _estipendio, _annoCurso, _grupo, _isProyecto, _proyecto, _asignaturas, _clase)
{
    asignaturaRepetida = _asignaturaRepetida;
    annoRepetido = _annoRepetido;
}; // Esta funcion la hizo chatgpt, cuidado
void EstudianteLicenciaEspecial::calcularEstipendio()
{
    Estudiante::calcularEstipendio();
};
void EstudianteLicenciaEspecial::mostrar()
{
    Estudiante::mostrar();
    cout << "\n";
    cout << "Asignatura repetida: " << asignaturaRepetida << endl;
    cout << "Año repetido: " << annoRepetido << endl;
};

// Agrupacion
class Agrupacion
{
private:
    vector<Estudiante> estudiantes;

public:
    Agrupacion(const vector<Estudiante> &);
    void mostrar();
};
Agrupacion::Agrupacion(const vector<Estudiante> &_estudiantes)
{
    estudiantes = _estudiantes;
};
void Agrupacion::mostrar()
{
    cout << "Estudiantes en la agrupación:";
    for (int i = 0; i < estudiantes.size(); i++)
    {
        estudiantes[i].mostrar();
        cout << "\n";
    }
};

// Validar CI
void validarCI(string CI, vector<Estudiante *> estudiantes)
{

    // validar que no haya otro con ese mismo CI
    string CIBuscando = CI;

    bool isEncontrado = false;

    for (int i = 0; i < estudiantes.size(); i++)
    {
        if (estudiantes[i]->getCI() == CIBuscando)
        {
            cout << "\n";
            throw runtime_error("CI INVALIDO, YA LO USA OTRO ESTUDIANTE");
            break;
        }
    }
}

// Mostrar Vector de Estudiantes
void mostrarEstudiantes(vector<Estudiante *> estudiantes)
{

    cout << "Lista de estudiantes en base de datos:" << endl;
    cout << "\n";
    for (int i = 0; i < estudiantes.size(); ++i)
    {
        cout << "Estudiante #" << (i + 1) << ":" << endl;
        estudiantes[i]->mostrar();
        cout << "\n";
    }
}

// Buscar Estudiante por CI
void buscarEstudiantePorCI(vector<Estudiante *> estudiantes)
{
    string CIBuscando;
    cout << "Ingrese el CI del estudiante que desea buscar: ";
    cin >> CIBuscando;

    bool encontrado = false;

    for (int i = 0; i < estudiantes.size(); i++)
    {
        if (estudiantes[i]->getCI() == CIBuscando)
        {
            cout << "Estudiante encontrado:" << endl;
            cout << "\n";
            estudiantes[i]->mostrar();
            encontrado = true;
            break;
        }
    }
    if (!encontrado)
    {
        cout << "No se encontró ningún estudiante con ese CI." << endl;
    }
}

// Promediar año
void promediarAnno(vector<Estudiante *> estudiantes)
{
    int anno;
    cout << "Ingrese el año que desea promediar: ";
    cin >> anno;

    if (cin.fail() || anno <= 0)
    {
        cout << "Error: año inválido. " << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    float sumaNotas = 0;
    int cantidadAsignaturas = 0;

    for (int i = 0; i < estudiantes.size(); ++i)
    {
        vector<Asignatura> asignaturas = estudiantes[i]->getAsignaturas();
        for (int j = 0; j < asignaturas.size(); ++j)
        {
            if (asignaturas[j].getAnno() == anno)
            {
                sumaNotas += asignaturas[j].getNota();
                cantidadAsignaturas++;
            }
        }
    }

    if (cantidadAsignaturas > 0)
    {
        float promedio = sumaNotas / cantidadAsignaturas;
        cout << "El promedio del año " << anno << " es: " << promedio << endl;
    }
    else
    {
        cout << "No hay asignaturas para el año " << anno << "." << endl;
    }
}

// REVISAR MAS TARDE
//  Buscar Estudiante por Nombre
void buscarEstudiantePorNombre(vector<Estudiante *> estudiantes)
{
    string nombreBuscando;
    cout << "Ingrese el nombre del estudiante que desea buscar: ";
    cin >> nombreBuscando;

    bool encontrado = false;

    for (int i = 0; i < estudiantes.size(); i++)
    {
        if (estudiantes[i]->getNombre() == nombreBuscando)
        {
            cout << "Estudiante encontrado:" << endl;
            cout << "\n";
            estudiantes[i]->mostrar();
            encontrado = true;
        }
    }
    if (!encontrado)
    {
        cout << "No se encontró ningún estudiante con ese nombre." << endl;
    }
};

// Listar estudiantes con promedio mayor a 4.75 (Titulo de oro)
void listarEstudiantesConPromedioMayorA4_75(vector<Estudiante *> estudiantes)
{
    bool isMayorA4_75 = false;
    cout << "Estudiantes con promedio mayor a 4.75:" << endl;
    for (int i = 0; i < estudiantes.size(); ++i)
    {
        vector<Asignatura> asignaturas = estudiantes[i]->getAsignaturas();
        float sumaNotas = 0;
        int cantidadAsignaturas = asignaturas.size();

        for (int j = 0; j < cantidadAsignaturas; ++j)
        {
            sumaNotas += asignaturas[j].getNota();
        }

        if (cantidadAsignaturas > 0)
        {
            float promedio = sumaNotas / cantidadAsignaturas;
            if (promedio > 4.75)
            {
                isMayorA4_75 = true;
                cout << "Estudiante: " << estudiantes[i]->getNombre() << ", Promedio: " << promedio << endl;
            }
        }
    }
    if (!isMayorA4_75)
    {
        cout << "No hay estudiantes con promedio mayor a 4.75." << endl;
    }
};

// Escalafon
void escalafon(vector<Estudiante *> estudiantes)
{
    vector<pair<string, float>> ranking;

    for (int i = 0; i < estudiantes.size(); i++)
    {
        vector<Asignatura> asignaturas = estudiantes[i]->getAsignaturas();
        float sumaNotas = 0;
        int cantidadAsignaturas = asignaturas.size();

        for (int j = 0; j < cantidadAsignaturas; ++j)
        {
            sumaNotas += asignaturas[j].getNota();
        }

        float promedio = (cantidadAsignaturas > 0) ? (sumaNotas / cantidadAsignaturas) : 0;
        ranking.push_back({estudiantes[i]->getNombre(), promedio});
    }

    // Ordenar de mayor a menor promedio
    sort(ranking.begin(), ranking.end(), [](const pair<string, float> &a, const pair<string, float> &b)
         { return a.second > b.second; });

    ofstream archivo("escalafon.txt");
    if (archivo.is_open())
    {

        archivo << "Escalafón de estudiantes: " << endl;

        for (const auto &par : ranking)
        {
            archivo << par.first << "-" << par.second << endl;
        }
        archivo.close();
        cout << "Escalafón guardado en escalafon.txt" << endl;
    }
    else
    {
        cout << "No se pudo crear el archivo escalafon.txt" << endl;
    }
}

// Exportar datos a un documento de texto para impresion
void exportarADocumentoTexto(vector<Estudiante *> estudiantes)
{
    ofstream archivo("ParaImpresion.txt");
    if (archivo.is_open())
    {
        for (int i = 0; i < estudiantes.size(); ++i)
        {
            int cantAsignaturas = estudiantes[i]->getAsignaturas().size();
            archivo << "Estudiante " << (i + 1) << ":" << endl;
            archivo << "Nombres y apellidos: " << estudiantes[i]->getNombre() << " " << estudiantes[i]->getApellidos() << endl;
            archivo << "Grupo: " << estudiantes[i]->getGrupo() << endl;
            archivo << "Estipendio: " << estudiantes[i]->getEstipendio() << endl;

            float sumaNotas = 0;
            for (int j = 0; j < cantAsignaturas; j++)
            {
                float nota = estudiantes[i]->getAsignaturas()[j].getNota();
                sumaNotas += nota;
                archivo << "Asignatura " << (j + 1) << ": " << nota << endl;
            }

            float promedio = (cantAsignaturas > 0) ? (sumaNotas / cantAsignaturas) : 0;
            archivo << "Promedio: " << promedio << endl;
            archivo << "\n";
        }
        archivo.close();
        cout << "Datos exportados a ParaImpresion.txt" << endl;
    }
    else
    {
        cout << "Error al abrir el archivo para escribir." << endl;
    }
}

// Guardar los datos en un fichero "ListaEstudiantes.txt"
void guardarDatosEnFichero(vector<Estudiante *> estudiantes)
{
    ofstream fichero("ListaEstudiantes.txt");
    fichero.exceptions(ios::badbit | ios::failbit);
    if (!fichero)
        return;

    try
    {
        fichero << estudiantes.size() << endl;
        for (int i = 0; i < estudiantes.size(); ++i)
        {
            vector<Asignatura> asignaturas = estudiantes[i]->getAsignaturas();
            fichero << estudiantes[i]->getClase() << endl
                    << estudiantes[i]->getNombre() << endl
                    << estudiantes[i]->getApellidos() << endl
                    << estudiantes[i]->getCI() << endl
                    << estudiantes[i]->getEstipendio() << endl
                    << estudiantes[i]->getAnnoCurso() << endl
                    << estudiantes[i]->getGrupo() << endl
                    << estudiantes[i]->getiIsProyecto() << endl;
            if (estudiantes[i]->getiIsProyecto())
                fichero << estudiantes[i]->getProyecto() << endl;
            fichero << asignaturas.size() << endl;
            for (auto &asignatura : asignaturas)
            {
                fichero << asignatura.getNombre() << endl
                        << asignatura.getNota() << endl
                        << asignatura.getAnno() << endl
                        << asignatura.getSemestre() << endl;
            }

            if (estudiantes[i]->getClase() == "Estudiante Ayudante")
            {
                EstudianteAyudante *estudianteAyudante = dynamic_cast<EstudianteAyudante *>(estudiantes[i]);
                vector<Asignatura> asignaturasImpartidas = estudianteAyudante->getAsignaturasImpartidas();
                fichero << estudianteAyudante->getAnnosAyudantia() << endl;
                fichero << asignaturas.size() << endl;
                for (auto &asignatura : asignaturasImpartidas)
                {
                    fichero << asignatura.getNombre() << endl
                            << asignatura.getNota() << endl
                            << asignatura.getAnno() << endl
                            << asignatura.getSemestre() << endl;
                }
            }
            else if (estudiantes[i]->getClase() == "Licencia")
            {
                EstudianteLicenciaEspecial *estudianteLicenciaEspecial = dynamic_cast<EstudianteLicenciaEspecial *>(estudiantes[i]);
                fichero << estudianteLicenciaEspecial->getAsignaturaRepetida() << endl
                        << estudianteLicenciaEspecial->getAnnoRepetido() << endl;
            }
        }
    }
    catch (ios::failure &e)
    {
        cerr << "Error: " << e.what() << endl;
    }
}

// Crear Estudiante
void crearEstudiante(vector<Estudiante *> &estudiantes, int &conteoParalelo)
{
    string nombre, apellidos, CI, proyecto;
    float estipendio;
    int annoCurso, grupo, isProyecto, cantidadAsignaturas;
    vector<Asignatura> asignaturas;

    float estipendioFijo = 50;

    try
    {
        cin.ignore();
        cout << "Diga nombres:" << endl;
        getline(cin, nombre);
        cout << "Diga apellidos:" << endl;
        getline(cin, apellidos);
        cout << "Diga CI:" << endl;
        cin >> CI;

        validarCI(CI, estudiantes);

        cout << "Diga ayuda financiera, (0) NO TIENE:" << endl;

        // estipendio fijo=50

        // Estipendio Fijo (EF)
        // Alumno Ayudante (AA)
        // Ayuda Financiera (AF)

        // Si es un estudiante común o de licencia especial: E = EF + AF
        // Si es alumno ayudante: E = EF + AF + AA

        // estipendio en realidad guarda ayuda financiera

        cin >> estipendio;
        if (cin.fail())
            throw runtime_error("Estipendio inválido.");

        // Calculo de estipendio
        estipendio += estipendioFijo;

        cout << "Diga año de curso:" << endl;
        cin >> annoCurso;
        if (cin.fail())
            throw runtime_error("Año de curso inválido.");

        cout << "Diga grupo:" << endl;
        cin >> grupo;
        if (cin.fail())
            throw runtime_error("Grupo inválido.");

        cout << "Diga si el estudiante está en algún proyecto (1)SI, (otro numero)NO: ";
        cin >> isProyecto;
        if (cin.fail())
            throw runtime_error("Valor de proyecto inválido.");

        if (isProyecto == 1)
        {
            cin.ignore();
            cout << "Inserte el nombre del proyecto: ";
            getline(cin, proyecto);
        }
        else
        {
            proyecto = "No tiene proyecto";
        }

        cout << "Diga la cantidad de asignaturas cursadas: ";
        cin >> cantidadAsignaturas;
        if (cin.fail() || cantidadAsignaturas < 0)
            throw runtime_error("Cantidad de asignaturas inválida.");

        for (int i = 0; i < cantidadAsignaturas; i++)
        {
            string nombreAsignatura;
            float nota;
            int anno, semestre;

            cout << "Diga el nombre de la asignatura " << (i + 1) << ": ";
            cin >> nombreAsignatura;

            cout << "Diga la nota de la asignatura " << (i + 1) << ": ";
            cin >> nota;
            if (cin.fail() || nota < 0 || nota > 5)
                throw runtime_error("Nota inválida.");

            cout << "Diga el año en que se cursó la asignatura " << (i + 1) << ": ";
            cin >> anno;
            if (cin.fail())
                throw runtime_error("Año de asignatura inválido.");

            cout << "Diga el semestre en que se cursó la asignatura " << (i + 1) << ": ";
            cin >> semestre;
            if (cin.fail())
                throw runtime_error("Semestre inválido.");

            Asignatura asignatura(nombreAsignatura, nota, anno, semestre);
            asignaturas.push_back(asignatura);
        };

        estudiantes.push_back(new Estudiante(nombre, apellidos, CI, estipendio, annoCurso, grupo, isProyecto == 1, proyecto, asignaturas, "Estudiante"));

        guardarDatosEnFichero(estudiantes);

        cout << "\n";
        cout << "Estudiante creado correctamente." << endl;
        cout << "\n";

        conteoParalelo++;

        estudiantes.back()->mostrar();
    }
    catch (const exception &e)
    {
        cout << "Error al crear estudiante: " << e.what() << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Crear EstudianteAyudante
void crearEstudianteAyudante(vector<Estudiante *> &estudiantes, int &conteoParalelo)
{
    string nombre, apellidos, CI, proyecto;
    float estipendio;
    int annoCurso, grupo, isProyecto, cantidadAsignaturas, annosAyudantia;
    vector<Asignatura> asignaturas, asignaturasImpartidas;

    float estipendioFijo = 50;
    float salarioAyudante;

    try
    {
        cin.ignore();
        cout << "Diga nombres: ";
        getline(cin, nombre);

        cout << "Diga apellidos: ";
        getline(cin, apellidos);

        cout << "Diga CI:" << endl;
        cin >> CI;

        validarCI(CI, estudiantes);

        cout << "Diga ayuda financiera, (0) NO TIENE:" << endl;

        //

        // Estipendio Fijo (EF)
        // Alumno Ayudante (AA)
        // Ayuda Financiera (AF)

        // Si es un estudiante común o de licencia especial: E = EF + AF
        // Si es alumno ayudante: E = EF + AF + AA

        cin >> estipendio;

        if (cin.fail())
            throw runtime_error("Estipendio inválido.");

        cout << "Diga salario de ayudante: ";
        cin >> salarioAyudante;
        if (cin.fail())
            throw runtime_error("Salario inválido.");

        estipendio = estipendioFijo + estipendio + salarioAyudante;

        cout << "Diga año de curso:" << endl;
        cin >> annoCurso;
        if (cin.fail())
            throw runtime_error("Año de curso inválido.");

        cout << "Diga grupo:" << endl;
        cin >> grupo;
        if (cin.fail())
            throw runtime_error("Grupo inválido.");

        cout << "Diga si el estudiante está en algún proyecto (1)SI, (otro numero)NO: ";
        cin >> isProyecto;
        if (cin.fail())
            throw runtime_error("Valor de proyecto inválido.");

        if (isProyecto == 1)
        {
            cin.ignore();
            cout << "Inserte el nombre del proyecto: ";
            getline(cin, proyecto);
        }
        else
        {
            proyecto = "No tiene proyecto";
        }

        cout << "Diga la cantidad de asignaturas cursadas: ";
        cin >> cantidadAsignaturas;
        if (cin.fail() || cantidadAsignaturas < 0)
            throw runtime_error("Cantidad de asignaturas inválida.");

        asignaturas.clear();
        for (int i = 0; i < cantidadAsignaturas; i++)
        {
            string nombreAsignatura;
            float nota;
            int anno, semestre;

            cout << "Diga el nombre de la asignatura " << (i + 1) << ": ";
            cin >> nombreAsignatura;
            cout << "Diga la nota de la asignatura " << (i + 1) << ": ";
            cin >> nota;
            if (cin.fail() || nota < 0 || nota > 5)
                throw runtime_error("Nota inválida.");

            cout << "Diga el año en que se cursó la asignatura " << (i + 1) << ": ";
            cin >> anno;
            if (cin.fail())
                throw runtime_error("Año de asignatura inválido.");

            cout << "Diga el semestre en que se cursó la asignatura " << (i + 1) << ": ";
            cin >> semestre;
            if (cin.fail())
                throw runtime_error("Semestre inválido.");

            Asignatura asignatura(nombreAsignatura, nota, anno, semestre);
            asignaturas.push_back(asignatura);
        };

        cout << "Diga los años de ayudantía: ";
        cin >> annosAyudantia;
        if (cin.fail() || annosAyudantia < 0)
            throw runtime_error("Años de ayudantía inválidos.");

        cout << "Diga la cantidad de asignaturas impartidas: ";
        int cantidadAsignaturasImpartidas;
        cin >> cantidadAsignaturasImpartidas;
        if (cin.fail() || cantidadAsignaturasImpartidas < 0)
            throw runtime_error("Cantidad de asignaturas impartidas inválida.");

        asignaturasImpartidas.clear();
        for (int i = 0; i < cantidadAsignaturasImpartidas; i++)
        {
            string nombreAsignatura;
            float nota = 0;
            int anno = 777, semestre = 666;

            cout << "Diga el nombre de la asignatura impartida " << (i + 1) << ": ";
            cin >> nombreAsignatura;

            /*            cout << "Diga la nota de la asignatura impartida " << (i + 1) << ": ";
                        cin >> nota;
                        if (cin.fail() || nota < 0 || nota > 5)
                            throw runtime_error("Nota inválida.");
            */

            /*         cout << "Diga el año en que se impartió la asignatura " << (i + 1) << ": ";
                     cin >> anno;
                     if (cin.fail())
                         throw runtime_error("Año de asignatura impartida inválido.");
            */

            /*

            cout << "Diga el semestre en que se impartió la asignatura " << (i + 1) << ": ";
            cin >> semestre;
            if (cin.fail())
                throw runtime_error("Semestre de asignatura impartida inválido.");

            */

            // XDDDDDDDD ORIGINALMENTE IBA A PEDIR AQUI EL OBJETO ASIGNATURA PERO SOLO NECESITO GUARDAR
            // EL STRING DEL NOMBRE Y NO VOY A RETOCAR NADA MAS DEL CODIGO, SI FUNCIONA FUNCIONA

            Asignatura asignaturaImpartida(nombreAsignatura, nota, anno, semestre);
            asignaturasImpartidas.push_back(asignaturaImpartida);
        };

        estudiantes.push_back(new EstudianteAyudante(nombre, apellidos, CI, estipendio, annoCurso, grupo, isProyecto == 1, proyecto, asignaturas, "Estudiante Ayudante", annosAyudantia, asignaturasImpartidas));

        guardarDatosEnFichero(estudiantes);

        cout << "\n";
        cout << "Estudiante ayudante creado correctamente." << endl;
        cout << "\n";

        conteoParalelo++;

        estudiantes.back()->mostrar();
    }
    catch (const exception &e)
    {
        cout << "Error al crear estudiante ayudante: " << e.what() << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Regresando al menú principal.\n"
             << endl;
        return;
    }
}

// Crear EstudianteLicenciaEspecial
void crearEstudianteLicenciaEspecial(vector<Estudiante *> &estudiantes, int &conteoParalelo)
{
    string nombre, apellidos, CI, proyecto, asignaturaRepetida;
    float estipendio;
    int annoCurso, grupo, isProyecto, annoRepetido, cantidadAsignaturas;
    vector<Asignatura> asignaturas;

    float Estipendiofijo = 50;

    try
    {
        cin.ignore();
        cout << "Diga nombres: ";
        getline(cin, nombre);

        cout << "Diga apellidos: ";
        getline(cin, apellidos);

        cout << "Diga CI:" << endl;
        cin >> CI;

        validarCI(CI, estudiantes);

        cout << "Diga ayuda financiera, (0) NO TIENE:" << endl;

        //

        // Estipendio Fijo (EF)
        // Alumno Ayudante (AA)
        // Ayuda Financiera (AF)

        // Si es un estudiante común o de licencia especial: E = EF + AF
        // Si es alumno ayudante: E = EF + AF + AA

        cin >> estipendio;

        estipendio += Estipendiofijo;

        if (cin.fail())
            throw runtime_error("Estipendio inválido.");

        cout << "Diga año de curso:" << endl;
        cin >> annoCurso;
        if (cin.fail())
            throw runtime_error("Año de curso inválido.");

        cout << "Diga grupo:" << endl;
        cin >> grupo;
        if (cin.fail())
            throw runtime_error("Grupo inválido.");

        cout << "Diga si el estudiante está en algún proyecto (1)SI, (otro numero)NO: ";
        cin >> isProyecto;
        if (cin.fail())
            throw runtime_error("Valor de proyecto inválido.");

        if (isProyecto == 1)
        {
            cin.ignore();
            cout << "Inserte el nombre del proyecto: ";
            getline(cin, proyecto);
        }
        else
        {
            proyecto = "No tiene proyecto";
        }

        cout << "Diga la cantidad de asignaturas cursadas: ";
        cin >> cantidadAsignaturas;
        if (cin.fail() || cantidadAsignaturas < 0)
            throw runtime_error("Cantidad de asignaturas inválida.");

        asignaturas.clear();
        for (int i = 0; i < cantidadAsignaturas; i++)
        {
            string nombreAsignatura;
            float nota;
            int anno, semestre;

            cout << "Diga el nombre de la asignatura " << (i + 1) << ": ";
            cin >> nombreAsignatura;
            cout << "Diga la nota de la asignatura " << (i + 1) << ": ";
            cin >> nota;
            if (cin.fail() || nota < 0 || nota > 5)
                throw runtime_error("Nota inválida.");

            cout << "Diga el año en que se cursó la asignatura " << (i + 1) << ": ";
            cin >> anno;
            if (cin.fail())
                throw runtime_error("Año de asignatura inválido.");

            cout << "Diga el semestre en que se cursó la asignatura " << (i + 1) << ": ";
            cin >> semestre;
            if (cin.fail())
                throw runtime_error("Semestre inválido.");

            Asignatura asignatura(nombreAsignatura, nota, anno, semestre);
            asignaturas.push_back(asignatura);
        };

        cout << "Diga la asignatura repetida: ";
        cin >> asignaturaRepetida;
        cout << "Diga el año repetido: ";
        cin >> annoRepetido;
        if (cin.fail())
            throw runtime_error("Año repetido inválido.");

        estudiantes.push_back(new EstudianteLicenciaEspecial(nombre, apellidos, CI, estipendio, annoCurso, grupo, isProyecto == 1, proyecto, asignaturas, "Licencia", asignaturaRepetida, annoRepetido));

        guardarDatosEnFichero(estudiantes);

        cout << "\n";
        cout << "Estudiante con licencia especial creado correctamente." << endl;
        cout << "\n";

        estudiantes.back()->mostrar();
        conteoParalelo++;
    }
    catch (const exception &e)
    {
        cout << "Error al crear estudiante con licencia especial: " << e.what() << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }
}

// Eliminar estudiante
void eliminarEstudiante(vector<Estudiante *> &estudiantes)
{

    mostrarEstudiantes(estudiantes);

    cout << "Ingrese el numero en lista del estudiante a eliminar: ";

    int numero;
    cin >> numero;

    if (numero < 1 || numero > estudiantes.size())
    {
        cout << "numero inválido. No se pudo eliminar el estudiante.\n";
        cout << endl;
        return;
    }

    estudiantes.erase(estudiantes.begin() + (numero - 1)); // Eliminar el estudiante con el numero especificado
    cout << "Estudiante eliminado correctamente.\n";
    guardarDatosEnFichero(estudiantes);
    cout
        << endl;
}

// FUNCION DE CARGA PRINCIPAL
// Cargar datos de un fichero "ListaEstudiantes.txt"
void cargarDatosDesdeFichero(vector<Estudiante *> &estudiantes)
{
    ifstream fichero("ListaEstudiantes.txt");
    if (!fichero)
        return;

    estudiantes.clear();
    try
    {
        int cantEstudiantes;
        fichero >> cantEstudiantes;
        for (int i = 0; i < cantEstudiantes; i++)
        {
            fichero.ignore(numeric_limits<streamsize>::max(), '\n');
            string clase;
            getline(fichero, clase);
            string nombre;
            getline(fichero, nombre);
            string apellidos;
            getline(fichero, apellidos);
            string CI;
            getline(fichero, CI);
            float estipendio;
            fichero >> estipendio;
            int annoCurso;
            fichero >> annoCurso;
            int grupo;
            fichero >> grupo;
            bool isProyecto;
            fichero >> isProyecto;
            string proyecto;
            if (isProyecto)
            {
                fichero.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(fichero, proyecto);
            }
            int cantAsignaturas;
            fichero >> cantAsignaturas;

            vector<Asignatura> asignaturas;
            for (int i = 0; i < cantAsignaturas; i++)
            {
                string nombreAsignatura;
                fichero.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(fichero, nombreAsignatura);
                float nota;
                fichero >> nota;
                int anno;
                fichero >> anno;
                int semestre;
                fichero >> semestre;
                asignaturas.push_back(
                    Asignatura(
                        nombreAsignatura,
                        nota,
                        anno,
                        semestre));
            }

            if (clase == "Estudiante")
            {
                estudiantes.push_back(
                    new Estudiante(
                        nombre,
                        apellidos,
                        CI,
                        estipendio,
                        annoCurso,
                        grupo,
                        isProyecto,
                        proyecto,
                        asignaturas,
                        "Estudiante"));
            }
            else if (clase == "Estudiante Ayudante")
            {
                int annosAyudantia;
                fichero >> annosAyudantia;
                int cantidadAsignaturasImpartidas;
                fichero >> cantidadAsignaturasImpartidas;
                vector<Asignatura> asignaturasImpartidas;
                for (int i = 0; i < cantidadAsignaturasImpartidas; i++)
                {
                    string nombreAsignatura;
                    fichero.ignore(numeric_limits<streamsize>::max(), '\n');
                    getline(fichero, nombreAsignatura);
                    float nota;
                    fichero >> nota;
                    int anno;
                    fichero >> anno;
                    int semestre;
                    fichero >> semestre;
                    asignaturasImpartidas.push_back(
                        Asignatura(
                            nombreAsignatura,
                            nota,
                            anno,
                            semestre));
                }

                estudiantes.push_back(
                    new EstudianteAyudante(
                        nombre,
                        apellidos,
                        CI,
                        estipendio,
                        annoCurso,
                        grupo,
                        isProyecto,
                        proyecto,
                        asignaturas,
                        "Estudiante Ayudante",
                        annosAyudantia,
                        asignaturasImpartidas));
            }
            else if (clase == "Licencia")
            {
                string asignaturaRepetida;
                fichero.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(fichero, asignaturaRepetida);
                int annoRepetido;
                cin >> annoRepetido;

                estudiantes.push_back(
                    new EstudianteLicenciaEspecial(
                        nombre,
                        apellidos,
                        CI,
                        estipendio,
                        annoCurso,
                        grupo,
                        isProyecto,
                        proyecto,
                        asignaturas,
                        "Licencia",
                        asignaturaRepetida,
                        annoRepetido));
            }
        }
    }
    catch (ios::failure &e)
    {
        cerr << "Error: " << e.what() << endl;
    }
}

// Animacion de carga
void animacionCarga(float segundos = 2.5)
{

    for (int i = 0; i < segundos * 4; ++i)
    {
        cout << ".";
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(250));
    }
    cout << endl;
}

// Desplegar menu principal
void desplegarMenu(vector<Estudiante *> &estudiantes, int &conteoParalelo)
{
    int opcion;

    while (1 == 1)
    {
        animacionCarga();
        cout << "\n";
        cout << "Seleccione una opcion" << endl
             << endl;
        cout << "1. Añadir Estudiante" << endl;
        cout << "2. Añadir Estudiante Ayudante" << endl;
        cout << "3. Añadir Estudiante Licencia Especial" << endl;
        cout << "4. Eliminar estudiante" << endl
             << endl;

        cout << "5. Mostrar Estudiantes" << endl;
        cout << "6. Buscar Estudiante por CI" << endl;
        cout << "7. Promediar año" << endl;
        cout << "8. Buscar Estudiante por Nombre" << endl;
        cout << "9. Listar estudiantes posibles titulos de oro" << endl;
        cout << "10. Exportar a documento de texto escalafon de estudiantes" << endl;
        cout << "11. Exportar a documento de texto para impresion" << endl;
        cout << "12. Guardar y Salir" << endl;
        cout << "13. Salir sin guardar" << endl;
        cout << "\n";

        try
        {
            cout << "Opcion: ";
            cin >> opcion;
            if (cin.fail())
            {
                cin.clear();                                         // Limpiar el estado de error
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer
                throw runtime_error("Entrada no válida. Debe ingresar un número entero.");
            }
        }
        catch (const exception &error)
        {
            cout << "Error: " << error.what() << endl;
            continue; // Volver a pedir la opción
        }

        switch (opcion)
        {
        case 1:
            crearEstudiante(estudiantes, conteoParalelo);
            break;
        case 2:
            crearEstudianteAyudante(estudiantes, conteoParalelo);
            break;
        case 3:
            crearEstudianteLicenciaEspecial(estudiantes, conteoParalelo);
            break;
        case 4:
            eliminarEstudiante(estudiantes);
            break;

        case 5:
            mostrarEstudiantes(estudiantes);
            break;
        case 6:
            buscarEstudiantePorCI(estudiantes);
            break;
        case 7:
            promediarAnno(estudiantes);
            break;
        case 8:
            buscarEstudiantePorNombre(estudiantes);
            break;
        case 9:
            listarEstudiantesConPromedioMayorA4_75(estudiantes);
            break;

        case 10:
            escalafon(estudiantes);
            break;

        case 11:
            exportarADocumentoTexto(estudiantes);
            break;

        case 12:
            guardarDatosEnFichero(estudiantes);
            cout << "Guardando y saliendo del programa..." << endl;
            return;
        case 13:
            cout << "Saliendo sin guardar" << endl;
            return;

            /*        case 999:
                        cargarDatosDesdeFichero(estudiantes);
                        cout << "Datos cargados desde el fichero." << endl;
                        break;
            */

        default:
            cout << "Opcion no valida, intente de nuevo." << endl;
            break;
        }
    }
}

int main()
{
    vector<Estudiante *> estudiantes;

    int conteoParalelo = 0;

    // En un inicio tenia la idea de hacer 3 vectores, uno por cada clase XD
    // y ahora tengo una variable que va para aqui y para alla
    // y se incrementa cada vez que creo un objeto XDD

    ofstream fichero("ListaEstudiantes.txt", ios::app);
    fichero.close();

    cargarDatosDesdeFichero(estudiantes);

    // Para rematar la broma annadi esta funcion,
    // conteoParalelo basicamente solo da el tamanno
    // de estudiantes JAJAJA

    conteoParalelo += estudiantes.size();

    desplegarMenu(estudiantes, conteoParalelo);

    for (auto estudiante : estudiantes)
    {
        delete estudiante;
    }

    return 0;
}

// REVISAR AYUDA ECONOMICA,
// QUE LAS FUNCIONES DE EXPORTAR A TXT PINCHEN BIEN principalmente escalafon,

// autocarga de datos

// ESTUDIANTE AYUDANTE NO RECIBE ASIGNATURAS COMO OBJETO

// NO PERMITIR ESTUDIANTES CON CI REPETIDO,\\

// AUTOGUARDADO DE DATOS

// estipendio fijo=50

// Estipendio Fijo (EF)
// Alumno Ayudante (AA)
// Ayuda Financiera (AF)

// Si es un estudiante común o de licencia especial: E = EF + AF
// Si es alumno ayudante: E = EF + AF + AA

/*toDo:


  • Confeccionar un documento texto para una futura impresión que contenga el siguiente formato:

  Nombre y Apellidos: __________________
Grupo: ______
Estipendio: ____
Asignatura_1: notas
Asignatura_2: notas
Asignatura_3: notas
Asignatura_4: notas
.
.
Asignatura_n: notas
Promedio: _____



*/
