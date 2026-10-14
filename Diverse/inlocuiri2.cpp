//Fiind dat un număr natural n înlocuiți toate aparițiile cifrei c1 din numărul n cu cifra c2.


#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char s[12], c1, c2;
    cin >> s >> c1 >> c2;
 
    char *q = s;
    while ((q = strchr(q, c1)))
        *q++ = c2;
    
    char *p = s;
    while (*p == '0' && *(p+1))
        p++;

    cout << p;
    return 0;
}    
