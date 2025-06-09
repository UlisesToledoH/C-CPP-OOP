# 06_ClasesAmigas

Programas que demuestran el uso de **clases amigas** en C++ mediante la palabra clave `friend class`. Una clase amiga puede acceder directamente a los miembros privados de otra clase.

| Archivo                                  | Descripción |
|------------------------------------------|-------------|
| Vectores3D_Suma_ClaseAmiga.cpp           | Realiza la suma de dos vectores 3D. `CALC_VECXYZ` es amiga de `Coordenadas`, y accede directamente a sus atributos. |
| Promedio_ClaseAmiga_ConPuntero.cpp       | Calcula el promedio de tres calificaciones usando amistad entre clases. La clase amiga accede al objeto `Coordenadas` por puntero. |
| FuncionAmiga_MiembroDeOtraClase.cpp      | La función miembro `EsMayor()` de la clase `B` es amiga de la clase `A`. Permite comparar valores privados entre dos clases distintas. |
