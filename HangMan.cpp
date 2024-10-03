#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

vector<string> loadWordsFromFile(string& filename){
    vector<string> words;
    ifstream file(filename);

    if(!file){
        cerr << "Error opening file: " << filename << endl;
        return words;
    }

    string word;
    while(getline(file,word)){
        words.push_back(word);
    }

    file.close();
    return words;

};

string getRandomWord(vector<string>& words){
    srand(time(0));         // for randomness
    int randomIndex = rand() % words.size();
    return words[randomIndex];

}
void displayWord(string& word, vector<bool>& guessed){

    for(int i = 0; i < word.length();i++){
        if(guessed[i]){
            cout << word[i] << " ";
        } else {
            cout << "_ ";
        }
    }
    cout << endl;

};

bool isGuessed(vector<bool>& guessed){

    for(bool b : guessed) {
        if(!b) 
            return false;
    }
    return true;

};


void playHangMan(){
    string filename = "words.txt";
    vector<string> words = loadWordsFromFile(filename);
    string s_word = getRandomWord(words);
    vector<bool> guessed(s_word.length(), false);
    
    // cout << s_word << endl;         //for debugging purposes 

    int max_guesses = 6;
    int wrong_guesses = 0;

    while(wrong_guesses < max_guesses){
        bool a = isGuessed(guessed);
        if( a  == true){
            cout << "you win!" << endl;
            break;
        }
        else if( a  == false){
            
            char a1;        //alhabet one
            bool check = false;
            cout << "Enter an Alphabet" << endl;
            cin >> a1;
            for(int i = 0; i < s_word.length(); i++){
                if(a1 == s_word[i] ){
                    // show alphabet at the indices
                    guessed[i] = true;
                    check = true;
                    displayWord(s_word,guessed);
                }
                
            }
            if(check == false){
                wrong_guesses = wrong_guesses + 1;
                cout << "Wrong guess!" << endl;
                cout << max_guesses - wrong_guesses << " chances left" << endl;
                displayWord(s_word,guessed);
            }


        }
    }
    if(wrong_guesses == max_guesses){
        cout << "You Lost!" << endl;
    }
    


};

int main(){

    cout << "Welcome to HangMan !" << endl;
    cout << "Press 1 to see the rules " << endl << "Press 2 to play the game" << endl << "Press 3 to Quit" << endl;
    int s1;                 //s1 is used for switch 1 
    
    do{
        cin >> s1;
        switch(s1){
            case 1:
                cout << "The object of hangman is to guess the secret word before the run out of guesses (YOU ONLY GET 6). You select letters to narrow the word down" << endl;
                cout << "Press 1 to see the rules " << endl << "Press 2 to play the game" << endl << "Press 3 to Quit" << endl;
                break;
            
            case 2:
                playHangMan();
                cout << endl << "Press 1 to see the rules " << endl << "Press 2 to play the game" << endl << "Press 3 to Quit" << endl;
                break;
            case 3:
                cout << "See you soon!" << endl << "Press CTRL + C" << endl;
                break;
            default:
                cout << "Please enter vaid options" << endl;
                break;
        }
    }while(s1 != 3);
    
    
   
   return 0;
}


