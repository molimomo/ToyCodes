#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(const string &s, char delim) {
  vector<string> elems;
  stringstream ss(s);
  string item;
  while (getline(ss, item, delim)) {
    elems.push_back(item);
  }
  return elems;
}

string join(const vector<string>& input) {
  string output = "";
  bool has_data = false;
  for (unsigned int i = 0; i < input.size(); ++i) {
    has_data = true;
    output += input[i];
    output += ", ";
  }
  if (has_data) {
    output = output.substr(0, output.length() - 2);
  }
  return output;
}

class FileSystem {
 public:
  vector<string> Ls(const string& path) {
    // IMPLEMENT ME
    if(path=="/")
        return myRec[path];

    // fetch tokens
    vector<string> output;
    string tmp = path;
    string delimiter = "/";
    size_t pos = 0;
    string token="";
    string prev="/";
    while((pos=tmp.find(delimiter))!=string::npos){
        token = tmp.substr(0,pos);
        tmp.erase(0,pos+delimiter.length());
        if(token!=""){
            myRec[prev].push_back(token);
            prev = token;
        }
    }
    // Generate output string
    for(auto it=myRec[tmp].begin();it!=myRec[tmp].end();it++){
        if(*it!="")
            output.push_back(*it);
    }
    return output;
  }

  void MkdirP(const string& dir_path) {
    // IMPLEMENT ME
    
    // fetch tokens
    string tmp = dir_path;
    string delimiter = "/";
    size_t pos = 0;
    string token;
    string prev="/";
    while((pos=tmp.find(delimiter))!=string::npos){
        token = tmp.substr(0,pos);
        tmp.erase(0,pos+delimiter.length());
        if(token!=""){
            myRec[prev].push_back(token);
            prev = token;
        }
    }
    myRec[prev].push_back(tmp);
    myRec[tmp].push_back("");
    outputRec();
  }

  void AddFileWithContent(const string& file_path, const string& content) {
    // IMPLEMENT ME

    // fetch tokens
    string tmp = file_path;
    string delimiter = "/";
    size_t pos = 0;
    string token;
    string prev="";
    while((pos=tmp.find(delimiter))!=string::npos){
        token = tmp.substr(0,pos);
        tmp.erase(0,pos+delimiter.length());
        if(token!="" && myRec.find(token)==myRec.end()){
            cout<<"New: "<<token<<endl;
            
        }
    }
    auto it = myRec.end();
    it--;
    if(myRec.find(tmp)==myRec.end()){
        (*it).second.push_back(tmp);
    }
    myRec[tmp].push_back(content);
  }

  string GetFileContent(const string& file_path) {
    // IMPLEMENT ME
    string tmp = file_path;
    string delimiter = "/";
    string output = "";
    size_t pos = 0;
    string token;
    string prev="";
    while((pos=tmp.find(delimiter))!=string::npos){
        token = tmp.substr(0,pos);
        tmp.erase(0,pos+delimiter.length());
    }
    if(myRec.find(tmp)!=myRec.end())
        output = *(myRec[tmp].begin());
    return output;
  }
  
    // key: current directory/file
    // value: sub-directories of files
    map<string, vector<string> > myRec; 
   
    void outputRec(){
        cout<<"Check"<<endl;
        for(auto it = myRec.begin();it!=myRec.end();it++){
            cout<<(*it).first<<": ";
            vector<string> sub = (*it).second;
            for(auto i = sub.begin();i!=sub.end();i++){
                cout<<*i<<", "<<endl;
            }
        }
    }
 
};


#ifndef __main__
#define __main__

int main(int argc, char* argv[]) {
  FileSystem fs;

  // should print ""
  cout << join(fs.Ls("/")) << endl;
  fs.MkdirP("/a/b/c");
  fs.MkdirP("/a/b/e");
  fs.AddFileWithContent("/a/b/c/d", "hello world");
  // should print a
  cout << join(fs.Ls("/")) << endl;
  // should print c,e
  cout << join(fs.Ls("/a/b")) << endl;
  // should print d
  cout << join(fs.Ls("/a/b/c")) << endl;
  // should print d
  cout << join(fs.Ls("/a/b/c/d")) << endl;
  // should print hello world
  cout << fs.GetFileContent("/a/b/c/d");
    cout<<endl;
}

#endif


