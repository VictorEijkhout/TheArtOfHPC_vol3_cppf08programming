#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip> 
#include <fstream>

using namespace std;

vector<vector<int>> initialize_domain(int SIZE,int trash,int turtle, int ship){
    vector<vector<int>> mesh(SIZE,vector<int>(SIZE,0));
    if (trash + turtle + ship > SIZE*SIZE){
        cout << "Number of species larger than available space." << endl;
        exit(1);
    }
    while(ship>0){
        int x = rand()%SIZE;
        int y = rand()%SIZE;
        if (mesh[x][y] == 0){
            mesh[x][y] = 3;
            ship--;
        }
    }
    while(trash>0){
        int x = rand()%SIZE;
        int y = rand()%SIZE;
        if (mesh[x][y] == 0){
            mesh[x][y] = 1;
            trash--;
        }
    }
    while(turtle>0){
        int x = rand()%SIZE;
        int y = rand()%SIZE;
        if (mesh[x][y] == 0){
            mesh[x][y] = 2;
            turtle--;
        }
    }
    return mesh;
}

void print_info(vector<vector<int>> mesh,int trash,int turtle,int ship){
    int xSize = mesh.size();
    int ySize = mesh[0].size();
    int total = xSize * ySize;
    cout << "Mesh:" << endl;
    cout << setw(15) << left << "X" << right << setw(6) << xSize << endl;
    cout << setw(15) << left << "Y" << right << setw(6) << ySize << endl;
    cout << setw(15) << left << "Total Space" << right << setw(6) << total << endl;
    cout << setw(15) << left << "trash" << right << setw(6) << trash << endl;
    cout << setw(15) << left << "turtle" << right << setw(6) << turtle << endl;
    cout << setw(15) << left << "ship" << right << setw(6) << ship << endl;
    cout << setw(15) << left << "ocean" << right << setw(6) << total - trash - turtle - ship << endl;
}

void print_domain(vector<vector<int>> mesh, string fileName){
    ofstream myFile;
    myFile.open(fileName);
    int xSize = mesh.size();
    int ySize = mesh[0].size();
    for (int x = 0; x < xSize; ++x){
        for (int y = 0; y < ySize; ++y){
            myFile << mesh[x][y] << " ";
        }
        myFile << endl;
    }
    myFile.close();
}

void get_neighborhood(vector<vector<int>> mesh, int x, int y, int& empty, int& prey, int& predator){
    empty = 0;
    prey = 0;
    predator = 0;
    for (int i = x-1; i<=x+++1; i){
        for (int j = y-1; j<=y+1; ++j){
            if( (i==x && j==y) || i<0 || j<0 || i==mesh.size() || j==mesh.size()){
                continue;
            }
            if(mesh[i][j] == 0)
                ++empty;
            else if(mesh[i][j] == 1)
                ++prey;
            else
                ++predator;
        }
    }
}

void get_position(vector<vector<int>> mesh, int x, int y, int& xx, int& yy, int pos, int label){
    int empty = 0;
    for (int i = x-1; i<=x+1; ++i){
        for (int j = y-1; j<=y+1; ++j){
            if( (i==x && j==y) || i<0 || j<0 || i==mesh.size() || j==mesh.size()){
                continue;
            }
            if(mesh[i][j] == label){
                if(empty == pos){
                    xx = i;
                    yy = j;
                }
                ++empty;
            }
        }
    }
}

vector<vector<int>> update_position(vector<vector<int>> mesh, int& trash){
    int xSize = mesh.size();
    int ySize = mesh[0].size();
    int empty = 0, prey = 0, predator = 0;
    vector<vector<int>> aux(xSize,vector<int>(xSize,0));
    aux = mesh;
    // Access the mesh randomly 
    vector<int> xVector(xSize);
    for (int x = 0; x < xSize; ++x)
        xVector[x] = x;
    vector<int> yVector(ySize);
    for (int y = 0; y < ySize; ++y)
        yVector[y] = y;
    std::random_shuffle( xVector.begin(), xVector.end() );
    std::random_shuffle( yVector.begin(), yVector.end() );
    
    for (int i = 0; i < xSize; ++i){
        int x = xVector[i];
        for (int j = 0; j < ySize; ++j){
            int y = yVector[j];
            if (mesh[x][y] == 2){
                get_neighborhood(aux,x,y,empty,prey,predator);
                if(empty > 0){
                    int pos = rand()%empty;
                    int xx,yy;
                    get_position(aux,x,y,xx,yy,pos,0);
                    aux[xx][yy] = mesh[x][y];
                    aux[x][y] = 0;
                }
            }
            else if (mesh[x][y] == 3){
                get_neighborhood(aux,x,y,empty,prey,predator);
                if(prey > 0){
                    int pos = rand()%prey;
                    int xx,yy;
                    get_position(aux,x,y,xx,yy,pos,1);
                    aux[xx][yy] = mesh[x][y];
                    aux[x][y] = 0;
                    trash--;
                }
                else if(empty > 0){
                    int pos = rand()%empty;
                    int xx,yy;
                    get_position(aux,x,y,xx,yy,pos,0);
                    aux[xx][yy] = mesh[x][y];
                    aux[x][y] = 0;
                }
            }
        }
    }
    return aux;
}

