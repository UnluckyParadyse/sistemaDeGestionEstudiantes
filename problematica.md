PROYECTO #2. CONTROL DE DATOS

A un vicedecano de formación de una facultad, debido a la sobrecarga de trabajo que tiene le cuesta mucho trabajo tener un control sobre los datos de los estudiantes de su facultad y más difícil aun es buscar una información determinada de algún estudiante, es por eso que le pide a un grupo de estudiantes que le realicen una aplicación que pueda facilitarle este tarea.

El vicedecano les informa que deben tener en cuenta que hay tres categorías de estudiantes, el estudiante común, el alumno ayudante y el de licencia especial. Por cada estudiante común se va ha guardar nombre, apellidos, CI, el estipendio, grupo al que pertenece, año de curso, si está o no en proyecto (de estar en alguno poner el nombre), las asignaturas que haya cursado (por cada asignatura se va a guardar el nombre,  la nota final, el año y el semestre en que se dio) y si recibe ayuda financiera o no. Las otras dos categorías van ha tener la misma información que el estudiante común. En caso de que sea alumno ayudante, se le adiciona los años de ayudantía y la(s) asignatura(s) que impartió y si es de licencia especial la asignatura y el año que repitió. Un estudiante de licencia especial no puede ser Alumno Ayudante.

El estipendio (E) va ha estar definido por:
Estipendio Fijo (EF) = Alumno Ayudante (AA) =  Ayuda Financiera (AF) = $50.
Si es un estudiante común o de licencia especial: E = EF + AF
Si es alumno ayudante: E = EF + AF + AA

De la aplicación se necesita que dado un estudiante haga lo siguiente:

    • De la posibilidad de insertarlo.
    • Realizar una búsqueda mediante el CI y que muestre el grupo al que pertenece.
    • Determinar su promedio de un año específico,
    • Dado el nombre, Verificar si es Licencia Especial o Alumno Ayudante, mostrar sus datos característicos.
    • Obtener un listado de todos los estudiantes posibles diplomas de oro (promedio > 4.75)

    • Confeccionar un documento texto con el escalafón de los estudiantes (nombre-promedio) para una futura impresión.

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

Nota: Elabore una aplicación que permita darle solución al problema anterior, la misma debe contar con un menú que permita entrar los datos y procesar toda la información. Además, debe guardase la información en un fichero y abrir la información guardada en el fichero.