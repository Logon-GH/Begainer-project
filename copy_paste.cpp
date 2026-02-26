#include<iostream>
#include<fstream>
#include<filesystem>
#include<string>
using namespace std;

void Directory_Create(const string &path);
std::string Write_code();

int main(){

    string path;
    cout << "Enter the path: \n";
    getline(cin, path);
    Directory_Create(path);

    int file_count = 1;
    string code;
    string filename;

    while(true){

        cout << "\n";
        cout << "enter the code: \n\n";
        code = Write_code();
        // checks if code return empty
        if(code.empty()){
            return 0;
        }
        //create the file or the path where the code will be
        filename = path + "/Codeforces" + to_string(file_count) + ".cpp";
        //create ofstream for filename
        ofstream outfile(filename);

        if(!outfile){
            cout << "Did not create the file";
            break;
        }
        // write the contain to filename
        outfile << code;
        outfile.close();
        file_count++;
        cout << "SAVED: " << filename;
    }

    return 0;
}
void Directory_Create(const string &path){

    if(!filesystem::exists(path)){ 
        //checks if directory exist
        cout << "Does not exist\n";
        cout <<"Would you like to create new one(y or n): ";
        char create_file;
        cin >> create_file;
        if(create_file == 'y'){
            filesystem::create_directories(path); 
            //create the directory if does not exist
            if(!filesystem::exists(path)){ 
                cout << "Failed to create the directories\n";
            }
            
            cout << "Directory created in " << path;
        }
    }
}
std::string Write_code(){

    string line;
    string code;
    while(true){
        getline(cin , line);
        // condition for stopping loop
        if(line == "EXIT"){
            return code;
        }
        else if(line == "SAVE"){
            break;
        }

        code += line + "\n";
    }
    return code;

}
