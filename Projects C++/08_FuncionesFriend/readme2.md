# 08_FuncionesFriend

errores a corregir
Programas que aplican funciones `friend` para realizar operaciones entre objetos, sin necesidad de exponer directamente los atributos.

| Archivo                             | Descripción |
|-------------------------------------|-------------|
| PUNTO1.cpp                          | Calcula la distancia entre dos puntos 2D usando una función `friend`. Código limpio, corto y funcional. |
| FrienDistancia1.cpp                | ⚠️ **Este archivo contiene varios errores de diseño:**<br>
- La función `distancia()` está mal implementada (usa `LeeX` y `LeeY` como si fueran atributos, cuando son funciones).<br>
- Los objetos `PUNTO1()` y `PUNTO2()` están mal declarados (parecen funciones).<br>
- Las funciones `LEEX`, `LEEY`, `VERX`, `VERY` acceden a métodos como si fueran variables.<br><br>
🔧 **Sugerencia**: Elimina o corrige profundamente este archivo. Ya tienes `PUNTO1.cpp` como mejor versión. |
