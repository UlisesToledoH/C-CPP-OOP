# 07_FuncionesFriend

Programas que utilizan **funciones amigas** (`friend function`) para acceder a miembros privados de una clase sin ser parte de ella. Estas funciones se definen fuera de la clase, pero se les concede acceso.

| Archivo                                  | Descripción |
|------------------------------------------|-------------|
| AsignacionPorFuncionAmiga.cpp            | La función `cargar()` asigna directamente valores al miembro privado `datos` de un objeto `cosa`. Ejemplo simple de función amiga. |
| FuncionAmiga_Externa.cpp                 | La función `Ver()` accede a un miembro privado de la clase `A` desde fuera. Comparación con uso de métodos públicos. |
| FuncionAmiga_Multiclase_TiempoFecha.cpp  | La función `TIME_DATE()` accede a atributos de dos clases diferentes (`TIME1` y `DATE1`) para combinar fecha y hora. |
| DistanciaEntrePuntos_FuncionAmiga.cpp    | Calcula la distancia entre dos objetos `Punto` utilizando una función `friend`. Ejemplo clásico de geometría con POO.
