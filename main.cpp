#include <iostream>
#include <algorithm>

using namespace std;

//CaesarCipher
string codeCaesarCipher(string code, int increment)
{
    string decoded;
    for(char& c: code)
        decoded += c+increment;

    return decoded;
}

void bruteForceCaesarCipher(string code)
{
    for(int i = -25; i < 25; i++)
        cout << codeCaesarCipher(code, -i) << endl;
}



//Morse Code
string encodeMorseCode(string code)
{
    std::transform(code.begin(), code.end(), code.begin(), [](unsigned char c){ return std::tolower(c); });
    string encoded;
    for(char &c: code) {
        if(c!=' ') {
            if(c=='a') encoded+=".-";
            else if(c=='b') encoded+="-...";
            else if(c=='c') encoded+="-.-.";
            else if(c=='d') encoded+="-..";
            else if(c=='e') encoded+=".";
            else if(c=='f') encoded+="..-.";
            else if(c=='g') encoded+="--.";
            else if(c=='h') encoded+="....";
            else if(c=='i') encoded+="..";
            else if(c=='j') encoded+=".---";
            else if(c=='k') encoded+="-.-";
            else if(c=='l') encoded+=".-..";
            else if(c=='m') encoded+="--";
            else if(c=='n') encoded+="-.";
            else if(c=='o') encoded+="---";
            else if(c=='p') encoded+=".--.";
            else if(c=='q') encoded+="--.-";
            else if(c=='r') encoded+=".-.";
            else if(c=='s') encoded+="...";
            else if(c=='t') encoded+="-";
            else if(c=='u') encoded+="..-";
            else if(c=='v') encoded+="...-";
            else if(c=='w') encoded+=".--";
            else if(c=='x') encoded+="-..-";
            else if(c=='y') encoded+="-.--";
            else if(c=='z') encoded+="--..";
            else if(c=='1') encoded+=".----";
            else if(c=='2') encoded+="..---";
            else if(c=='3') encoded+="...--";
            else if(c=='4') encoded+="....-";
            else if(c=='5') encoded+=".....";
            else if(c=='6') encoded+="-....";
            else if(c=='7') encoded+="--...";
            else if(c=='8') encoded+="---..";
            else if(c=='9') encoded+="----.";
            else if(c=='0') encoded+="-----";
            encoded+=" ";
        }
    }
    return encoded;
}

string decodeMorseCode(string code)
{
    string decoded;
    size_t charPos = 0;
    while(code.length()) {
        string word;
        if((charPos = code.find(' ')) != string::npos) {
            word = code.substr(0, charPos);
            code.erase(0, charPos + 1);
        }
        else {
            word = code;
            code = "";
        }
        if(word==".-") decoded+='a';
        else if(word=="-...") decoded+='b';
        else if(word=="-.-.") decoded+='c';
        else if(word=="-..") decoded+='d';
        else if(word==".") decoded+='e';
        else if(word=="..-.") decoded+='f';
        else if(word=="--.") decoded+='g';
        else if(word=="....") decoded+='h';
        else if(word=="..") decoded+='i';
        else if(word==".---") decoded+='j';
        else if(word=="-.-") decoded+='k';
        else if(word==".-..") decoded+='l';
        else if(word=="--") decoded+='m';
        else if(word=="-.") decoded+='n';
        else if(word=="---") decoded+='o';
        else if(word==".--.") decoded+='p';
        else if(word=="--.-") decoded+='q';
        else if(word==".-.") decoded+='r';
        else if(word=="...") decoded+='s';
        else if(word=="-") decoded+='t';
        else if(word=="..-") decoded+='u';
        else if(word=="...-") decoded+='v';
        else if(word==".--") decoded+='w';
        else if(word=="-..-") decoded+='x';
        else if(word=="-.--") decoded+='y';
        else if(word=="--..") decoded+='z';
        else if(word==".----") decoded+='1';
        else if(word=="..---") decoded+='2';
        else if(word=="...--") decoded+='3';
        else if(word=="....-") decoded+='4';
        else if(word==".....") decoded+='5';
        else if(word=="-....") decoded+='6';
        else if(word=="--...") decoded+='7';
        else if(word=="---..") decoded+='8';
        else if(word=="----.") decoded+='9';
        else if(word=="-----") decoded+='0';
    }
    return decoded;
}



