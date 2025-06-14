# RESTAUSARS-COV2 🍽️

**Simulador de pedidos para restaurante en consola**, desarrollado como proyecto escolar en C++.

## 📄 Descripción

Este programa permite gestionar pedidos en un restaurante ficticio, desde la toma de orden hasta la visualización de tickets, todo mediante un menú en consola. Usa clases en un solo archivo fuente para estructurar la lógica del sistema.

## 🧱 Características principales

- Menú interactivo en consola con `system("cls")` y `conio.h`.
- Registro de cliente.
- Visualización y selección de alimentos del menú.
- Cálculo de totales por pedido.
- Ticket de compra.
- Uso de clases para encapsular lógica.
- Control del flujo mediante menús anidados.

## 💻 Requisitos

- Sistema operativo **Windows**.
- Compilador C++ con soporte para `conio.h` y `windows.h`.
- Consola de 80x25 (el programa define esta dimensión).

## ▶️ Ejecución

1. Compila el archivo:
   ```bash
   g++ PROYECTO_08_01_2021_45.cpp -o restaurante.exe
