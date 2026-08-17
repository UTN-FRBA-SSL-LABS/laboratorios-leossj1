#include <stdio.h>
#include "../src/carrito.h"
#include "minunit/minunit.h"

/*
 * Tests de integracion: verifican que las funciones trabajan bien
 * en combinacion, no de forma aislada.
 */

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE D — Escribir el test guiado (ver README.md, Parte 8)
 * ═══════════════════════════════════════════════════════════════════════════ */

/* TODO: escribir test_compra_con_descuento() siguiendo la guia del .md */
void test_compra_con_descuento(void) {
    printf("\n[compra con descuento]\n");
    Carrito c;
    carrito_init(&c);

    Producto pan = {"Pan", 200, 3};
    Producto leche = {"Leche", 350, 2};

    carrito_agregar(&c, pan);
    carrito_agregar(&c, leche);

    int total = carrito_total(&c);

    /* Total sin descuento: (200 * 3) + (350 * 2) = 600 + 700 = 1300 */
    ASSERT_IGUAL(1300, total);

    /* Total con 10% de descuento: 1300 - 130 = 1170 */
    ASSERT_IGUAL(1170, carrito_descuento(total, 10));
}

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE E — Disenar un test propio (ver README.md, Parte 9)
 * ═══════════════════════════════════════════════════════════════════════════ */

/* TODO: escribir test_agregar_hasta_llenar() */
void test_agregar_hasta_llenar(void) {
    printf("\n[agregar hasta llenar]\n");
    Carrito c;
    carrito_init(&c);

    Producto p = {"Yerba", 500, 1};

    /* 1. Llenar el carrito hasta su capacidad maxima (4 productos) */
    carrito_agregar(&c, p);
    carrito_agregar(&c, p);
    carrito_agregar(&c, p);
    carrito_agregar(&c, p);

    /* 2. Verificar que el conteo es MAX_ITEMS (4) */
    ASSERT_IGUAL(MAX_ITEMS, carrito_contar(&c));

    /* 3. Verificar que intentar agregar uno mas devuelve 0 */
    ASSERT_IGUAL(0, carrito_agregar(&c, p));

    /* 4. Verificar que el conteo sigue siendo MAX_ITEMS (no cambio) */
    ASSERT_IGUAL(MAX_ITEMS, carrito_contar(&c));
}

int main(void) {
    printf("=== Tests de integracion ===");
    test_compra_con_descuento();
    test_agregar_hasta_llenar();
    RESUMEN();
    return EXIT_CODE();
}