//Pig Latin
bool isVowel(char c)
{
    if((c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u')) return true;
    else return false;
}

string encodeBasicPigLatin(string code)
{
    string strShift = code.substr(0,1);
    strShift.append("ay");
    code.erase(0,1);
    return code.append(strShift);
}

string decodeBasicPigLatin(string code)
{
    code.pop_back();
    code.pop_back();
    char charShift = code.back();
    code.pop_back();
    return charShift+code;
}

string encodePigLatin(string code)
{
    if(isVowel(code[0])) {
        return code.append("ay");
    }
    else {
        for(char& c: code) {
            if(isVowel(c)) {
                string strShift = code.substr(0, code.find(c));
                strShift.append("ay");
                code.erase(0,code.find(c));
                return code.append(strShift);
            }
        }
    }
    return code;
}

string decodePigLatin(string code)
{
    return "";
}

string decodePigLatinSentence(string code, bool isBasic)
{
    std::transform(code.begin(), code.end(), code.begin(), [](unsigned char c){ return std::tolower(c); });
    string decoded = "";
    size_t charPos = 0;
    while((charPos = code.find(" ")) != string::npos) {
        string word = code.substr(0, charPos);
        if(isBasic) decoded+=decodeBasicPigLatin(word)+" ";
        else decoded+=decodePigLatin(word)+" ";

        code.erase(0, charPos + 1);
    }
    decoded+=decodePigLatin(code);
    return decoded;
}

string encodePigLatinSentence(string code, bool isBasic)
{
    std::transform(code.begin(), code.end(), code.begin(), [](unsigned char c){ return std::tolower(c); });
    string encoded;
    size_t charPos = 0;
    while((charPos = code.find(" ")) != string::npos) {
        string word = code.substr(0, charPos);
        if(isBasic) encoded+=encodeBasicPigLatin(word)+" ";
        else encoded+=encodePigLatin(word)+" ";
        code.erase(0, charPos + 1);
    }
    encoded+=encodePigLatin(code);
    return encoded;
}



//Base 64
void encodeBase64()
{

}

void decodeBase64()
{

}

int main()
{
    cout << "---CAESAR CIPHER---" << endl;
    cout << "Encode Caesar Cipher   " << codeCaesarCipher("Hello World", 1) << endl;
    cout << "Decode Caesar Cipher   " << codeCaesarCipher("Ifmmp!Xpsme", -1) << endl;
    cout << "Brute Force Decode Caesar Cipher:  " << endl;
    bruteForceCaesarCipher("vxemhfwrusdwlhqwlvwrzdwfkylghrdplqlpxpri33fbfohvirupdalpxpvxjjhvwlyhhiihfwv");
    cout << "---MORSE CODE---" << endl;
    cout << "Decoding      " << decodeMorseCode("-- --- .-. ... . -.-. --- -.. .") << endl;
    cout << "Encoding Morse Code Words      " << encodeMorseCode("morse code") << endl;
    cout << "Encoding More Code Numbers      " << encodeMorseCode("1 2 3 4 5 6 7 8 9 0") << endl;

    cout << "---PIG LATIN---" << endl;
    cout << "Encode Basic Pig Latin  " << encodePigLatinSentence("The pig tried to learn latin but gave up and ate an omelet instead",true) << endl;
    cout << "Decode Basic Pig Latin  " << decodePigLatinSentence("hetay igpay riedtay otay earnlay atinlay utbay avegay puay ndaay teaay naay meletoay insteaday",true) << endl;
    cout << "Encode Advance Pig Latin  " << encodePigLatinSentence("The pig tried to learn latin but gave up and ate an omelet instead",false) << endl;

    return 0;
}
