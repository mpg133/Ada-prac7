//Miguel Pérez Giménez - 74395666G

#include <fstream>
#include <string>
#include <limits>
#include <iostream>
#include <vector>
#include <tuple>
#include <list>
#include <queue>
using namespace std ;

const unsigned int SENTINEL = numeric_limits < unsigned int>:: max();
bool NO_EXIT=true;

struct position{
    int x;
    int y;
};

bool isValid(unsigned int i, unsigned int j, unsigned int rows, unsigned int cols){
    if( (i>=0) && (j>=0) && (i<rows) && (j<cols)){
        return true;
    }
    return false;
}

unsigned int maze_greedy(unsigned int i, unsigned int j, unsigned int rows, unsigned int cols,
                        const vector<vector<int>> matriu ){



}


void show_usage(){
    cout<<"Usage:"<<endl;
    cout<<"maze_greedy [-p] -f file"<<endl;
    exit(EXIT_FAILURE);
}

int main(int argc , char *argv[] ){
    string file_name;
    bool opcio_f =false;
    bool mostrar_cami=false;
    
    // Parsing arguments-------------------------------------------------------------
    for ( int i = 1; i < argc ; i ++ ) {
        
        string arg = argv [ i ];

       if(arg=="-f"){
            opcio_f=true;
            i++;
            if(i>=argc){ //si no hay fichero 
                cerr<<"ERROR: missing filename."<<endl;
                show_usage();
            }

            file_name=argv[i];
        }else if(arg=="-p"){
            mostrar_cami=true;
        
        }else{
            cout<<"ERROR: unknown option "<<arg<<"."<<endl;
            show_usage();
        }
    }
    //processing parameters--------------------------------------------------------------
    if(opcio_f){
        ifstream file(file_name);
        if(!file){
            cerr<<"ERROR: can’t open file: "<<file_name<<"."<<endl;
            show_usage();
        }
        int rows;
        int cols;
        file >> rows >> cols; //llegim columnes i files

        //creem matriu
        vector <vector<int>> matriu (rows , vector<int>(cols) );
        
        for(int i=0; i< rows;i++)
            for(int j=0;j<cols;j++)
                file >>matriu[i][j];
        file.close();
        
        //eixida de programa-----------------------------------------------------------
        //creem matriu auxiliar per al cami
        vector <vector<int>> aux_matriu (rows , vector<int>(cols) );
       
        unsigned int resultat=maze_greedy(0,0,rows,cols,matriu);
        if(resultat>0 && !NO_EXIT){
            cout<<endl;
        }else{
            cout<<"0"<<endl;
        }
        if(mostrar_cami){


        }


        
    }else{
        show_usage();    
    }
    

   
   
}