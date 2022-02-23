#include <cctype>
#include <string>
#include <iostream>

using namespace std;
char get_rotation(char rotateMe, int rotateAmt){
    // if the combination of characters exceeds 'z'
    if((rotateMe + rotateAmt) >= 123){
        int difference = (int(rotateMe) + rotateAmt) - 122;
        rotateMe = 'a';
        rotateMe = int(rotateMe) + difference;
        return rotateMe;
    }
    // if they do not
    else
    return char(rotateMe + rotateAmt);
}

int find_rotation_ammount(char k){
//    'A' == 65
// k == 'c'

// 99 - 97 = 2
k = std::tolower(k);
return k - 'a';

}


int main(){
string key("dog");
string plainText("hello there this should be encrypted");
for(int i = 0; i < key.size(); i++){
    cout << key[i] << " shifts " << find_rotation_ammount(key[i]) << endl;
}
for(int i =0, k = 0; i < plainText.size(); i++, k++){
    if(k == key.size()) k = 0;
    if(plainText[i] == ' ') continue;
    else
    plainText[i] = get_rotation(plainText[i], find_rotation_ammount(key[k]));
}
cout << plainText << endl;
    return 0;
}