#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include <cstdio>

using namespace std;
// function to delete space
string remove_spaces(string input){
  input.erase(remove(input.begin(),input.end(),' '),input.end());
  return input;
}
// function to convert str 2 int
int str2int(string str){
    int sum = 0, i = 0;
    while (str[i] !='\0'){
        if (str[i]<48 || str[i]>57)
            return -1;
        else {
            sum = sum * 10 + (str[i] - 48);
            i++;
        }
    }
    return sum;
}



//salam
//kos kesh khodet nafahmi

class Game {
	string name , genre;
	int year , repeat , point;
	
	public:
	Game(){};
	Game(string n,int y,string g,int p,int r):name(n),year(y),genre(g),point(p),repeat(r){};
	string get_name(){return name;}
	string get_genre(){return genre;}
	int get_year(){return year;}
	int get_repeat(){return repeat;}
	int get_point(){return point;}
	void print_game(){cout<<name<<" "<<year<<" "<<genre<<" "<<point<<" "<<repeat<<endl;};

	
};

class Games{
	public:
	vector<Game> gameNodes;
//	vector<Game> sort_rank_game(vector<Game> Games){}
//	Game sort_newer_game(vector<Game> Games){}
//	Game sort_rate_game(vector<Game> Games){}
	Games& operator=(const Games& G){
		gameNodes = G.gameNodes;
		return *this;
	}
	

};

//----- end class -----\\



vector<string> read_program() {
    vector<string> lines;
    ifstream input("game.info");

    string line;
    while (getline(input, line)){
		 line = remove_spaces(line);
        lines.push_back(line);
	}
    input.close();
    return lines;
}


vector<Game> parse_program(vector<string> lines) {
	
	vector<Game> TGames;
	string name , genre;
	int year , repeat ,point;
	
	int counter=1;
	for (int i = 0; i < lines.size(); i++) {
		int start =0 , end = 0;
		for (int j=0; j<lines[i].length() ; j++) {
			//create functio for virgool extractor....
			if(lines[i][j] == ','){
				counter++;
				
				end=j;
				switch (counter) {
					case 1: name=lines[i].substr(start , end-start);            break;
					case 2: year=str2int(lines[i].substr(start , end-start));   break;
					case 3: genre=lines[i].substr(start , end-start);           break;
					case 4: point=str2int(lines[i].substr(start , end-start));  break;
				}
				start=end+1;
			}
			
		}
		end=lines[i].length();
		repeat= str2int(lines[i].substr(start , end-start));
		//construct the temp game and pushback:
		cout<<name<<" "<<year<<" "<<genre<<" "<<point<<" "<<repeat<<endl;
		Game tempGame(name,year,genre,point,repeat);
		TGames.push_back(tempGame);
	}
	
	return TGames;
}

Games parse_input(){
	vector<Game> myGames;
	vector<string> lines;
	//read file
	lines = read_program();
	//process file
	myGames = parse_program(lines);
	cout<<myGames.size();
//	myGames[1].print_game();
	//return games obj
	Games tempGames;
	tempGames.gameNodes = myGames;
	return tempGames;
}







int main(int argc, char *argv[]) {
	Games myGames;
	myGames = parse_input();
//	cout << myGames.gameNodes[0].get_name();
	
	
}