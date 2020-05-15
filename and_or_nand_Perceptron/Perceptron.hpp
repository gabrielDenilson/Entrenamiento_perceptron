#pragma once
#ifndef PERCEPTRON_HPP
#define PERCEPTRON_HPP

#include <vector>
#include <numeric>
#include <stdexcept>

#include "Entrenamiento.hpp"

class Perceptron
{
 public:
  Perceptron (int contador_entrada, const double aprendizaje_ = 0.1,
              const double umbral_ = 0.5)
    : pesos(contador_entrada)
  {
      aprendizaje_vel = aprendizaje_;
      umbral = umbral_;
  }

  double aprendizaje_tasa() const { return aprendizaje_vel; }
  void aprendizaje_tasa(const double &aprendiz) { aprendizaje_vel = aprendiz; }

  double unbral() const { return umbral; }
  void unbral(const double &mi_umbral) { umbral = mi_umbral; }

  std::vector<double> & weights() { return pesos; }
  void misPesos(const std::vector<double> &mis_pesos) { pesos = mis_pesos; }

  void entrenar(std::vector<Entrenamiento> & mi_entrenamiento, unsigned int maximo_iteraciones)
  {
    if (maximo_iteraciones == 0)
      throw std::invalid_argument("El numero maximo de iteraciones no puede ser cero.");

    unsigned int iteraciones(0);
    while (true) {
        if (iteraciones > maximo_iteraciones)
            break;
        else
            iteraciones++;

        int error_contador = 0;

        for (auto &item : mi_entrenamiento) {
            bool output = aprender(item.mi_salida(), item.mi_entrada());

            if (output != item.mi_salida())
                error_contador++;
        }

        if (error_contador == 0)
            break;
    }
  }

  bool obtener_Resulatados(const std::vector<double> &entradas_)
  {
    if (entradas_.size() != pesos.size())
      throw std::invalid_argument("Numero invalido de entradas. Excepciones: "
                                  + pesos.size());

    return puntoProducto(entradas_, pesos) > umbral;
  }

  bool aprender(bool resul_esperado, const std::vector<double> &entradas_)
  {
    bool resultado = obtener_Resulatados(entradas_);
    if (resultado != resul_esperado) {
        //Convertir booleano a numero
        double error = (resul_esperado ? 1 : 0) - (resultado ? 1 : 0);
        for (int i = 0; i < pesos.size(); i++) {
            pesos[i] += aprendizaje_vel * error * entradas_[i];
        }
    }

    return resultado;
  }

 private:
  double aprendizaje_vel;
  double umbral;
  std::vector<double> pesos;

  //Funcion que saque de StackOverflow para el punto de partida
  double puntoProducto(const std::vector<double> &v1,
                     const std::vector<double> &v2)
  {
      return std::inner_product(v1.begin(), v1.end(), v2.begin(), 0);
  }

};

#endif 