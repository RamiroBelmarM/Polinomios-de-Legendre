# Polinomios-de-Legendre
Polinomios de Legendre programado en c++, usando las relaciones de recurrencia


![Alt text](https://raw.githubusercontent.com/RamiroBelmarM/Polinomios-de-Legendre/main/legendre.png)


```cpp
#include "legendre.h"
int main(){
    //se crea objeto Legendre
    Legendre pn;

    //grado del polinomio
    pn.set_n(n);

    //obtener Pn(t)
    value=pn.get_P(t)

    //obtener derivada de Pn(t)
    value=pn.get_DP(t)

    //cambiar grado
    //pn.get_n(n)
    //cambiar rango normalizado alrededor de 0
    //pn.set_alpha(a)

    return 0;
}
```
# Referencia 

Arfken, G. B., & Weber, H. J. (1999). Mathematical methods for physicists.