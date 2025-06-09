# 07_ClasesAmigas

Programas diseñados para ilustrar el uso de clases amigas (`friend class`) y funciones amigas (`friend function`) en C++.

| Archivo                             | Descripción |
|-------------------------------------|-------------|
| amigaclase1.cpp                     | Muestra cómo una clase (`CALC_VECXYZ`) accede directamente a los miembros privados de otra (`Coordenadas`) gracias a la amistad. Realiza suma de vectores 3D. |
| amigaExterna.cpp                   | Demuestra el uso de una función externa `Ver()` como `friend` de la clase `A` para acceder a miembros privados. |
| amigaInterna.cpp                   | La función miembro `EsMayor()` de la clase `B` es `friend` de la clase `A`. Se compara un valor entre dos clases relacionadas. |
| REPASOAMIGA.cpp                    | Aplica amistad entre clases con un puntero. Calcula el promedio de tres valores ingresados por el usuario. Muy útil para conceptos como encapsulamiento y acceso indirecto. |
| COSA1.cpp                          | Usa una función `friend` llamada `cargar()` para modificar directamente miembros privados de un objeto. Muy claro y funcional. |
| timefucamiga.CPP                   | Función amiga `TIME_DATE` que accede a miembros de dos clases distintas (`TIME1` y `DATE1`). Muestra cómo combinar tiempo y fecha como una sola cadena. |

