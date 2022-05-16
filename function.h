#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED
#include <iostream>
#include<fstream>
#include <string>
#include <cctype>
#include <regex>

using namespace std;

void entermessage(); //function to display the choices
void addtext(string); //function to add text
void Display(string); //fuction to show the user the content in the file
void Empty(string);   // this function to clear all the content
void Encrypt(string);  // this function to cypher the file content
void decrybtion(string); // this function to discypher the file content
void merg(string);  // to add two files together
void numofwords(string); // calculate the number of words
void numofchar(string);  // calculate the number of characters
void nmbroflins(string);  // calculate the number of lines
void findword(string);  // search for a word
void numword(string);   // how many times the word existis
void upper(string);      // turn all the content to upper
void lower(string);       // turn all the content to lower
void frstlttrc(string);    //turn all the first letter to capital
void save(string,string);   // to save the file


// this function to check if the input the right name or not
// this function also check if the name of the file repeated or not
// and chech the validation of the file
string check_filename()
{
    ifstream inputFile1;
    start2:
        string regexpattern = "\\w+\\.txt";
        regex regexrule(regexpattern);
        cout<<"note: the file name should contain the extend like .txt \n"
              "Enter the file name: ";
        string userinput;
        cin>>userinput;
        string change = userinput.c_str();
        bool isvaild = regex_match(change,regexrule);
        if(isvaild)
        {
            inputFile1.open (userinput.c_str());
            if(inputFile1.fail())
            {
             cout<<"This is a new file. I created it for you.\n"<<endl;
             return userinput;
            }
            else
            {
              cout<<"sorry, but This File Already Exists.\n"<<endl;
              goto start2;
            }

        }
        else{
            cout<<"name is not valid.\n"<<endl;
            goto start2;
        }

}


//this function to open the file
string inputFile()
{
    ifstream inputFile1;
    string myFile;
    cout<<"what is the file name: ";
    cin >> myFile;
    inputFile1.open (myFile.c_str());
    if(inputFile1.fail())
    {
        cout<<"\nThis is a new file. I created it for you.\n"<<endl;
    }
    else
    {
        cout<<"\nThis File Already Exists\n"<<endl;
    }
    return myFile;
}

//function to copy file that the user want into another file
string file2(string file)
{
    ifstream inputFile(file,ios::in);
    fstream file2("minfel.txt",ios::out);
    string line;
    while(getline(inputFile,line))
    {
        file2<<line<<endl;
    }
    return "minfel.txt";
}


#endif // FUNCTION_H_INCLUDED
