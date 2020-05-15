/*
* Author : DENILSON GABRIEL MAMANI COCHI
*/

/*PRUEBA PARA EVALUAR EL ENTRENAMIENTO DEL PERCEPTRON*/
#include <iostream>

/*
          OR
 1 1 = 1
 1 0 = 1
 0 1 = 1
 0 0 = 0

*/

/*
          NOR
 1 1 = 0
 1 0 = 0
 0 1 = 0
 0 0 = 1

*/
/*
          AND
 1 1 = 1
 1 0 = 0
 0 1 = 0
 0 0 = 0

*/

/*
          NAND
 1 1 = 0
 1 0 = 1
 0 1 = 1
 0 0 = 1

*/
//DataSet OR
int dataset[4][3]={{1,1,1},
                   {1,0,1},
                   {1,1,0},
                   {1,0,0}}; 

/*
//DataSet AND
int dataset[4][3] = { {1,1,1},
                      {0,0,1},
                      {0,1,0},
                      {0,0,0} }; */

/*
//DataSet NAND
int dataset[4][3] = { {1,1,1},
                      {0,0,1},
                      {0,1,0},
                      {0,0,0} }; */

int etiquetas[]={1,1,1,0};  //or

//int etiquetas[] = { 0,0,0,1 }; // nor

//int etiquetas[] = { 0,0,0,1 }; // and

//int etiquetas[] = { 1,0,0,0}

// Pesos:
float w[]={0.3,0.2};
float umbral = 0.5;
// Tasa de aprendizaje
float alpha = 1;
// Bias
float bias = 0.5;
// error
float error = 0;
float errorFinal = 0;

float funcion(float suma){
    if (suma>0){
        return 1;
    }
    else{
        return 0;
    }

}

int main()
{
    float suma = 0;
    //  Iteraciones
    for(int i= 0; i< 1000; i++){
        std::cout<<"------ Iteracion: "<< i+1<<" -----"<<std::endl;
        for(int i = 0; i<4; i++){
            for (int j = 1; j<3; j++){
                suma = w[j]*dataset[i][j];
            }
            suma = suma +bias;
            error = etiquetas[i] - funcion(suma);
            std::cout<<"etiqueta: "<<etiquetas[i]<<" resultado: "<<funcion(suma)<<std::endl;
            //std::cout<<"error: "<<error<<std::endl;
            if (error != 0 ){
                for(int j = 1; j< 3; j++){
                    w[j] = w[j]+alpha*error*dataset[i][j];
                }
                bias = bias +alpha*error*dataset[i][0];
                //std::cout<< "w1: "<<w[1]<<"   y   w2: "<<w[2]<<" bias: "<<bias<<std::endl;
                errorFinal = errorFinal + error;
            }
        }
        if(errorFinal ==0){
            std::cout<<"------- Entrenamiento finalizado -------"<<std::endl;
            break;
        }else{
            errorFinal = 0;
        }
    }

    while(true){
            std::cout<<std::endl;
            std::cout<< "Funcion"<<std::endl;
            std::cout<< "w1: "<<w[1]<<"   |   w2: "<<w[2]<< " | bias: "<<bias<<std::endl;
            std::cout<< "Ingrese Valor 1"<<std::endl;
            float x;
            std::cin>>x;
             std::cout<< "Ingrese Valor 2"<<std::endl;
            float y;
            std::cin>>y;

            float prediccion = funcion(x* w[1]+ y*w[2]+bias);
            std::cout << "----- El resultado es: "<< prediccion<<" -----" <<std::endl;

    }



    return 0;
}
