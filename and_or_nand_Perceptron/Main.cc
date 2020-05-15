/*  DENILSON GABRIEL MAMANI COCHI
    AND, NAND, OR, NOR

    LO HIZE EN C++ PORQUE ES EL LENGUAJE QUE MAS PRACTICO,
    LAS OPERACIONES LAS HICE
    CON AYUDA DE TUTORIALES
    NO PUDE TERMINARLO PARA QUE EVALUE PARAMETROS
    PERO CUMPLE SU COMETIDO
    */

#include <vector>
#include <iostream>
#include <cassert>

#include "Perceptron.hpp"

void ANDPerceptron()
{
    std::cout << "Entrenando perceptron AND..." << std::endl;

    std::vector<Entrenamiento> training_set =
    {
        Entrenamiento(false, { 1, 0, 0 }),
        Entrenamiento(false, { 1, 0, 1 }),
        Entrenamiento(false, { 1, 1, 0 }),
        Entrenamiento(true,  { 1, 1, 1 })
    };

    Perceptron perceptron(3);

    perceptron.entrenar(training_set, 43);

    assert(perceptron.obtener_Resulatados({ 1, 0, 0 }) == false);
    assert(perceptron.obtener_Resulatados({ 1, 0, 1 }) == false);
    assert(perceptron.obtener_Resulatados({ 1, 1, 0 }) == false);
    assert(perceptron.obtener_Resulatados({ 1, 1, 1 }) == true);
    std::cout << "Entrenamiento exitoso!" << std::endl;
    std::cout << std::endl;
}

void NANDPerceptron()
{
    std::cout << "Entrenando perceptron  NAND..." << std::endl;

    std::vector<Entrenamiento> training_set =
    {
        Entrenamiento(true,  { 1, 0, 0 }),
        Entrenamiento(true,  { 1, 0, 1 }),
        Entrenamiento(true,  { 1, 1, 0 }),
        Entrenamiento(false, { 1, 1, 1 })
    };

    Perceptron perceptron(3);

    perceptron.entrenar(training_set, 29);

    assert(perceptron.obtener_Resulatados({ 1, 0, 0 }) == true);
    assert(perceptron.obtener_Resulatados({ 1, 0, 1 }) == true);
    assert(perceptron.obtener_Resulatados({ 1, 1, 0 }) == true);
    assert(perceptron.obtener_Resulatados({ 1, 1, 1 }) == false);
    std::cout << "Entrenamiento exitoso!" << std::endl;
    std::cout << std::endl;
}

void ORPerceptron()
{
    std::cout << "Entrenando perceptron OR..." << std::endl;

    std::vector<Entrenamiento> training_set =
    {
        Entrenamiento(false, { 1, 0, 0 }),
        Entrenamiento(true,  { 1, 0, 1 }),
        Entrenamiento(true,  { 1, 1, 0 }),
        Entrenamiento(true,  { 1, 1, 1 })
    };

    Perceptron perceptron(3);

    perceptron.entrenar(training_set, 14);

    assert(perceptron.obtener_Resulatados({ 1, 0, 0 }) == false);
    assert(perceptron.obtener_Resulatados({ 1, 0, 1 }) == true);
    assert(perceptron.obtener_Resulatados({ 1, 1, 0 }) == true);
    assert(perceptron.obtener_Resulatados({ 1, 1, 1 }) == true);
    std::cout << "Entrenamiento exitoso!" << std::endl;
    std::cout << std::endl;
}

void NORPerceptron()
{
    std::cout << "Entrenando perceptron NOR..." << std::endl;

    std::vector<Entrenamiento> training_set =
    {
        Entrenamiento(true,  { 1, 0, 0 }),
        Entrenamiento(false, { 1, 0, 1 }),
        Entrenamiento(false, { 1, 1, 0 }),
        Entrenamiento(false, { 1, 1, 1 })
    };

    Perceptron perceptron(3);

    perceptron.entrenar(training_set, 14);

    assert(perceptron.obtener_Resulatados({ 1, 0, 0 }) == true);
    assert(perceptron.obtener_Resulatados({ 1, 0, 1 }) == false);
    assert(perceptron.obtener_Resulatados({ 1, 1, 0 }) == false);
    assert(perceptron.obtener_Resulatados({ 1, 1, 1 }) == false);
    std::cout << "Entrenamiento exitoso!" << std::endl;
    std::cout << std::endl;
}


int main(int argc, char **argv)
{
    std::cout << "Estudiante: DENILSON GABRIEL MAMANI COCHI" << std::endl;
    std::cout << "Este programa esta desarrollado para la clase de I.A 2. ." << std::endl;
    std::cout << "ing. JESUS ROCHA" << std::endl;
    std::cout << "Entrenamiento de perceptron simple." << std::endl;

    std::cout << std::endl;

    ANDPerceptron();
    NANDPerceptron();
    ORPerceptron();
    NORPerceptron();

    return 0;
}
