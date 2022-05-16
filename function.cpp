#include"function.h"
#include <iostream>
#include<fstream>
#include <string>
#include <cctype>
#include <regex>
using namespace std;

void entermessage()
{
    cout << "1. Add new text to the end of the file \n"
            "2. Display the content of the file\n"
            "3. Empty the file\n"
            "4. Encrypt the file content\n"
            "5. Decrypt the file content\n"
            "6. Merge another file\n"
            "7. Count the number of words in the file.\n"
            "8. Count the number of characters in the file\n"
            "9. Count the number of lines in the file\n"
            "10. Search for a word in the file\n"
            "11. Count the number of times a word exists in the file\n"
            "12. Turn the file content to upper case.\n"
            "13. Turn the file content to lower case \n"
            "14. Turn file content to 1st caps (1st char of each word is capital)\n"
            "15. Save\n"
            "16. Exit\n"
            "Please Enter your choice ==>";
}

//function to add text
void addtext(string filename)
{
    fstream add(filename,ios::app);
    cout<<"enter massege: ";
    string addToend;
    cin>>addToend;
    add<<addToend<<endl;
    add.close();
}

//fuction to show the user the content in the file
void Display(string filename)
{
    fstream read(filename,ios::in);
    string line ;
    while (getline(read,line)){
    cout<<line<<endl;
}
read.close();
}

// this function to clear all the content
void Empty(string filename)
{
    fstream cleer(filename,ios::out);
    cleer.clear();
    cleer.close();
}

// this function to cypher the file content
void Encrypt(string filename)
{
    int x , shift ;
    fstream file(filename,ios::in);
    // tring to make the file lines
    string line ;
    string cypher = "";
    while(getline(file,line))
    {
        cypher += line;
        cypher += '\n';
    }
    file.close();


    // looping each letter
       for(int i=0 ; i < cypher.length() ; i++)
       {
        if (cypher[i] == '\n' || cypher[i] == ' ')
        {
            continue;
        }
        else if(cypher[i] > 64 && cypher[i]<91){
            // subtraction from ascii
            x = cypher[i] - 65 ;
            // converting to Ciphertext
            shift = (((5 * x) + 8) % 26 ) + 65 ;
            // to chech if the converting bigger than the the ascii letters and if it so it will subtract 26
            if (shift>90)
            {
                shift = shift - 26;
                cypher[i] = shift ;
            }
            else
            {
                cypher[i] = shift ;
            }
       }//end of if upper
       else if(cypher[i] > 96 && cypher[i]<123)
        {
            // subtraction from ascii
            x = cypher[i] - 97 ;
            // converting to Ciphertext
            shift = (((5 * x) + 8) % 26 ) + 97 ;
            // to chech if the converting bigger than the the ascii letters and if it so it will subtract 26
            if (shift>122)
            {
                shift = shift - 26;
                cypher[i] = shift ;
            }
            else
            {
                cypher[i] = shift ;
            }
        }
       }//end of loop

       fstream file2(filename, ios::out);
       for(int i=0 ; i < cypher.length() ; i++)
       {
           file2<<cypher[i];
       }
       file2.close();

    cout<<"the file has been encyrpt."<<endl;
}

// this function to discypher the file content
void decrybtion(string filename)
{
   int y , shift ;
    fstream file(filename,ios::in);
    // tring to make the file lines
    string line ;
    string discypher = "";
    while(getline(file,line))
    {
        discypher += line;
        discypher += '\n';
    }
    file.close();


   for(int i2 = 0 ; i2 < discypher.length() ; i2++)
        {
            if(discypher[i2] == ' ' || discypher[i2] == '\n' )
                continue;
            else if (discypher[i2] > 64 && discypher[i2]<91)
            {
            // subtraction from ascii
            y = discypher[i2] - 65 ;
            // converting to Plaintext
            shift = 21*( y - 8) ;
            // to make the shift value positive
            while(shift < 25 )
            {
                shift = shift + 26;
            }
            shift = (shift % 26 ) + 65 ;
            discypher[i2] = shift ;
            }
            else if(discypher[i2] > 96 && discypher[i2]<123)
            {
                // subtraction from ascii
                y = discypher[i2] - 97 ;
                // converting to Plaintext
                shift = 21*( y - 8) ;
                // to make the shift value positive
                while(shift < 25 )
                {
                    shift = shift + 26;
                }
                shift = (shift % 26 ) + 97 ;
                discypher[i2] = shift ;
            }
        }//end of for loop

       fstream file2(filename, ios::out);
       for(int i=0 ; i < discypher.length() ; i++)
       {
           file2<<discypher[i];
       }
       file2.close();

    cout<<"the file has been discyphred."<<endl;
}

// to add two files together
void merg(string filename)
{
    fstream file(filename,ios::app);

    string mfile2 = inputFile();
    fstream file2(mfile2,ios::in|ios::out|ios::app);
    string line2 ;

        while (getline(file2,line2))
        {
            file<<line2<<" ";
        }

        cout<<"file merged."<<endl;
        file2.close();
        file.close();
}

// calculate the number of words
void numofwords(string filename)
{
    fstream file(filename,ios::in);
    string line ;
    int word = 0;
   file.seekg(0,ios::beg); //bring position of file pointer to begining of file

    while(getline(file,line))
        {
            for(int i = 0; i<line.length();i++)
            {
                if((line[i] == ' ' || (i+1) == line.length() ) && (line[i+1] != ' '))
                    word++;
            }
       }
        cout<<"number of words = "<<word<<endl;
        file.close();
}

