//Mina Maged Faris      : 20210420
//Felopater Maher Faris : 20210291

#include <iostream>
#include<fstream>
#include <string>
#include <cctype>
#include <regex>
#include"function.cpp"

using namespace std;

int main(){

    cout<<"Welcome to Mina&Felo Text Editor.\n"<<endl;

    string orignal = inputFile();
    //to not manipulate in the original file i made another file and copied all the file content in it.
    string file = file2(orignal);

    bool en = true ;

    while(en){ //enless loop to make the user in the programe and the loop doensn't break till the user enter 16

    entermessage();

    StartingPoint:
    int num;
    cin>>num;
    if (cin.fail())
    {
        cout << "You should enter correct choice\n\n";
        cin.clear();
        cin.ignore(10000, '\n');
        goto StartingPoint;
    }

     if(num == 1)
     {
         addtext(file);
     }
     else if(num == 2)
     {
         Display(file);
     }
     else if(num == 3)
     {
         Empty(file);
         cout<<"the content in the file has been cleared."<<endl;
     }
     else if (num == 4)
    {
        Encrypt(file);
    }
     else if (num == 5)
    {
        decrybtion(file);
    }
    else if (num== 6)
    {
        merg(file);
    }
    else if (num == 7)
    {
        numofwords(file);
    }
    else if (num == 8 )
    {
        numofchar(file);
    }
    else if (num== 9)
    {
        nmbroflins(file);
    }
    else if (num == 10)
    {
        findword(file);
    }
    else if (num == 11)
    {
        numword(file);
    }
    else if (num==12)
    {
        upper(file);
    }
    else if (num == 13)
    {
        lower(file);
    }
    else if(num == 14)
    {
        frstlttrc(file);
    }
    else if (num== 15)
    {
        save(file,orignal);
    }
    else if (num == 16)
    {
       en = false;
       Empty(file);
    }
    else
    {
        cout<<"\nplease enter a correct choice.\n"<<endl;
    }

    }//while
}//main
