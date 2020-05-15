#pragma once
#ifndef TRAININGITEM_HPP
#define TRAININGITEM_HPP

#include <vector>

class Entrenamiento {
 public:
  Entrenamiento(bool salidas_, const std::vector<double> &entradas_)
      : salidas(salidas_)
  {
      entradas = entradas_;
  }

  bool mi_salida() const { return salidas; }
  std::vector<double> & mi_entrada() { return entradas; }

 private:
  bool salidas;
  std::vector<double> entradas;
};

#endif
