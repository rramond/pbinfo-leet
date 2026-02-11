// varianta 1: cautare carac si stergere

#include <iostream>
#include <cstring>
using namespace std;

bool anagrama(char s1[], char s2[], int len_s1, int len_s2) {
    if(len_s1 != len_s2) return 0;
  
    for (int i = 0; i < len_s1; i++) {
        char* pos = strchr(s2, s1[i]);
        if (pos != NULL) {
            strcpy(pos, pos + 1);
        } else return 0;
    }
    return 1;
}

int main() {
    char s1[21], s2[21];
    cin >> s1 >> s2;

    int x = strlen(s1);
    int y = strlen(s2);

    cout << anagrama(s1, s2, x, y);
}


// varianta 2: vector de frecventa