// calculate the number of characters
void numofchar(string filename)
{
    fstream file(filename,ios::in);
    string line ;
    int num , sum = 0;

    while (getline(file,line))
        {
            num = line.size();
            sum += num;
        }
        cout<<"number of characters is : "<<sum<<endl;
        file.close();
}

// calculate the number of lines
void nmbroflins(string filename)
{
     fstream read(filename,ios::in);
     string line ;
     int i = 0 ;
      while (getline(read,line))
        {
            i++;
        }
        cout<<"number of lines is: "<<i<<endl;
        read.close();
}

// search for a word
void findword(string filename)
{
    //i turned the file to lower then i  turned the word that the user want to lower to make Ali = ali = ALi = ALI.
    lower(filename);//to make all the letters lower to clear the confusion if Ali = ali or not
    ifstream fin;
	fin.open(filename);
	if(fin.fail())
	{
		cout << "Input file opening failed.\n";
	}
	string search;
	cout << "Enter a word to search for: ";
	cin  >> search;
    // using transform() function and ::tolower in STL
    transform(search.begin(), search.end(), search.begin(), ::tolower);

	bool isFound=0;
	while(!fin.eof())
	{
		string temp = "";
		getline(fin,temp);
		for(int i=0;i<search.size();i++)
		{
			if(temp[i]==search[i])
				isFound = 1;
			else
			{
				isFound =0;
				break;
			}
		}

		if(isFound)
		{
			cout << "the word exist.\n"<<endl;
			break;
		}
	}

	if(fin.eof()&&(!isFound))
	{
		cout << "the word doesn't exist!\n";
	}
	 Empty(filename);
	 fin.close();
}


// how many times the word existis
void numword(string filename)
{
    //i turned the file to lower then i  turned the word that the user want to lower to make Ali = ali = ALi = ALI.
    lower(filename);//to make all the letters lower to clear the confusion if Ali = ali or not
    ifstream plate(filename);
    int count = 0;
    string search;
    cout<<"what is the word you are searching for: ";
    cin>>search;

    // using transform() function and ::tolower in STL
    transform(search.begin(), search.end(), search.begin(), ::tolower);

    string temp;
    while (plate >> temp) {
        if (temp == search) {
            ++count;
        }
    }
    cout <<"the word repeated: "<< count <<" times in the file.\n"<< endl;
    Empty(filename);
    plate.close();
}

 // turn all the content to upper
void upper(string filename)
{
    fstream file(filename,ios::in);
    string nline;
    // tring to make the file lines
    string line ;
    string line2 = "";
    while(getline(file,line))
    {
        line2 += line;
        line2 += '\n';
    }
    file.close();

    fstream fin2(filename,ios::out);
    for(int i=0 ; i < line2.length() ; i++)
       {
           if (line2[i] == '\n')
           {
               fin2<<line2[i];
           }
           else if(line2[i]>96 && line2[i] < 123){ // subtract from ascaii
			   fin2<< static_cast<char>(line2[i]-32);
		    }
           else{
                fin2<< static_cast<char>(line2[i]);
       }
       }
       fin2.close();
}

// turn all the content to lower
void lower(string filename)
{

    fstream file(filename,ios::in);
    string nline;
    // tring to make the file lines
    string line ;
    string line2 = "";
    while(getline(file,line))
    {
        line2 += line;
        line2 += '\n';
    }
    file.close();

    fstream fin2(filename,ios::out);
    for(int i=0 ; i < line2.length() ; i++)
       {
           if (line2[i] == '\n')
           {
               fin2<<line2[i];
           }
           else if(line2[i]>64 && line2[i] < 91){ //add to ascaii
			   fin2<< static_cast<char>(line2[i]+32);
		    }
           else{
                fin2<< static_cast<char>(line2[i]);
       }
       }
       fin2.close();
}


void save(string filename,string orgfile)
{
    start:
    int x;
    cout<<"Do you want to save it in the same file?\n"
          "enter 1 for yes 2 for saving in another file \n"<<endl;
    cin>>x;
    if(x==1)
    {
        //copied all the changes in the file
        fstream file1(filename,ios::in);
        fstream file2(orgfile,ios::out);
        string line;
        while(getline(file1,line))
    {
        file2<<line<<endl;
    }
    cout<<"your changes have been succesfully done."<<endl;
}
    else if (x==2)
    {
        //copied all the changes in the new file
        string userinput = check_filename();
        fstream inputFile(userinput,ios::out);
        fstream file2("minfel.txt",ios::in);
        string line;
        while(getline(file2,line))
        {
            inputFile<<line<<endl;
        }
    }
    else
    {
        cout<<"you should enter a correct choice"<<endl;
        goto start;
    }
}

//turn all the first letter to capital
void frstlttrc(string filename)
{
    //turned all the file content to lower to make it easier to me.
    lower(filename);
    fstream file(filename,ios::in);

    // copied the file content in string variable
    string line ;
    string line2 = "";
    while(getline(file,line))
    {
        line2 += line;
        line2 += '\n';
    }
    file.close();

    for(int i=0;i < line2.length() ; i++){
        if((line2[i]>96 && line2[i] < 123) && (line2[i-1] == ' ' || line2[i-1] == '\n'))
        {
			   line2[i] = line2[i]-32;
        }
        else if((line2[0]>96 && line2[0] < 123) && (line2[1]>96 && line2[1] < 123))
            line2[i] = line2[i]-32;
        else{
                static_cast<char>(line2[i]);
       }
        }

       fstream fin2(filename,ios::out);
       for (int i = 0 ; i<line2.length() ; i++)
        fin2<<line2[i];
       fin2.close();
       cout<<"done\n\n";
}
