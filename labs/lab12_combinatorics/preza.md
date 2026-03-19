

Презентация
---
Инициализация программы
```cpp
#include <iostream>
using namespace std;

int main() {
    const int n = 3;
    int P[n];
    int R[n];

    for (int i1 = 0; i1 < n; i1++) {
        P[i1] = i1; R[i1] = 1;
        
        for (int i2 = 0; i2 < n; i2++) {
            if (R[i2] == 0) {
                P[i2] = i2; R[i2] = 1;
                
                for (int i3 = 0; i3 < n; i3++) {
                    if (R[i3] == 0) {
                        P[i3] = i3; R[i3] = 1;
                        
                        cout << P[0] << " " << P[1] << " " << P[2] << endl;
                        
                        R[i3] = 0;
                    }
                }
                R[i2] = 0;
            }
        }
        R[i1] = 0;
    }
    return 0;
}

```
---
Заголовок

```cpp
#include <iostream>
using namespace std;

int main() {
    const int n = 3;
    int P[n];
    int R[n];

    for (int i1 = 0; i1 < n; i1++) {
        P[i1] = i1; R[i1] = 1;
        
        for (int i2 = 0; i2 < n; i2++) {
            if (R[i2] == 0) {
                P[i2] = i2; R[i2] = 1;
                
                for (int i3 = 0; i3 < n; i3++) {
                    if (R[i3] == 0) {
                        P[i3] = i3; R[i3] = 1;
                        
                        cout << P[0] << " " << P[1] << " " << P[2] << endl;
                        
                        R[i3] = 0;
                    }
                }
                R[i2] = 0;
            }
        }
        R[i1] = 0;
    }
    return 0;
}


