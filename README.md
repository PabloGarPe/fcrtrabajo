# Trabajo de Fundamentos de Computadores y Redes

> Universidad de Oviedo – Curso 2024-2025  
> Escuela de Ingeniería Informática de Oviedo   
> Asignatura: Fundamentos de Computadores y Redes  
> Grupo de prácticas: PL.3 - A  
> Titulación: PCEO Informática y Matemáticas
> 

## Descripción
Este repositorio contiene la implementación del trabajo de la asignatura *Fundamentos de Computadores y Redes* de la Universidad de Oviedo. El proyecto consiste en el desarrollo de un sistema de control de licencias utilizando C/C++ y ensamblador x86, aplicando conceptos de manipulación de bits, operaciones con máscaras y verificaciones de seguridad.

## Funcionalidades
### Fase I
- **ControlWithReversedStrings**
- **MaskControl**
- **ControlInAsm**
- **CheckArray**


## Herramientas utilizadas
Para este proyecto, se han empleado las siguientes herramientas:
- Visual Studio (Teamwork Template)
- Lenguaje C++ y ensamblador (x86-64)
- Git + GitHub (flujo basado en feature branches y pull requests)

## Instalación
Clonar este repositorio:
```bash
git clone https://github.com/tu_usuario/fcrtrabajo.git
cd fcrtrabajo
```


## Asignación de Tareas
El proyecto se dividirá de la siguiente manera:

| Tarea                | Responsable       | Estado |
|----------------------|-------------------|------------------|
| ControlWithReversedStrings | Diego |Falta Testeo           |
| MaskControl          | Pablo |Falta Testeo           |
| ControlInAsm         | Fernando |Falta Testeo          |
| CheckArray           | Jorge |Falta Testeo           |


## Flujo del Repositorio

El proyecto se ha desarrollando siguiendo la dinámica *feature branching*. Así, se consideran las siguientes ramas:

- **Rama principal (`main`)**:
  - Rama estable
  - Contiene el código listo para producción o releases
  - Nadie debe de trabajar directamente sobre esta rama
- **Rama de desarrollo (`develop`)**:
  - Rama base para el desarrollo de nuevas features
  - Aquí se integran las ramas de feature antes de pasar a `main`
- **Crear una nueva rama para feature**:
  - Cada funcionalidad, corrección o mejora se desarrolla en su propia rama
    ```bash
    git checkout develop
    git pull origin develop
    git checkout -b feature/nombre-descriptivo
    ```
  - Finalmente, para incorporar la funcionalidad al *main*, hay que abrir un pull request en GitHub desde la rama `feature-nombre` hacia la rama `main`.


> **Reglas de contribución:** Antes de enviar un *pull request*, asegúrate de que tu código está bien documentado y sigue la estructura del proyecto.

