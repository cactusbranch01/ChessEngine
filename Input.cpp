//
// Created by user on 2023-02-03.
//
#include <bits/stdc++.h>
#pragma warning(disable :4996)
#include "Input.h"
#include <string>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

Input:: Input(string file_name){

   ifstream ifs;
   ifs.open(file_name);
   cout<<file_name<<endl;

   string line;
   int count =0;
   int occur = 1;
   while(!ifs.eof())
   {
       getline(ifs, line);


       if(line[0]=='['){

           if(occur==2||occur==3||occur==8)
           {
               cout<< line<< endl;
           }

           occur ++;
       }


       if(line[0]=='1'&& count==0){

           //cout<< line<< endl;
           line = line.substr(line.find(".")+1);
           while(line.find(".")!=-1){

               string target1= line.substr(1, line.find("{")-2);
               line = line.substr(line.find("}"));
               string target2= line.substr(3, line.find("{")-4);
               line = line.substr(line.find(".")+1);
               cout<<target1<<target2<<endl;
               convert(target1);
               convert(target2);

           }
           //cout<< line<< endl;


           occur=1;
           count++;
       }


   }
}

int Input:: convert(string target){

    if(target[0]>'Z'){
        int col = target[0]-'a';
        int row= target[1]-'1';
        cout<< col<< row<< endl;
    }
}
