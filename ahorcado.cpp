//incluir librerias//
#include <iostream>
#include <cstdlib>
#include <string>
#include <cctype>

using namespace std;

//palabras aleatorias//

string words[]={"star","planet","wifi","internet","rocket","help","rescue","galaxy","travel","space"};


//declarar las funciones que son las que ayudan a ver que es lo que se debe realizar//


//la funcion de limpiar la pantalla//

void Cleanscreen(){
    #ifdef _WIN32
        system("clear");
    #else
        system("clear");
    #endif
}


//Dibujo del cuerpo//
void body(int life){
    switch (life)
    {
    case 6:
    cout<<".........."<<endl;
    cout<<"|"<<endl;
    cout<<"|"<<endl;
    cout<<"|"<<endl;
    cout<<"|"<<endl;
    cout<<"|"<<endl;
    cout<<"|"<<endl;
    cout<<"|"<<endl;
    break;

    case 5:
    cout<<".........."<<endl;
    cout<<"|        O"<<endl;
    cout<<"|"<<endl;
    cout<<"|"<<endl;
    cout<<"|"<<endl;
    cout<<"|"<<endl;
    cout<<"|"<<endl;
    cout<<"|"<<endl;
    break;

    case 4:
    cout<<".........."<<endl;
    cout<<"|        O"<<endl;
    cout<<"|        |"<<endl;
    cout<<"|"<<endl;
    cout<<"|"<<endl;
    cout<<"|"<<endl;
    cout<<"|"<<endl;
    cout<<"|"<<endl;
    break;

    case 3:
    cout<<".........."<<endl;
    cout<<"|        O"<<endl;
    cout<<"|       /|"<<endl;
    cout<<"|"<<endl;
    cout<<"|"<<endl;
    cout<<"|"<<endl;
    cout<<"|"<<endl;
    cout<<"|"<<endl;
    break;

    case 2:
    cout<<".........."<<endl;
    cout<<"|        O"<<endl;
    cout<<"|       /|\\"<<endl;
    cout<<"|"<<endl;
    cout<<"|"<<endl;
    cout<<"|"<<endl;
    cout<<"|"<<endl;
    cout<<"|"<<endl;
    break;

    case 1:
    cout<<".........."<<endl;
    cout<<"|        O"<<endl;
    cout<<"|       /|\\"<<endl;
    cout<<"|       /"<<endl;
    cout<<"|"<<endl;
    cout<<"|"<<endl;
    cout<<"|"<<endl;
    cout<<"|"<<endl;
    break;


    case 0:
    cout<<".........."<<endl;
    cout<<"|        O"<<endl;
    cout<<"|       /|\\"<<endl;
    cout<<"|       / \\"<<endl;
    cout<<"|"<<endl;
    cout<<"|"<<endl;
    cout<<"|"<<endl;
    cout<<"|"<<endl;
    default:
        break;
    }
}


void Playgame(){
    srand((int)(NULL));
    int nA=rand()%7;

    string word=words[nA];
    string hiddendword(word.length(),'_');

    int life=6;
    char letter;
    bool win=false;



    while (life>0 && !win)
    {
        Cleanscreen();
        body(life);


        cout<<"Word:"<<hiddendword<<endl;
        cout<<"Remaining lifes"<<life<<endl;
        cout<<"Enter a letter:"<<endl;
        cin>>letter;



        //funcion para que aunque el usuario ingrese la letra en mayuscula no genere un error o lo tome como malo//

        letter=tolower(letter);


        bool hitit=false;

        for (int i = 0; i < word.length(); i++)
        {
            if (word[i]==letter && hiddendword[i]=='_')
            {
                hiddendword[i]=letter;

                hitit=true;
            }
            
        }
         //Mostrar cuando ingreso una letra correctamente//


        if (!hitit)
        {
            life--;
            cout<<"Wrong letter, try with another one"<<endl;
            cout<<"You lose a life...sorry"<<endl;
        }
        else{

            cout<<"GOOD!!!,It's the correct letter"<<endl;
        }
        
      cout<<"Press Enter to continue"<<endl;

      cin.ignore();
      cin.get();
    }
    
}

int main(){

    int options;

//mostrar un do while para no generar un blucle infinito//
 do
 {
 int life=6;
 Cleanscreen();


 //Otro menu//

    cout<<"----------------------"<<endl;
    cout<<"----------------------"<<endl;
    cout<<"       HANGMAN        "<<endl;
    cout<<"-----------------------"<<endl;
    cout<<"-----------------------"<<endl;
    cout<<"1 PLAY GAME"<<endl;
    cout<<"2 GO BACK"<<endl;
    cin>>options;


    //si el usuario pone una opcion distinta obtendra un "error",para esto se utilizsara un if//
      if (options!=1 && options!=2)
    {
    cout<<"THERE IS A PROBLEM...choose between the option 1 and 2"<<endl;
    cout<<"Please try again"<<endl;
    }

    else{

    //swith para las opciones o caasos que tiene el usuario//

    switch (options)
    {
    case 1:
    Playgame();
    break;

    case 2:
    cout<<"You went back to the principal menu"<<endl;
    default:
    break;
    }
    }

 } while (options!=2);

    return 0;
}