vector<vector<int>> update_values(vector<vector<int>> mesh,int& trash,int& turtle,int ship){
    int xSize = mesh.size();
    int ySize = mesh[0].size();
    int empty = 0, prey = 0, predator = 0;   
    double proliferation = 0.042;
    
    vector<vector<int>> aux(xSize,vector<int>(xSize,0));
    aux = mesh;
    vector<int> xVector(xSize);
    for (int x = 0; x < xSize; ++x)
        xVector[x] = x;
    vector<int> yVector(ySize);
    for (int y = 0; y < ySize; ++y)
        yVector[y] = y;
    std::random_shuffle( xVector.begin(), xVector.end() );
    std::random_shuffle( yVector.begin(), yVector.end() );
    
    for (int i = 0; i < xSize; ++i){
        int x = xVector[i];
        for (int j = 0; j < ySize; ++j){
            int y = yVector[j];
            int occupied = trash + turtle + ship;
            if (mesh[x][y] == 2){
                double r = double(rand())/RAND_MAX;
                if(r < proliferation && occupied < xSize * ySize){
                    bool add_turtle = true;
                    while(add_turtle){
                        int place_x = rand()%xSize;
                        int place_y = rand()%ySize;
                        if (aux[place_x][place_y] == 0){
                            aux[place_x][place_y] = 2;
                            ++turtle;
                            add_turtle = false;
                        }
                    }
                }
                get_neighborhood(aux,x,y,empty,prey,predator);
                r = double(rand())/RAND_MAX;
                if(r < 0.11+0.01*prey && prey>0){
                    aux[x][y] = 0;
                    turtle--;
                }
            }
        }
    }
    int new_trash = trash * 0.025;
    int occupied = trash + turtle + ship;
    while(new_trash > 0 && occupied < xSize * ySize){
        int place_x = rand()%xSize;
        int place_y = rand()%ySize;
        if (aux[place_x][place_y] == 0){
            aux[place_x][place_y] = 1;
            ++trash;
            ++occupied;
            new_trash--;
        }
    }
    return aux;
}

int main (){
    //srand(time(NULL));
    const int SIZE = 40; //domain size 40x40
    int trash = 366, turtle = 29, ship = 28; // counter for the species
    
    // Base name
    string baseName = "outputData_";
    string fileName;
    
    //File to save the temporal dynamics
    ofstream temporal;
    temporal.open("dynamics.txt");
    
    //function that returns a 2D array with the initial positions
    vector<vector<int>> mesh = initialize_domain(SIZE, trash, turtle, ship);
    
    //Printing the initial condition to the screen
    print_info(mesh,trash,turtle,ship);
    
    //Printing the initial number of trash and turtle to the file dynamics.txt
    temporal << 0 << " " << trash << " " << turtle << endl;
    
    //Defining the file name
    // baseName + converting a number to string + adding the file format .txt
    std::ostringstream ss;
    ss << std::setw(5) << std::setfill('0') << 0;
    fileName = baseName + ss.str() + ".txt";
    ss.str("");ss.clear();
    
    //Function that receives the 2D vactor and the name of the file to save the data
    print_domain(mesh,fileName);

    //looping how many steps I want
    for(int t = 0; t < 200; ++t){
        cout << "Time: " << t+1 << endl; //Printing the time to the screen
        //Updating the values of the animals following the defined rules
        mesh = update_values(mesh,trash,turtle,ship); 
        
        //Updating their positions
        mesh = update_position(mesh,trash);
               
        //Updating the name of the file so I have a different file to each iterations
        if ((t+1)%1 == 0){
            ss << std::setw(5) << std::setfill('0') << t+1;
            fileName = baseName + ss.str() + ".txt";
            ss.str("");ss.clear();
            cout << fileName << endl;
            print_domain(mesh,fileName); //Saving the data to the new file
        }
        
        //Printing the initial number of trash and turtle to the file dynamics.txt
        temporal << t+1 << " " << trash << " " << turtle << endl;
    }

    //Printing to the screen the final number of trash and turtle
    print_info(mesh,trash,turtle,ship);
    
    //Closing the file dynamics.txt
    temporal.close();
    return 0;
}
