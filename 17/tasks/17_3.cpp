#include <iostream>
#include <cstring>

bool substr(const char * p1, const char * p2); 

              
int main() {

    const char* a = "Hello worldlig";
    const char* b  = "lig";
    const char* c = "ligs";
    
    std::cout << substr(a,b)<<"   "<< substr(a,c);
    return 0;
}





bool substr(const char * p1, const char * p2) {

    bool found = false;
    for (int i = 0; i + strlen(p2) <= strlen(p1); ++i) {
        bool match = true;
        for (size_t j = 0; j < strlen(p2); ++j) {
            if (*(p2 + j) != *(p1 + i + j)) {
                match = false;
                break;
            }
        }
        if(match) {
            found = true;
            break;
        }
    }

    
    return found;
}



